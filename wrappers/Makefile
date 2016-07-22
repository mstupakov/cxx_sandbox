OUTPUT := wrp.a

BASE_DIR := $(CURDIR)

K_DIR := $(BASE_DIR)/
K_INC := -I$(K_DIR)/include/

C_KSRCS := $(wildcard $(K_DIR)/*.c)
CPP_KSRCS := $(wildcard $(K_DIR)/*.cpp)

KOBJS := $(C_KSRCS:%.c=%.o) $(CPP_KSRCS:%.cpp=%.o)

$(K_DIR)/%.o: $(K_DIR)/%.c
	$(CC) $(C_FLAGS) $(E_CFLAGS) $(K_CFLAGS) $(K_INC) -c $< -o $@

$(K_DIR)/%.o: $(K_DIR)/%.cpp
	$(CC) $(CPP_FLAGS) $(E_CFLAGS) $(K_CFLAGS) $(K_INC) -c $< -o $@

all: $(OUTPUT)

clean:
	rm -rf $(K_DIR)/*.o $(K_DIR)/*.a

$(OUTPUT): $(KOBJS) $(HOBJS)
	$(AR) -crs $(OUTPUT) $^

.PHONY: all clean

