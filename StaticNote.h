#ifndef _StaticNote_
#define _StaticNote_
#include "Circle.h"
#include "Rectangle.h"
using namespace std;
#include <GLUT/glut.h>

class StaticNote {
  bool used;
  Point CP;
  Point RP;
 public:
  StaticNote();
  void draw(int pos);
  void setSNColor(int pos, int acc);
  void notUsed(int pos);
};


#endif
