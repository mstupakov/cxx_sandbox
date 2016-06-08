TARGET := kmodule
KERNEL_SRC := /lib/modules/$(shell uname -r)/build

BASE_DIR := $(PWD)

K_FLAGS := kflags.mk

A_OBJ := abi++.a
O_OBJ := std.a
S_OBJ := stl.a
X_OBJ := test.a

I_OBJS := $(A_OBJ) $(O_OBJ) $(S_OBJ) $(X_OBJ)
E_OBJS := kernel_objs.o

M_DIR := $(BASE_DIR)/module/
A_DIR := $(BASE_DIR)/cxxabi/
O_DIR := $(BASE_DIR)/std/
S_DIR := $(BASE_DIR)/stl/
X_DIR := $(BASE_DIR)/test/
F_DIR := $(BASE_DIR)/kflags/
K_DIR := $(BASE_DIR)/scripts/
B_DIR := $(BASE_DIR)/build/

-include $(B_DIR)/$(K_FLAGS)

E_CFLAGS := $(K_CFLAGS) 
E_CFLAGS += -fno-nonansi-builtins 
E_CFLAGS += -fno-threadsafe-statics 
E_CFLAGS += -fno-use-cxa-atexit 
E_CFLAGS += -fno-use-cxa-get-exception-ptr 
E_CFLAGS += -fno-builtin 
E_CFLAGS += -fno-exceptions 
E_CFLAGS += -fno-rtti
E_CFLAGS += -fno-stack-protector
E_CFLAGS += -fno-fast-math 
E_CFLAGS += -msoft-float 
E_CFLAGS += -mtune=generic 
E_CFLAGS += -O3 -nostdinc++ 
E_CFLAGS += -D__NO_INLINE__ -D__KERNEL__ -DMODULE

LNX_INCS := $(K_LXINCLUDE)
USR_INCS := $(K_NOSTDINC)
STD_INCS := 
STL_INCS := -I$(S_DIR)/include/ -I$(S_DIR)/include/ustl/


all: $(TARGET)
	echo "Build has been finished!"

clean:
	make -C $(M_DIR) clean
	make -C $(A_DIR) clean
	make -C $(O_DIR) clean
	make -C $(S_DIR) clean
	make -C $(X_DIR) clean
	make -C $(F_DIR) clean
	rm -rf $(B_DIR)/*
	echo "It has been cleaned!"

insmod: $(TARGET)
	sudo insmod $(M_DIR)/$(TARGET).ko

rmmod:
	sudo rmmod $(TARGET)

$(TARGET): $(B_DIR)/$(K_FLAGS) $(addprefix $(B_DIR)/,$(E_OBJS))
	make -C $(M_DIR) TARGET=$(TARGET) E_OBJS="$(E_OBJS)"

$(B_DIR)/$(A_OBJ):
	make -C $(A_DIR) OUTPUT=$@ E_CFLAGS="$(E_CFLAGS)"

$(B_DIR)/$(O_OBJ):
	make -C $(O_DIR) OUTPUT=$@ E_CFLAGS="$(E_CFLAGS) $(LNX_INCS)"

$(B_DIR)/$(S_OBJ):
	make -C $(S_DIR) OUTPUT=$@ E_CFLAGS="$(E_CFLAGS)"

$(B_DIR)/$(X_OBJ):
	make -C $(X_DIR) OUTPUT=$@ E_CFLAGS="$(E_CFLAGS) $(STL_INCS)"

$(B_DIR)/$(E_OBJS): $(addprefix $(B_DIR)/,$(I_OBJS))
	$(CROSS_COMPILE)$(LD) --whole-archive -Ur -T$(K_DIR)/ld_script.lds $^ -o $@ 

$(B_DIR)/$(K_FLAGS):
	make -C $(F_DIR) OUTPUT=$@


.PHONY: module clean insmod rmmod
