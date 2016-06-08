/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include <stdlib.h>

extern void cleanup(void);

extern void (*__init_array_start []) (int, char **, char **);
extern void (*__init_array_end []) (int, char **, char **);
extern void (*__fini_array_start []) (void);
extern void (*__fini_array_end []) (void);

static void __init(void) {
  size_t i = 0;

  for (i = 0; i < __init_array_end - __init_array_start; i++) {
    __init_array_start[i](0, NULL, NULL);
  }
}

static void __fini(void) {
  size_t i = __fini_array_end - __fini_array_start;

  while (i--) {
    __fini_array_start[i]();
  }
}

void __crt_init(void) {
  atexit(__fini);
  __init();
}

void __crt_fini(void) {
  cleanup();
}
