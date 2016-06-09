OUTPUT := std.a

BASE_DIR := $(CURDIR)

K_DIR := $(BASE_DIR)/kernel/
K_INC := -I$(BASE_DIR)/include/

C_SRCS := $(wildcard *.c)
CPP_SRCS := $(wildcard *.cpp)

C_KSRCS := $(wildcard $(K_DIR)/*.c)
CPP_KSRCS := $(wildcard $(K_DIR)/*.cpp)

OBJS := $(C_SRCS:%.c=%.o) $(CPP_SRCS:%.cpp=%.o)
KOBJS := $(C_KSRCS:%.c=%.o) $(CPP_KSRCS:%.cpp=%.o)

$(K_DIR)/%.o: $(K_DIR)/%.c
	$(CROSS_COMPILE)$(CC) $(C_FLAGS) $(E_CFLAGS) $(K_INC) -c $< -o $@

$(K_DIR)/%.o: $(K_DIR)/%.cpp
	$(CROSS_COMPILE)$(CC) $(CPP_FLAGS) $(E_CFLAGS) $(K_INC) -c $< -o $@

%.o: %.c
	$(CROSS_COMPILE)$(CC) $(C_FLAGS) $(E_CFLAGS) $(K_INC) -D___USER___ -c $<

%.o: %.cpp
	$(CROSS_COMPILE)$(CC) $(CPP_FLAGS) $(E_CFLAGS) $(K_INC) -D___USER___ -c $<

all: $(OUTPUT)

clean:
	rm -rf *.o *.a
	rm -rf $(K_DIR)/*.o $(K_DIR)/*.a

$(OUTPUT): $(OBJS) $(KOBJS)
	$(CROSS_COMPILE)$(AR) -crs $(OUTPUT) $^

.PHONY: all clean

