/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include <fcntl.h>
#include <stdio.h>

int __attribute__((weak)) fcntl(int fd, int cmd, ... /* arg */ ) {
  printf("Func: %s, line: %u\r\n", __PRETTY_FUNCTION__, __LINE__);
  return -1;
}

int __attribute__((weak)) fsync(int fd) {
  printf("Func: %s, line: %u\r\n", __PRETTY_FUNCTION__, __LINE__);
  return -1;
}
