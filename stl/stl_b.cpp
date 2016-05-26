#include <stddef.h>

void stl_cpp(void);
void stl_cpp(void) {}

void* operator new(size_t size);
void operator delete(void* p);

void* operator new(size_t size)
{
    return 0;
}

void operator delete(void* p)
{
}

void* operator new[](size_t size)
{
    return 0;
}

void operator delete[](void* p)
{
}

