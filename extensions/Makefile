OUTPUT := ext.a

C_SRCS := $(wildcard *.c)
CPP_SRCS := $(wildcard *.cpp)

SRCS := $(C_SRCS) $(CPP_SRCS)
OBJS := $(C_SRCS:%.c=%.o) $(CPP_SRCS:%.cpp=%.o)

%.o: %.c
	$(CC) $(C_FLAGS) $(E_CFLAGS) $(K_CFLAGS) -D___USER___ -c $<

%.o: %.cpp
	$(CC) $(CPP_FLAGS) $(E_CFLAGS) $(K_CFLAGS) -D___USER___ -c $<

all: $(OUTPUT)

clean:
	rm -rf *.o *.a

$(OUTPUT): $(OBJS)
	$(AR) -crs $(OUTPUT) $^

.PHONY: all clean
