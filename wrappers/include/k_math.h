/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#ifndef __K_MATH_H__
#define __K_MATH_H__

#ifndef ___USER___
#include <linux/module.h>
#include <linux/kernel.h>
#endif

int __k_ilog2(int value);
int __k_roundup_pow_of_two(int value);
int __k_rounddown_pow_of_two(int value);
int __k_order_base_2(int value);

#endif /* __K_MATH_H__ */
