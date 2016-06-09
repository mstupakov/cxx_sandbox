OUTPUT := stl.a

BASE_DIR := $(CURDIR)
INCS_DIR := -I$(BASE_DIR)/include/ustl/

C_SRCS := $(wildcard *.c)
CPP_SRCS := $(wildcard *.cc)

SRCS := $(C_SRCS) $(CPP_SRCS)
OBJS := $(C_SRCS:%.c=%.o) $(CPP_SRCS:%.cc=%.o)

%.o: %.c
	$(CROSS_COMPILE)$(CC) $(C_FLAGS) $(E_CFLAGS) -c $<

%.o: %.cc
	$(CROSS_COMPILE)$(CC) $(CPP_FLAGS) $(E_CFLAGS) $(INCS_DIR)  -c $<

all: $(OUTPUT)

clean:
	rm -rf *.o *.a

$(OUTPUT): $(OBJS)
	$(CROSS_COMPILE)$(AR) -crs $(OUTPUT) $(notdir $^)

.PHONY: all clean
