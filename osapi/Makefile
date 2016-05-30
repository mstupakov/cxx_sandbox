OUTPUT := osapi.a

BASE_DIR := $(CURDIR)

I_DIR := $(BASE_DIR)/include/
S_DIR := $(BASE_DIR)/kernelspace/

C_SRCS := $(wildcard $(S_DIR)/*.c)
CPP_SRCS := $(wildcard $(S_DIR)/*.cpp)

SRCS := $(C_SRCS) $(CPP_SRCS)
OBJS := $(C_SRCS:%.c=%.o) $(CPP_SRCS:%.cpp=%.o)

%.o: %.c
	$(CROSS_COMPILE)$(CC) $(C_FLAGS) $(E_CFLAGS) -I$(I_DIR) -c $<

%.o: %.cpp
	$(CROSS_COMPILE)$(CC) $(CPP_FLAGS) $(E_CFLAGS) -I$(I_DIR) -c $<

all: $(OUTPUT)

clean:
	rm -rf *.o *.a

$(OUTPUT): $(OBJS)
	$(CROSS_COMPILE)$(AR) -crs $(OUTPUT) $(notdir $^)

.PHONY: all clean
