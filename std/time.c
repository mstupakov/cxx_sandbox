/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include <sys/time.h>

int gettimeofday(struct timeval *tv, struct timezone *tz) {
  return 0;
}

int settimeofday(const struct timeval *tv, const struct timezone *tz) {
  return 0;
}
