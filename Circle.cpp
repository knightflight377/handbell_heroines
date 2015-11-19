#include<iostream>
using namespace std;
#include<fstream>
#include "Circle.h"
#include <GLUT/glut.h>
#include<math.h>

Circle::Circle(Point p, int r) {
  position.xcoord = p.xcoord;
  position.ycoord = p.ycoord;
  radius = r;
}

Circle::Circle(istream &is) {
  is >> color.red >> color.green >> color.blue;
  is >> position.xcoord >> position.ycoord;
  is >> radius;
}

void Circle::display() {
  cout << "Circle ";
  Shape::display();
  cout << "  " << radius << endl;
}

void Circle::draw() {
  sendGLColor();
  const int NUM_DIVS = 50;
  glBegin(GL_TRIANGLE_FAN);
  glVertex2d(position.xcoord, position.ycoord);
  for ( int i = 0; i < NUM_DIVS; ++i )
    glVertex2d(position.xcoord + radius*cos(i*2*M_PI/(NUM_DIVS-1)),
	       position.ycoord + radius*sin(i*2*M_PI/(NUM_DIVS-1)));
  glEnd();
}

bool Circle::containsPoint(int x, int y) {
  if (distance(position,x,y) <= radius) 
    return true;
  else
    return false;
}
