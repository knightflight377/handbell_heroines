#include<iostream>
#include"Key.h"
#include "Text.h"
using namespace std;

Key KeyArray[7];
Color colorColor(100,100,100);

void initKeyboard()
{
  for (int i = 0; i < 7; ++i){
    Point p = Point(110*i + 225, 900);
    const char* L;
    if(KeyArray[i].used){
      if (i == 0) L = "A"; 
      if (i == 1) L = "S";
      if (i == 2) L = "D";
      if (i == 3) L = "F";
      if (i == 4) L = "J";
      if (i == 5) L = "K";
      if (i == 6) L = "L";
      Key k(p, L);
      k.draw(colorColor);
      sendGLColor();
      drawText(p.xcoord+20, p.ycoord+30, L);
    }
  }
}
