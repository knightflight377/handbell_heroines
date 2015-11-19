#ifndef _MusicalityMeter_
#define _MusicalityMeter_
#include "ColorPoint2.h"
#include <iostream>
using namespace std;
#include <GLUT/glut.h>

class MusicalityMeter {
 public:
  int health;
  MusicalityMeter();
  void update(bool n);
  void draw();
};

#endif
