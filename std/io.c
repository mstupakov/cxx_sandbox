/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

#include <k_io.h>

int __vsprintf_chk(char * s, int flag, size_t slen, 
                   const char * format, va_list args) {
  return __k_vsnprintf(s, INT_MAX, format, args);
}

int __vsnprintf_chk(char * s, size_t maxlen, int flag, 
                    size_t slen, const char * format, va_list args) {
  return __k_vsnprintf(s, maxlen, format, args);
}

int __sprintf_chk(char * str, int flag, 
                  size_t strlen, const char * format, ...) {
  int n = 0;
 
  va_list args;
  va_start(args, format);

  n = __k_vsnprintf(str, INT_MAX, format, args);

  va_end(args);
  return n;
}

int __snprintf_chk(char * str, size_t maxlen, 
                   int flag, size_t strlen, const char * format, ...) {
  int n = 0;
 
  va_list args;
  va_start(args, format);

  n = __k_vsnprintf(str, maxlen, format, args);

  va_end(args);
  return n;
}

int __printf_chk(int __flag, const char *__restrict __format, ...) {
  int n = 0;

  va_list args;
  va_start(args, __format);

  n = vprintf(__format, args);

  va_end(args);
  return n;
}

/* No need as provided by kernel.
int __attribute__((weak)) vsnprintf(char *str, size_t size, const char *format, va_list ap) {
  return __k_vsnprintf(str, size, format, ap);
}
*/

int __attribute__((weak)) printf(const char *format, ...) {
  int n = 0;

  va_list args;
  va_start(args, format);

  n = __k_vprintf(format, args);

  va_end(args);
  return n;
}

int __attribute__((weak)) vprintf(const char *format, va_list ap) {
  return __k_vprintf(format, ap);
}

