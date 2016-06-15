/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include <unistd.h>
#include <stdlib.h>
#include <libgen.h>
#include <string.h>
#include <execinfo.h>

#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <k_io.h>
#include <k_sort.h>
#include <k_misc.h>

void __assert_fail(void) {
  printf("Assert: there is a BUG! The program MUST be terminated!\r\n");

  __k_dumpstack();
  sleep(20);
}

long int strtol(const char *nptr, char **endptr, int base) {   
  long res = 0;
  __k_kstrtoul(nptr, base, &res);
  return res;
}

long long int strtoll(const char *nptr, char **endptr, int base) {   
  long long res = 0;
  __k_kstrtoll(nptr, base, &res);
  return res;
}

int rand(void) {
  int i = 0;
  
  __k_get_random_bytes(&i, sizeof(i));
  return i;
}

int rand_r(unsigned int *seedp) {
  return 0;
}

void srand(unsigned int seed) {
}

void qsort(void *base, size_t nmemb, size_t size,
           int (*compar)(const void *, const void *)) {
  __k_sort(base, nmemb, size, compar, NULL);
}

int close(int fd) {
  printf("Func: %s, line: %u\r\n", __PRETTY_FUNCTION__, __LINE__);
  return 0;
}

int open(const char *pathname, int flags, mode_t mode) {
  printf("Func: %s, line: %u\r\n", __PRETTY_FUNCTION__, __LINE__);
  return 0;
}

int msync(void *addr, size_t length, int flags) {
  printf("Func: %s, line: %u\r\n", __PRETTY_FUNCTION__, __LINE__);
  return 0;
}

char *strdup(const char *s) {
  printf("Func: %s, line: %u\r\n", __PRETTY_FUNCTION__, __LINE__);
  return 0;
}

ssize_t read(int fd, void *buf, size_t count) {
  printf("Func: %s, line: %u\r\n", __PRETTY_FUNCTION__, __LINE__);
  return 0;
}

ssize_t write(int fd, const void *buf, size_t count) {
  printf("Func: %s, line: %u\r\n", __PRETTY_FUNCTION__, __LINE__);

  if ((fd == 1) || (fd == 2)) {
    printf(buf);
  }

  return count;
}

void *mmap(void *addr, size_t length, int prot, int flags,
           int fd, off_t offset) {
  printf("Func: %s, line: %u\r\n", __PRETTY_FUNCTION__, __LINE__);
  return 0;
}

int munmap(void *addr, size_t length) {
  printf("Func: %s, line: %u\r\n", __PRETTY_FUNCTION__, __LINE__);
  return 0;
}

char *strerror(int errnum) {
  printf("Func: %s, line: %u\r\n", __PRETTY_FUNCTION__, __LINE__);
  return 0;
}

int ioctl(int d, unsigned long request, ...) {
  printf("Func: %s, line: %u\r\n", __PRETTY_FUNCTION__, __LINE__);
  return 0;
}

off_t lseek(int fd, off_t offset, int whence) {
  printf("Func: %s, line: %u\r\n", __PRETTY_FUNCTION__, __LINE__);
  return 0;
}

int backtrace(void **buffer, int size) {
  printf("Func: %s, line: %u\r\n", __PRETTY_FUNCTION__, __LINE__);
  return 0;
}

char **backtrace_symbols(void *const *buffer, int size) {
  printf("Func: %s, line: %u\r\n", __PRETTY_FUNCTION__, __LINE__);
  return 0;
}

void *__memcpy_chk(void * dest, const void * src, size_t len, size_t destlen) {
  printf("Func: %s, line: %u\r\n", __PRETTY_FUNCTION__, __LINE__);
  return 0;
}

int *__errno_location(void) {
  printf("Func: %s, line: %u\r\n", __PRETTY_FUNCTION__, __LINE__);
  return 0;
}

