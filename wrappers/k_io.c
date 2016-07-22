/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include <k_io.h>

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/version.h>

int __k_vsnprintf(char *buf, size_t size, const char *fmt, va_list args) {
  return vsnprintf(buf, size, fmt, args);
}

int __k_vprintf(const char *format, va_list args) {
  return vprintk(format, args);
}

int __k_kstrtoul(const char *s, unsigned int base, unsigned long *res) {
#if LINUX_VERSION_CODE < KERNEL_VERSION(3,0,0) 
  return strict_strtoul(s, base, res);
#else
  return kstrtoul(s, base, res);
#endif
}

int __k_kstrtoull(const char *s, unsigned int base, unsigned long long *res) {
#if LINUX_VERSION_CODE < KERNEL_VERSION(3,0,0)
  return strict_strtoull(s, base, res);
#else
  return kstrtoull(s, base, res);
#endif
}

int __k_kstrtol(const char *s, unsigned int base, long *res) {
#if LINUX_VERSION_CODE < KERNEL_VERSION(3,0,0) 
  return strict_strtol(s, base, res);
#else
  return kstrtol(s, base, res);
#endif
}

int __k_kstrtoll(const char *s, unsigned int base, long long *res) {
#if LINUX_VERSION_CODE < KERNEL_VERSION(3,0,0)
  return strict_strtoll(s, base, res);
#else
  return kstrtoll(s, base, res);
#endif
}

