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

#endif /* __K_MISC_H__ */
