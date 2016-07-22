/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include <string.h>
#include <limits.h>
#include <errno.h>
#include <malloc.h>

#include <k_io.h>
#include <k_misc.h>

char * __strcat_chk(char * dest, const char * src, size_t destlen) {
  return strcat(dest, src);
}

char * __strncat_chk(char * s1, const char * s2, size_t n, size_t s1len) {
  return strncat(s1, s2, n);
}

char * __strcpy_chk(char * dest, const char * src, size_t destlen) {
  return strcpy(dest, src);
}

char * __strncpy_chk(char * s1, const char * s2, size_t n, size_t s1len) {
  return strncpy(s1, s2, n);
}

void * __memset_chk(void * dest, int c, size_t len, size_t destlen) {
  return memset(dest, c, len);
}

void * __memcpy_chk(void * dest, const void * src, size_t len, size_t destlen) {
  return memcpy(dest, src, len);
}

char * __attribute__((weak)) strerror(int errnum) {
  return "Has not imlemented yet.";
}

long int __attribute__((weak)) strtol(const char *nptr, char **endptr, int base) {
  long res = 0;

  if (!__k_kstrtol(nptr, base, &res)) {
    if (endptr) {
      *endptr = nptr + strlen(nptr);
    }
  } else {
    if (endptr) {
      *endptr = nptr;
    }
  }
  return res;
}

long long int __attribute__((weak)) strtoll(const char *nptr, char **endptr, int base) {
  long long res = 0;

  if (!__k_kstrtoll(nptr, base, &res)) {
    if (endptr) {
      *endptr = nptr + strlen(nptr);
    }
  } else {
    if (endptr) {
      *endptr = nptr;
    }
  }
  return res;
}

unsigned long int __attribute__((weak)) strtoul(const char *nptr, char **endptr, int base) {
  unsigned long res = 0;

  if (!__k_kstrtoul(nptr, base, &res)) {
    if (endptr) {
      *endptr = nptr + strlen(nptr);
    }
  } else {
    if (endptr) {
      *endptr = nptr;
    }
  }
  return res;
}

unsigned long long int __attribute__((weak)) strtoull(const char *nptr, char **endptr, int base) {
  unsigned long long res = 0;

  if (!__k_kstrtoull(nptr, base, &res)) {
    if (endptr) {
      *endptr = nptr + strlen(nptr);
    }
  } else {
    if (endptr) {
      *endptr = nptr;
    }
  }
  return res;
}

int __attribute__((weak)) atoi(const char *__nptr) {
  long res = 0;

  __k_kstrtol(__nptr, 10, &res);
  return res;
}

char * __attribute__((weak)) strdup(const char *s) {
  int len = strlen(s) + 1;
  char* dup = malloc(len);
  if (dup) {
    memcpy(dup, s, len);
  }
  return dup;
}


