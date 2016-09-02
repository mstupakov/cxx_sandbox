OUTPUT := payload.a

C_SRCS := $(wildcard *.c)
CPP_SRCS := $(wildcard *.cpp)

SRCS := $(C_SRCS) $(CPP_SRCS)
OBJS := $(C_SRCS:%.c=%.o) $(CPP_SRCS:%.cpp=%.o)

%.o: %.c
	$(CC) -I. $(C_FLAGS) $(E_CFLAGS) $(K_CFLAGS) -c $<

%.o: %.cpp
	$(CC) -I. $(CPP_FLAGS) $(E_CFLAGS) $(K_CFLAGS) -c $<

all: $(OUTPUT)

clean:
	rm -rf *.o *.a

$(OUTPUT): $(OBJS)
	$(AR) -crs $(OUTPUT) $^

.PHONY: all clean
