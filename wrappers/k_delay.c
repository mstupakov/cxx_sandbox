/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include <k_delay.h>

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/delay.h>

int __k_usleep(unsigned int usec) {
  udelay(usec);
  return 0;
}

unsigned int __k_sleep(unsigned int seconds) {
  ssleep(seconds);
  return 0;
}
