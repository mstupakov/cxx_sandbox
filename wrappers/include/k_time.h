/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#ifndef __K_TIME_H__
#define __K_TIME_H__

struct __K_timeval {
  unsigned long tv_sec;
  unsigned long tv_usec;
};

struct __K_timespec {
  unsigned long tv_sec;
  unsigned long tv_nsec;
};

void __k_do_gettimeofday(struct __K_timeval *tv);
int __k_do_settimeofday(struct __K_timeval *tv);
void __k_getnstimeofday(struct __K_timespec *tp);

#endif /* __K_TIME_H__ */
