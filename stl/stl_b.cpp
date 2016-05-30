#include <stddef.h>
//#include <new>
//#include <linux/slub.h>



extern "C" void* __kmalloc(size_t, int);
extern "C" void kfree(void*);

void stl_cpp(void);
void stl_cpp(void) {}



void* operator new(size_t size);
void operator delete(void* p);

void* operator new(size_t size)
{
  return __kmalloc(size, 0);
}

void operator delete(void* p)
{
  kfree(p);
}

void* operator new[](size_t size)
{
  return __kmalloc(size, 0);
}

void operator delete[](void* p)
{
  kfree(p);
}

