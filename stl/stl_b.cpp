#include <stddef.h>
#include <stdlib.h>


void stl_cpp(void);
void stl_cpp(void) {}


void* operator new(size_t size) {
  return malloc(size);
}

void operator delete(void* p) {
  free(p);
}

void* operator new[](size_t size) {
  return malloc(size);
}

void operator delete[](void* p) {
  free(p);
}
