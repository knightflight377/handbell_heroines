#ifndef _NOTE_
#define _NOTE_
#include "Circle.h"
using namespace std;
#include <GLUT/glut.h>

class Note: public Circle {
 public:
  int name;
  int accidental;
  int hit;
  Note();
  Note(Point p, int r, int n, int a);
  void updateY(int y);
  void drawNote(double x, double y, Note& c);
};
#endif
