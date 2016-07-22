/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <errno.h>

#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/syscall.h>

#include <k_io.h>
#include <k_sort.h>
#include <k_misc.h>

int __errno;

void __assert_fail(void) {
  printf("Assert: there is a BUG! The program MUST be terminated!\r\n");

  __k_dumpstack();
  sleep(20);
}

void __assert(const char *msg, const char *file, int line) {
  __assert_fail();
}

int *__errno_location(void) {
  return &__errno;
}

int __attribute__((weak)) rand(void) {
  int i = 0;

  __k_get_random_bytes(&i, sizeof(i));
  return i;
}

int __attribute__((weak)) rand_r(unsigned int *seedp) {
  unsigned int value = *seedp;

  __k_get_random_bytes(&value, sizeof(value));
  *seedp = value;
  return value;
}

void __attribute__((weak)) srand(unsigned int seed) {
  printf("Func: %s, line: %u\r\n", __PRETTY_FUNCTION__, __LINE__);
}

void __attribute__((weak)) qsort(void *base, size_t nmemb, size_t size,
           int (*compar)(const void *, const void *)) {
  __k_sort(base, nmemb, size, compar, NULL);
}

int __attribute__((weak)) close(int fd) {
  printf("Func: %s, line: %u\r\n", __PRETTY_FUNCTION__, __LINE__);
  return 0;
}

int __attribute__((weak)) open(const char *pathname, int flags, mode_t mode) {
  printf("Func: %s, line: %u\r\n", __PRETTY_FUNCTION__, __LINE__);
  return 0;
}

ssize_t __attribute__((weak)) read(int fd, void *buf, size_t count) {
  printf("Func: %s, line: %u\r\n", __PRETTY_FUNCTION__, __LINE__);
  __errno = EINTR;
  return -1;
}

ssize_t __attribute__((weak)) write(int fd, const void *buf, size_t count) {
  if ((fd == 1) || (fd == 2)) {
    printf(buf);
  }

  return count;
}

int __attribute__((weak)) ioctl(int d, unsigned long request, ...) {
  printf("Func: %s, line: %u\r\n", __PRETTY_FUNCTION__, __LINE__);
  return 0;
}

off_t __attribute__((weak)) lseek(int fd, off_t offset, int whence) {
  printf("Func: %s, line: %u\r\n", __PRETTY_FUNCTION__, __LINE__);
  return 0;
}

int __attribute__((weak)) isalnum(int x) {
  return __k_isalnum(x);
}

int __attribute__((weak)) isalpha(int x) {
  return __k_isalpha(x);
}

int __attribute__((weak)) isascii(int x) {
  return __k_isascii(x);
}

int __attribute__((weak)) iscntrl(int x) {
  return __k_iscntrl(x);
}

int __attribute__((weak)) isdigit(int x) {
  return __k_isdigit(x);
}

int __attribute__((weak)) isgraph(int x) {
  return __k_isgraph(x);
}

int __attribute__((weak)) islower(int x) {
  return __k_islower(x);
}

int __attribute__((weak)) isprint(int x) {
  return __k_isprint(x);
}

int __attribute__((weak)) ispunct(int x) {
  return __k_ispunct(x);
}

int __attribute__((weak)) isspace(int x) {
  return __k_isspace(x);
}

int __attribute__((weak)) isupper(int x) {
  return __k_isupper(x);
}

int __attribute__((weak)) isxdigit(int x) {
  return __k_isxdigit(x);
}

int __attribute__((weak)) tolower(int x) {
  return __k_tolower(x);
}

