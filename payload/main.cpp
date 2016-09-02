#include "shape.h"
#include "driver.h"

#include <stdio.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>
using namespace std;

/* Example 1: Create global objects: call constructors/destructors */
class Global {
  static int instance;
public:
  Global() { instance++; cout <<  "! Global object(" << instance << "): " << __PRETTY_FUNCTION__ << endl; }
 ~Global() { cout << "! Global object(" << instance << "): " << __PRETTY_FUNCTION__ << endl; instance--; }
};

int Global::instance;

vector<Global> gl_vec(3);
Driver drv;

int main() {
  cout << "! Yes, it's C++'s main() function!" << endl;

  /* Example 2: Create an collection of shapes. */
  shape();

  /* Example 3: Create network devices. */
  char str[20];
  for (int i = 0; i < 10; i++) {
    sprintf(str, "%s%d", "My_NetDev_", i);
    drv.createNetdev(str);
  }
  
  /* Example 4: Show all just cretaed network devices. */
  drv.getNameNetdevs();

  /* Example 5: Remove first 5 just cretaed network devices. */
  for (int i = 0; i < 5; i++) {
    sprintf(str, "%s%d", "My_NetDev_", i);
    drv.removeNetdev(str);
  }

  drv.getNameNetdevs();

  return 0;
}

/* Entry point to C/C++ code. */
extern "C" int kernel_module_init(void) {
  return main();
}

