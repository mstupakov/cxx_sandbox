/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include <k_io.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/random.h>

int __k_vprintf(const char *format, va_list args) {
  return vprintk(format, args);
}

int __k_kstrtoul(const char *s, unsigned int base, unsigned long *res) {
  return kstrtoul(s, base, res);
}

int __k_kstrtoll(const char *s, unsigned int base, long long *res) {
  return kstrtoll(s, base, res);
}

void __k_get_random_bytes(void *buf, int nbytes) {
  get_random_bytes(buf, nbytes);
}
