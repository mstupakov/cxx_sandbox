/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#ifndef __SORT_H__
#define __SORT_H__

#ifndef ___USER___
#include <linux/module.h>
#include <linux/kernel.h>
#else
#include <stdio.h>
#endif

void __k_sort(void *base, size_t num, size_t size,
              int (*cmp)(const void *, const void *),
              void (*swap)(void *, void *, int));

#endif /* __K_SORT_H__ */
