#include<iostream>
using namespace std;
#include "KeyArray.h"
#ifdef MACOSX
#include<GLUT/glut.h>
#else
#include <GLUT/glut.h>
#endif

Color colorC(100,100,100);

Key::Key()
{
  used = 0;
  Point p(100,100); 
  Color color(100,100,100);
  position = p;
  width = 40;
  border = 10;
  letter = "A";
}

Key::Key(const char* l)
{
  used = 0;
  Point p(100,100); 
  Color color(100,100,100);
  position = p;
  width = 40;
  border = 10;
  letter = l;
}

Key::Key(Point p, const char* l)
{
  used = 1;
  position = p;
  Color color(100,100,100);
  width = 50;
  border = 20;
  letter = l;
}

void Key::draw(Color c)
{
  Point p2(position.xcoord - border/2, position.ycoord - border/2);
  Rectangle keyBackground(p2, width+border, width+border);
  keyBackground.color.red = c.red;
  keyBackground.color.green = c.green;
  keyBackground.color.blue = c.blue;
  Rectangle keyForeground(position, width, width);
  keyForeground.color.red = c.red+50;
  keyForeground.color.green = c.green+50;
  keyForeground.color.blue = c.blue+50;
  if (used){
    keyBackground.draw();
    keyForeground.draw();
  }

  // cout << keyBackground.color.red << endl;

}

