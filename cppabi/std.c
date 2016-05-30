//##include <linux/kernel.h>
//##include <linux/module.h>

#include <stdio.h>
#include <stdarg.h>

#define KERN_INFO "\0016! "
extern int printk(const char* fmt, ...);


int __printf_chk(int __flag, const char *__restrict __format, ...) {
  printk(__format);
  return 0;
}

int printf(const char *format, ...) {
  printk("Hello");
  return 0;
}



void *malloc(size_t sz) {
  return 0;
}

void free(void *p) {
}


void __assert_fail(void) {}
