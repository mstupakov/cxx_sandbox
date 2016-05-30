#include <linux/module.h>
#include <linux/kernel.h>

extern int cpp_module_init(void *param);
extern int cpp_module_deinit(void *param);

static void __exit kmodule_exit(void)
{
  printk(KERN_INFO "! Enter: %s\n", __FUNCTION__);
  cpp_module_deinit(0);
}

static int __init kmodule_init(void)
{
  printk(KERN_INFO "! Enter: %s, kmodule_init: %p, kmodule_exit: %p\n", __FUNCTION__, kmodule_init, kmodule_exit);
  return cpp_module_init(0);
}


module_init(kmodule_init);
module_exit(kmodule_exit);

MODULE_LICENSE("GPL");
