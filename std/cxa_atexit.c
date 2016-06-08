/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include <stdlib.h>

static struct atexit_handler {
  void (*func) (void*);
  void* arg;
  void* dso_handle;

  struct atexit_handler *next;
} *head;

int __cxa_atexit(void (*func) (void*), void* arg, void* dso_handle) {
  struct atexit_handler *p = malloc(sizeof(struct atexit_handler));

  if (!p) {
    return -1;
  }

  p->func = func;
  p->arg = arg;
  p->dso_handle = dso_handle;

  p->next = head;
  head = p;

  return 0;
}

int __aeabi_atexit(void* obj, void (*func) (void*), void* dso_handle) {
  return __cxa_atexit(func, obj, dso_handle);
}

void __cxa_finalize(void *dso_handle) {
  struct atexit_handler *p = head;

  while (p) {
    p->func(p->arg);
    p = p->next;
  }

  head = NULL;
  return 0;
}
