/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include <stdio.h>
#include <stdarg.h>

#define ___USER___
#include <k_io.h>

int __printf_chk(int __flag, const char *__restrict __format, ...) {
  int n = 0;

  va_list args;
  va_start(args, __format);

  n = __k_vprintf(__format, args);

  va_end(args);
  return n;
}

int printf(const char *format, ...) {
  int n = 0;

  va_list args;
  va_start(args, format);

  n = __k_vprintf(format, args);

  va_end(args);
  return n;
}
