#ifndef __DRIVER_H__
#define __DRIVER_H__

#include "netdev.h"

#include <string>
#include <vector>
using namespace std;

class Driver {
  vector<NetDev_t> m_devs;
public:
  Driver();
 ~Driver();

  void createNetdev(string name);
  void removeNetdev(string name);
  void getNameNetdevs();
};

#endif /* __DRIVER_H__ */

