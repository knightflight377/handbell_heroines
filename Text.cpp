#include <iostream>
#include <fstream>
#include<iomanip>
using namespace std;
#ifdef MACOSX
#include<GLUT/glut.h>
#else
#include <GLUT/glut.h>
#endif
#include <string.h>
#include <stdlib.h>
#include "Text.h"
#include "ColorPoint2.h"

Color testColor(152,60,63);

void sendGLColor() {glColor3f(testColor.red/255., testColor.green/255., testColor.blue/255.);}

void drawText(double x, double y, const char *text){
  glRasterPos2f(x,y);
  sendGLColor();
  //  glColor3f(0.5, 0.80, 0.5);
  int length = strlen(text);
  for (int i = 0; i < length; ++i)
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}





