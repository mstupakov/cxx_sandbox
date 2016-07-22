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
#include <linux/slab.h>
#include <linux/interrupt.h>

void* __k_vmalloc(long unsigned int sz) {
  return vmalloc(sz);
}

void __k_vfree(void* p) {
  return vfree(p);
}

void* __k_kmalloc(long unsigned int sz) {
  if (in_interrupt()) {
    return kmalloc(sz, GFP_ATOMIC);
  }

  return kmalloc(sz, GFP_KERNEL);
}

void __k_kfree(void* p) {
  return kfree(p);
}
