#ifndef _CIRCLE_
#define _CIRCLE_
#include "Shape.h"
using namespace std;
#include <GLUT/glut.h>

class Circle: public Shape{
 public:
  int radius;
  Circle(){radius = 40;}
  Circle(Point p, int r);
  Circle(istream&is);
  void display();
  void draw();
  void update(int x, int y) {radius = distance(position,x,y);}
  bool containsPoint(int x, int y);
};

#endif
