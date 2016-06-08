/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include <stdio.h>

extern "C" {

int cxx_module_init(void *param) {
  printf("Hello Module!\r\n");
  return 0;
}

int cxx_module_deinit(void *param) {
  printf("Goodbye!\r\n");
  return 0;
}

} /* extern "C" */
