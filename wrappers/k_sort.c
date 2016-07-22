/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include <k_sort.h>

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sort.h>

void __k_sort(void *base, size_t num, size_t size,
              int (*cmp)(const void *, const void *),
              void (*swap)(void *, void *, int)) {
  sort(base, num, size, cmp, swap);
}
