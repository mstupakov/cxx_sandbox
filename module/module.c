/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include <linux/module.h>
#include <linux/kernel.h>

extern int cxx_module_init(void *param);
extern int cxx_module_deinit(void *param);

static int __init kmodule_init(void)
{
  printk(KERN_INFO "! Enter: %s\n", __FUNCTION__);
  return cxx_module_init(0);
}

static void __exit kmodule_exit(void)
{
  printk(KERN_INFO "! Enter: %s\n", __FUNCTION__);
  cxx_module_deinit(0);
}

module_init(kmodule_init);
module_exit(kmodule_exit);

MODULE_LICENSE("GPL");
