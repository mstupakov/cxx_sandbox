#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init dummy_module_init(void) {
  return 0;
}

static void __exit dummy_module_exit(void) {
}

module_init(dummy_module_init);
module_exit(dummy_module_exit);

MODULE_LICENSE("GPL");
