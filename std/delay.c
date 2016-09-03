/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include <unistd.h>

#include <k_delay.h>

int usleep(unsigned int usec) {
  return __k_usleep(usec);
}

unsigned int sleep(unsigned int seconds) {
  return __k_sleep(seconds);
}
