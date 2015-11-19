#ifndef _KEY_
#define _KEY_
#include "Rectangle.h"
#include <GLUT/glut.h>

class Key {
 public:
  bool used;
  bool pressed;
  Point position;
  Color color;
  int width;
  int border;
  const char* letter;
  Key();
  Key(const char* l);
  Key(Point p, const char* l);
  void draw(Color);
  //bool getPressed();
};

#endif
