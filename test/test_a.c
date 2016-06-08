#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void test_c(void);

void my_func(void) {
  sleep(2);
  printf("Func: %s, line: %u\r\n", __PRETTY_FUNCTION__, __LINE__);
}

void test_c(void) {
  int i = 0;

  atexit(my_func);

  for (i = 7; i < 15; i++) {
  	printf("Func: %s, line: %u, i: %u\r\n", __PRETTY_FUNCTION__, __LINE__, i);
  }
}
