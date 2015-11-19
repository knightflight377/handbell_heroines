#ifndef _ColorPoint2_
#define _ColorPoint2_
using namespace std;

class Color {
 public:
  int red, green, blue;
  Color();
  Color(int r, int g, int b);
  void display();
};

class Point {
 public:
  int xcoord, ycoord;
  Point();
  Point(int x, int y);
  void display();
};

#endif //_ColorPoint2_
