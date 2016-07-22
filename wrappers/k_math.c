/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include <k_math.h>

#include <linux/kernel.h>
#include <linux/module.h>

int __k_ilog2(int value) {
  return ilog2(value);
}

int __k_roundup_pow_of_two(int value) {
  return roundup_pow_of_two(value);
}

int __k_rounddown_pow_of_two(int value) {
  return rounddown_pow_of_two(value);
}

int __k_order_base_2(int value) {
  return order_base_2(value);
}
