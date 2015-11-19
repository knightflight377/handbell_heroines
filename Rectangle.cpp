#include<iostream>
#include<fstream>
using namespace std;
#include "Rectangle.h"
#include <GLUT/glut.h>


Rectangle::Rectangle(Point p, int w, int h) {
  width = w; height = h;
  position.xcoord = p.xcoord;
  position.ycoord = p.ycoord;
}

Rectangle::Rectangle(istream &is) {
  is >> color.red >> color.green >> color.blue;
  is >> position.xcoord >> position.ycoord;
  is >> width >> height;
}

void Rectangle::display(){
  cout <<"Rectangle ";
  Shape::display();
  cout << "  " << width << " " << height << " " << endl;
}

void Rectangle::draw() {
  sendGLColor();
  double x0 = min(position.xcoord, position.xcoord + width);
  double x1 = max(position.xcoord, position.xcoord + width);
  double y0 = min(position.ycoord, position.ycoord + height);
  double y1 = max(position.ycoord, position.ycoord + height);
  glBegin(GL_QUADS);
    glVertex2d(x0, y0);
    glVertex2d(x1, y0);
    glVertex2d(x1, y1);
    glVertex2d(x0, y1);
  glEnd();
}

bool Rectangle::containsPoint(int x, int y) {
  if (position.xcoord <= x && x<= position.xcoord + width) {
    if (position.ycoord <= y && y <= position.ycoord + height)
      return true;
    else
      return false;
  }
  else
    return false;
}
