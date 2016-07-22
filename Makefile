export LD    = $(CROSS_COMPILE)ld
export CC    = $(CROSS_COMPILE)gcc
export AR    = $(CROSS_COMPILE)ar
export STRIP = $(CROSS_COMPILE)strip

TARGET := kmodule
KERNEL_SRC := /lib/modules/$(shell uname -r)/build

BASE_DIR := $(CURDIR)

K_FLAGS := kflags.mk

A_OBJ := abi++.a
O_OBJ := std.a
S_OBJ := stl.a
W_OBJ := wrp.a
Z_OBJ := ext.a
X_OBJ := payload.a

I_OBJS := $(A_OBJ) $(O_OBJ) $(S_OBJ) $(W_OBJ) $(Z_OBJ) $(X_OBJ)
E_OBJS := kernel_objs.o

M_DIR := $(BASE_DIR)/module/
A_DIR := $(BASE_DIR)/cxxabi/
O_DIR := $(BASE_DIR)/std/
S_DIR := $(BASE_DIR)/stl/
X_DIR := $(BASE_DIR)/payload/
F_DIR := $(BASE_DIR)/kflags/
K_DIR := $(BASE_DIR)/scripts/
W_DIR := $(BASE_DIR)/wrappers/
Z_DIR := $(BASE_DIR)/extensions/
B_DIR := $(BASE_DIR)/build/

ifneq ($(PAYLOAD),)
X_DIR := $(PAYLOAD)
endif

ifneq ($(EXTENSIONS),)
Z_DIR := $(EXTENSIONS)
endif

-include $(B_DIR)/$(K_FLAGS)

E_CFLAGS := $(K_CFLAGS) 
E_CFLAGS += -fno-nonansi-builtins 
E_CFLAGS += -fno-threadsafe-statics 
E_CFLAGS += -fuse-cxa-atexit 
E_CFLAGS += -fno-builtin 
E_CFLAGS += -fno-exceptions 
E_CFLAGS += -fno-rtti
E_CFLAGS += -fno-stack-protector
E_CFLAGS += -fno-fast-math 
E_CFLAGS += -msoft-float 
E_CFLAGS += -Wno-undef
E_CFLAGS += -O3 -nostdinc++
E_CFLAGS += -D_FORTIFY_SOURCE=0
E_CFLAGS += -D__NO_INLINE__ -D__KERNEL__ -DMODULE -Ddouble=int -Dfloat=int

LNX_INCS := $(K_LXINCLUDE)
USR_INCS := $(K_NOSTDINC)
WRP_INCS := -I$(W_DIR)/include/
STD_INCS := -I$(O_DIR)/include/
STL_INCS := -I$(S_DIR)/include/
EXT_INCS := -I$(Z_DIR)/include/

all: $(TARGET)
	echo "Build has been finished!"

clean:
	make -C $(M_DIR) clean
	make -C $(A_DIR) clean
	make -C $(O_DIR) clean
	make -C $(S_DIR) clean
	make -C $(W_DIR) clean
	make -C $(X_DIR) clean
	make -C $(F_DIR) clean
	make -C $(Z_DIR) clean
	rm -rf $(B_DIR)/*
	echo "It has been cleaned!"

insmod: $(TARGET)
	sudo insmod $(M_DIR)/$(TARGET).ko

rmmod:
	sudo rmmod $(TARGET)

$(TARGET): $(B_DIR)/$(K_FLAGS) $(addprefix $(B_DIR)/,$(E_OBJS))
	$(MAKE) -C $(M_DIR) TARGET=$(TARGET) E_OBJS="$(E_OBJS)"

$(B_DIR)/$(A_OBJ): # ABI
	$(MAKE) -C $(A_DIR) OUTPUT=$@ E_CFLAGS="$(STD_INCS) $(E_CFLAGS)"

$(B_DIR)/$(O_OBJ): # STD
	$(MAKE) -C $(O_DIR) OUTPUT=$@ E_CFLAGS="$(STD_INCS) $(E_CFLAGS)" K_CFLAGS="$(WRP_INCS)"

$(B_DIR)/$(S_OBJ): # STL
	$(MAKE) -C $(S_DIR) OUTPUT=$@ E_CFLAGS="$(STD_INCS) $(E_CFLAGS)" K_CFLAGS="$(WRP_INCS)"

$(B_DIR)/$(W_OBJ): # WRP
	$(MAKE) -C $(W_DIR) OUTPUT=$@ E_CFLAGS="$(STD_INCS) $(E_CFLAGS)" K_CFLAGS="$(LNX_INCS) $(WRP_INCS)"

$(B_DIR)/$(Z_OBJ): force_look # EXT
	$(MAKE) -C $(Z_DIR) OUTPUT=$@ E_OBJS="$(E_OBJS)" E_CFLAGS="$(STD_INCS) $(E_CFLAGS) $(STL_INCS)" K_CFLAGS="$(LNX_INCS) $(WRP_INCS)"

$(B_DIR)/$(X_OBJ): force_look # PAYLOAD
	$(MAKE) -C $(X_DIR) OUTPUT=$@ E_OBJS="$(E_OBJS)" E_CFLAGS="$(STD_INCS) $(E_CFLAGS) $(STL_INCS) $(EXT_INCS)" K_CFLAGS="$(LNX_INCS) $(WRP_INCS) $(EXT_INCS)"

$(B_DIR)/$(E_OBJS): $(addprefix $(B_DIR)/,$(I_OBJS))
	$(LD) --whole-archive -Ur -T$(K_DIR)/ld_script.lds $^ -o $@ 

$(B_DIR)/$(K_FLAGS):
	$(MAKE) -C $(F_DIR) OUTPUT=$@

force_look :
	@true

.PHONY: module clean insmod rmmod
