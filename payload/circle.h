#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "shape.h"
#include <iostream>

using namespace std;

class Circle : public Shape {
  int r;
public:
  Circle(int radius) { 
    r = radius;
    cout << "! " << __PRETTY_FUNCTION__ << endl; 
  }

 ~Circle() { cout << "! " << __PRETTY_FUNCTION__ << endl; }

  virtual void getShape() {
    cout << "! " << "It is a circle with radius: " << r << endl;
  }
};

#endif /* __CIRCLE_H__ */

