#include "driver.h"
#include "netdev.h"

#include <iostream>
using namespace std;

Driver::Driver() { 
  cout << "! " << __PRETTY_FUNCTION__ << endl; 
}

Driver::~Driver() { 
  cout << "! " <<__PRETTY_FUNCTION__ << endl;
  cout << "! " << "Remove all network devices" << endl;

  for (vector<NetDev_t>::iterator it = m_devs.begin(); it != m_devs.end();) {
    netdev_remove(*it);
    it = m_devs.erase(it);
  }
}

void Driver::createNetdev(string name) {
  NetDev_t dev = netdev_create(name.c_str());
  
  if (!dev) {
    cout << "! Tried to create an interface but without any success: " << name << endl;
    return;
  }

  m_devs.push_back(dev);
}

void Driver::removeNetdev(string name) {
  for (vector<NetDev_t>::iterator it = m_devs.begin(); it != m_devs.end(); ++it) {
    if (name == string(netdev_name_get(*it))) {
      netdev_remove(*it);
      m_devs.erase(it);
      break;
    }
  }
}

void Driver::getNameNetdevs() {
  cout << "! Iterate over netdevs: " << endl;
  for (vector<NetDev_t>::iterator it = m_devs.begin(); it != m_devs.end(); ++it) {
    cout << "! - " << netdev_name_get(*it) << endl;
  }
}

