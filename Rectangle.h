#ifndef _RECTANGLE_
#define _RECTANGLE_
#include "Shape.h"
#include <GLUT/glut.h>

class Rectangle: public Shape {
  int width, height;
public:
  Rectangle() {width = 50; height = 40;}
  Rectangle(Point p, int w, int h);
  Rectangle(istream &is);
  void display();
  void draw();
  void update(int x, int y) {width = x - position.xcoord; height = y - position.ycoord;}
  bool containsPoint(int x, int y);
};

#endif
