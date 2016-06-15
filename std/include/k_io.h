/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#ifndef __IOLIB_H__
#define __IOLIB_H__

#ifndef ___USER___
#include <linux/module.h>
#include <linux/kernel.h>
#else
#include <stdarg.h>
#endif

int __k_vsnprintf(char *buf, size_t size, const char *fmt, va_list args);
int __k_vprintf(const char *format, va_list args);

int __k_kstrtoul(const char *s, unsigned int base, unsigned long *res);
int __k_kstrtoll(const char *s, unsigned int base, long long *res);

void __k_get_random_bytes(void *buf, int nbytes);

#endif /* __K_IOLIB_H__ */
