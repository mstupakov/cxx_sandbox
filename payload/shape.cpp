#include "shape.h"
#include "circle.h"
#include "box.h"

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

void shape() {
  vector<Shape*> vec_shapes;

  vec_shapes.push_back(new Box(10, 20));
  vec_shapes.push_back(new Circle(15));
  vec_shapes.push_back(new Box(20, 20));
  vec_shapes.push_back(new Box(30, 20));
  vec_shapes.push_back(new Circle(20));
  vec_shapes.push_back(new Box(30, 20));
 
  cout << "! Lets iterate over vector: " << endl;
  for (vector<Shape*>::iterator it = vec_shapes.begin(); it != vec_shapes.end(); ++it) {
    (*it)->getShape();
  }
}
