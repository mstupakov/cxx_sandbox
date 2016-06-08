/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include <stdlib.h>

extern int __cxa_atexit(void (*func) (void*), void* arg, void* dso_handle);
extern int __aeabi_atexit(void *obj, void (*func) (void*), void* dso_handle);
extern void __cxa_finalize(void *dso_handle);

void *__dso_handle;

int atexit(void (*func) (void)) {
  return __cxa_atexit((void (*) (void *)) func, NULL,
                      &__dso_handle == NULL ? NULL : __dso_handle);
}

void cleanup(void) {
  __cxa_finalize(__dso_handle);
}
