#include<iostream>
#include<fstream>
using namespace std;
#include "Shape.h"
#include<math.h>

float distance(Point p, int x, int y){
  double dx = x - p.xcoord;
  double dy = y - p.ycoord;
  return sqrt(dx*dx + dy*dy);
}


Shape::Shape(istream &is) {
  is >> color.red >> color.blue >> color.green;
  is >> position.xcoord >> position.ycoord;
}
