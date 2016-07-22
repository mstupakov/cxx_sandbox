/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#ifndef __K_MISC_H__
#define __K_MISC_H__

#ifndef ___USER___
#include <linux/module.h>
#include <linux/kernel.h>
#endif

void __k_dumpstack(void);
int __k_isalnum(int x);
int __k_isalpha(int x);
int __k_isascii(int x);
int __k_iscntrl(int x);
int __k_isdigit(int x);
int __k_isgraph(int x);
int __k_islower(int x);
int __k_isprint(int x);
int __k_ispunct(int x);
int __k_isspace(int x);
int __k_isupper(int x);
int __k_isxdigit(int x);
int __k_tolower(int x);
int __k_taskid_get(void);

void __k_get_random_bytes(void *buf, int nbytes);

#endif /* __K_MISC_H__ */
