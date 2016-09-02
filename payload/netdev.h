#ifndef __NETDEV_H__
#define __NETDEV_H__

#ifdef __cplusplus 
extern "C" {
#endif

typedef void* NetDev_t;

typedef enum {
  NETDEV_STATE_UP,
  NETDEV_STATE_DOWN
} NetDevState_t;

NetDev_t netdev_create(const char* if_name);
void netdev_remove(NetDev_t dev);
char* netdev_name_get(NetDev_t dev);
void netdev_state_set(NetDev_t dev, NetDevState_t state);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __NETDEV_H__ */

