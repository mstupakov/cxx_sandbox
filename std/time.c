/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include <sys/time.h>
#include <time.h>
#include <string.h>
#include <k_time.h>

int __attribute__((weak)) gettimeofday(struct timeval *tv, 
                                       struct timezone *tz) {
  struct __K_timeval _tv;

  memset(tv, 0, sizeof(*tv));
  //memset(tz, 0, sizeof(*tz));

  __k_do_gettimeofday(&_tv);

  tv->tv_sec = _tv.tv_sec;
  tv->tv_usec = _tv.tv_usec;
  return 0;
}

int __attribute__((weak)) settimeofday(const struct timeval *tv, 
                                       const struct timezone *tz) {
  struct __K_timeval _tv;

  memset(&_tv, 0, sizeof(_tv));
  _tv.tv_sec = tv->tv_sec;
  _tv.tv_usec = tv->tv_usec;

  return __k_do_settimeofday(&_tv);
}

int __attribute__((weak)) clock_gettime(clockid_t clk_id, 
                                        struct timespec *tp) {
  struct __K_timespec _tp;
  memset(&_tp, 0, sizeof(_tp));

  __k_getnstimeofday(&_tp);

  tp->tv_sec = _tp.tv_sec;
  tp->tv_nsec = _tp.tv_nsec;

  return 0;
}
