TARGET := kmodule
KERNEL_SRC := /lib/modules/$(shell uname -r)/build

BASE_DIR := $(PWD)

K_FLAGS := kflags

A_OBJ := abi++.a
O_OBJ := osapi.a
S_OBJ := stl.a
X_OBJ := test.a

E_OBJS := $(A_OBJ) $(O_OBJ) $(S_OBJ) $(X_OBJ)

M_DIR := $(BASE_DIR)/module/
A_DIR := $(BASE_DIR)/cppabi/
O_DIR := $(BASE_DIR)/osapi/
S_DIR := $(BASE_DIR)/stl/
X_DIR := $(BASE_DIR)/test/
F_DIR := $(BASE_DIR)/scripts/
B_DIR := $(BASE_DIR)/build/

include $(B_DIR)/$(K_FLAGS)

E_CFLAGS := $(K_CFLAGS) 
E_CFLAGS += -fno-nonansi-builtins 
E_CFLAGS += -fno-threadsafe-statics 
E_CFLAGS += -fno-use-cxa-atexit 
E_CFLAGS += -fno-use-cxa-get-exception-ptr 
E_CFLAGS += -fno-builtin 
E_CFLAGS += -fno-exceptions 
E_CFLAGS += -fno-rtti


all: $(TARGET)
	echo "Build has been finished!"

clean:
	make -C $(F_DIR) clean
	make -C $(M_DIR) clean
	rm -rf $(B_DIR)/*
	echo "It has been cleaned!"

$(TARGET): $(B_DIR)/$(K_FLAGS) $(addprefix $(B_DIR)/,$(E_OBJS))
	make -C $(M_DIR) TARGET=$(TARGET) E_OBJS="$(E_OBJS)"

$(B_DIR)/$(A_OBJ):
	make -C $(A_DIR) OUTPUT=$@ E_CFLAGS="$(E_CFLAGS)"

$(B_DIR)/$(O_OBJ):
	make -C $(O_DIR) OUTPUT=$@ E_CFLAGS="$(E_CFLAGS)"

$(B_DIR)/$(S_OBJ):
	make -C $(S_DIR) OUTPUT=$@

$(B_DIR)/$(X_OBJ):
	make -C $(X_DIR) OUTPUT=$@ E_CFLAGS="$(E_CFLAGS)"

$(B_DIR)/$(K_FLAGS):
	make -C $(F_DIR) OUTPUT=$@


.PHONY: module clean
