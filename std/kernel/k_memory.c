/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include <k_memory.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/vmalloc.h>

void* __k_malloc(long unsigned int sz) {
  return vmalloc(sz);
}

void __k_free(void* p) {
  return vfree(p);
}
