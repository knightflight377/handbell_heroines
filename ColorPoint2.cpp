#include<iostream>
using namespace std;
#include "ColorPoint2.h"

//CONSTRUCTOR/METHOD DEFINITIONS
Color::Color() {
  red = 152;
  green = 60;
  blue = 63;
}

Color::Color (int r, int g, int b) {
  red = r;
  green = g;
  blue = b;
}

void Color::display() {
  cout << red << " " << green << " " << blue << " ";
}

Point::Point() {
  xcoord = 50;
  ycoord = 100;
}

Point::Point(int x, int y) {
  xcoord = x;
  ycoord = y;
}

void Point::display() {
  cout << xcoord << " " << ycoord << " ";
}


