/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include <k_misc.h>
#include <linux/kernel.h>
#include <linux/module.h>

void __k_dumpstack(void) {
  dump_stack();
}
