KERNEL_SRC := /lib/modules/$(shell uname -r)/build

D_TARGET := dummy_module
obj-m += $(D_TARGET).o

export _CC := $(CC)
CC := $(M)/get_flags

module: clean
	$(MAKE) -C $(KERNEL_SRC) M=$(CURDIR) modules

clean:
	$(MAKE) -C $(KERNEL_SRC) M=$(CURDIR) clean
