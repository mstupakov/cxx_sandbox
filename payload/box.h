#ifndef __BOX_H__
#define __BOX_H__

#include "shape.h"
#include <iostream>

using namespace std;

class Box : public Shape {
  int w;
  int h;
public:
  Box(int width, int height) : w(width), h(height) { 
    cout << "! " << __PRETTY_FUNCTION__ << endl; 
  }
 
 ~Box() { cout << "! " << __PRETTY_FUNCTION__ << endl; }

  virtual void getShape() {
    cout << "! " << "It is a box with W: " << w << " H: " << h << endl;
  };
};

#endif /* __BOX_H__ */

