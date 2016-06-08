#include <stdio.h>
#include <ustl.h>

void test_cpp(void);

void test_cpp(void) {
  printf("Func: %s, line: %u\r\n", __PRETTY_FUNCTION__, __LINE__);
}
