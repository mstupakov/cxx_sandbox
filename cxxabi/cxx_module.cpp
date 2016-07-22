/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include <stdio.h>

extern "C" {

extern void __crt_init(void);
extern void __crt_fini(void);

int __attribute__((weak)) kernel_module_init(void) {
  printf("! Enter: %s\n", __FUNCTION__);
  return 0;
}

int __attribute__((weak)) kernel_module_deinit(void) {
  printf("! Enter: %s\n", __FUNCTION__);
  return 0;
}

int cxx_module_init(void *param) {
  printf("! Enter: %s\n", __FUNCTION__);

  __crt_init();
  return kernel_module_init();
}

int cxx_module_deinit(void *param) {
  printf("! Enter: %s\n", __FUNCTION__);

  int rc = kernel_module_deinit();
  __crt_fini();
  return rc;
}

} /* extern "C" */
