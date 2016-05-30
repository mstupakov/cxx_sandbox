OUTPUT := stl.a

C_SRCS := $(wildcard *.c)
CPP_SRCS := $(wildcard *.cpp)

SRCS := $(C_SRCS) $(CPP_SRCS)
OBJS := $(C_SRCS:%.c=%.o) $(CPP_SRCS:%.cpp=%.o)

%.o: %.c
	$(CROSS_COMPILE)$(CC) $(C_FLAGS) $(E_CFLAGS) -c $<

%.o: %.cpp
	$(CROSS_COMPILE)$(CC) $(CPP_FLAGS) $(E_CFLAGS) -c $<

all: $(OUTPUT)

clean:
	rm -rf *.o *.a

$(OUTPUT): $(OBJS)
	$(CROSS_COMPILE)$(AR) -crs $(OUTPUT) $(notdir $^)

.PHONY: all clean
