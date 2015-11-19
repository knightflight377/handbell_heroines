#ifndef _SHAPE_
#define _SHAPE_
#include "ColorPoint2.h"
#include <iostream>
using namespace std;
#include <GLUT/glut.h>
#include <math.h>

class Shape {
public:
  Color color;
  Point position;
  Shape() {}
  Shape(Point p) {position = p;}
  Shape(istream &is);
  Color getColor() {return color;}
  Point getPosition(){return position;}
  void setColor(Color c) {color = c;}
  void setPosition(int x, int y) {position.xcoord = x; position.ycoord = y;}
  virtual void display(){color.display(); cout << "  "; position.display();}
  void sendGLColor() {glColor3f(color.red/255., color.green/255., color.blue/255.);}
  virtual void draw() =0;
  virtual void update(int x, int y) =0;
  virtual bool containsPoint(int x, int y) =0;
};

float distance(Point p, int x, int y);

#endif //_SHAPE_
