#ifndef __SHAPE_H__
#define __SHAPE_H__

#include <iostream>
using namespace std;

void shape();

class Shape {
public:
  Shape() { cout << "! " << __PRETTY_FUNCTION__ << endl; }
 ~Shape() { cout << "! " << __PRETTY_FUNCTION__ << endl; }

  virtual void getShape() = 0;
};

#endif /* __SHAPE_H__ */

