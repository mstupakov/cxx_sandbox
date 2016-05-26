TARGET := dummy_module
obj-m += $(TARGET).o

export _CC := $(CC)
CC := $(M)/get_flags

module: clean
	make -C /lib/modules/$(shell uname -r)/build M=$(CURDIR) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(CURDIR) clean
