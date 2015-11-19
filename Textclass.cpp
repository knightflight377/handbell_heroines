#include <iostream>
#include <fstream>
using namespace std;
#ifdef MACOSX
#include <GLUT/glut.h>
#else
#endif
#include <string.h>
#include <stdlib.h>
#include <ColorPoint2.h>
#include <Text.h>

//This file is no longer used for the text class. Use Text.cpp instead.

//Text::Text(Point p, const char *ch, int s, Color c) {
    size = s;
    location.xcoord = p.xcoord;
    location.ycoord = p.ycoord;

    for(size = 0; c[size] !='\0'; ++size){}
    words = new char[size+1];

    red = c.red;
    green = c.green;
    blue = c.blue;

    return *this;
  }

//void Text::drawText(float x, float y, const char *text, Color c){

    glRasterPos2f(x,y);
    int len = strlen(text);
    for (int i = 0; i < length; i++)
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    red = c.red;
    green = c.green;
    blue = c.blue;
    glColor3f(red, green, blue);
  }




