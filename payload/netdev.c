#include "netdev.h"

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/version.h>
#include <linux/inet.h>
#include <linux/netdevice.h>

static int dummy(void) {
  return 0;
}

#if LINUX_VERSION_CODE > KERNEL_VERSION(2,6,26)
static struct net_device_ops ndo = {
  .ndo_open = dummy,
  .ndo_stop = dummy,
  .ndo_change_mtu = dummy,
  .ndo_start_xmit = dummy,
  .ndo_set_mac_address = dummy,
};
#endif

static void netdev_setup(struct net_device *dev) {
  char MAC_ADDR[] = { 0x77, 0x77, 0x77, 0x77, 0x77, 0x77 };

  ether_setup(dev);
#if LINUX_VERSION_CODE > KERNEL_VERSION(2,6,26)
  dev->netdev_ops = &ndo;
#else
  dev->open = dummy;
  dev->stop = dummy;
  dev->change_mtu = dummy;
  dev->hard_start_xmit = dummy;
  dev->set_mac_address = dummy;
#endif
  memcpy(dev->dev_addr, MAC_ADDR, sizeof(MAC_ADDR));
}

NetDev_t netdev_create(const char* if_name) {
  struct net_device *netdev = NULL;

#if LINUX_VERSION_CODE <= KERNEL_VERSION(3,18,0)
  netdev = alloc_netdev(0, if_name, netdev_setup);
#else
  netdev = alloc_netdev(0, if_name, NET_NAME_UNKNOWN, netdev_setup);
#endif

  if (!netdev) {
    return (NetDev_t) 0;
  }

  if (0 > register_netdev(netdev)) {
    printk(KERN_INFO "! Unable to register netdev: %s\n", if_name);
    free_netdev(netdev);
    return (NetDev_t) 0;
  }

  printk(KERN_INFO "! It was registered new netdev: %s\n", if_name);
  return (NetDev_t) netdev;
}

void netdev_remove(NetDev_t dev) {
  struct net_device *netdev = (struct net_device *) dev;

  printk(KERN_INFO "! Remove netdev: %s\n", netdev->name);
  unregister_netdev(netdev);
  free_netdev(netdev);
}

char* netdev_name_get(NetDev_t dev) {
  struct net_device *netdev = (struct net_device *) dev;
  return netdev->name;
}

void netdev_state_set(NetDev_t dev, NetDevState_t state) {

}
