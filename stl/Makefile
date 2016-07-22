OUTPUT := stl.a

BASE_DIR := $(CURDIR)
INCS_DIR := -I$(BASE_DIR)/include/ustl/

C_SRCS := $(wildcard *.c)
CPP_SRCS := $(wildcard *.cc)

SRCS := $(C_SRCS) $(CPP_SRCS)
OBJS := $(C_SRCS:%.c=%.o) $(CPP_SRCS:%.cc=%.o)

%.o: %.c
	$(CC) $(C_FLAGS) $(E_CFLAGS) $(K_CFLAGS) -c $<

%.o: %.cc
	$(CC) $(CPP_FLAGS) $(E_CFLAGS) $(K_CFLAGS) $(INCS_DIR)  -c $<

all: $(OUTPUT)

clean:
	rm -rf *.o *.a

$(OUTPUT): $(OBJS)
	$(AR) -crs $(OUTPUT) $(notdir $^)

.PHONY: all clean
