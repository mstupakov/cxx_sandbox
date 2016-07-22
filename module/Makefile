TARGET := kmodule
KERNEL_SRC := /lib/modules/$(shell uname -r)/build

obj-m += $(TARGET).o

LDFLAGS := --whole-archive
$(TARGET)-objs := module.o
$(TARGET)-objs += $(addprefix ../build/,$(E_OBJS))

module:
	$(MAKE) -C $(KERNEL_SRC) M=$(CURDIR) modules

clean:
	$(MAKE) -C $(KERNEL_SRC) M=$(CURDIR) clean
