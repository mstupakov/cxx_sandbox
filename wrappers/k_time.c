/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include <k_time.h>

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/version.h>
#include <linux/time.h>

void __k_do_gettimeofday(struct __K_timeval *tv) {
  struct timeval _tv;

  do_gettimeofday(&_tv);
  memset(tv, 0, sizeof(*tv));

  tv->tv_sec = _tv.tv_sec;
  tv->tv_usec = _tv.tv_usec;
}

int __k_do_settimeofday(struct __K_timeval *tv) {
#if LINUX_VERSION_CODE < KERNEL_VERSION(3,19,0) 
  struct timeval _tv;
  memset(&_tv, 0, sizeof(_tv));

  _tv.tv_sec = tv->tv_sec;
  _tv.tv_usec = tv->tv_usec;

  return do_settimeofday(&_tv);
#else
  struct timespec64 _ts;
  memset(&_ts, 0, sizeof(_ts));

  _ts.tv_sec = tv->tv_sec;
  _ts.tv_nsec = tv->tv_usec * 1000;

  return do_settimeofday64(&_ts);
#endif
}

void __k_getnstimeofday(struct __K_timespec *tp) {
  struct timespec _tp;

  getnstimeofday(&_tp);
  memset(tp, 0, sizeof(*tp));

  tp->tv_sec = _tp.tv_sec;
  tp->tv_nsec = _tp.tv_nsec;
}

