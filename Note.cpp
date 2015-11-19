#include<iostream>
using namespace std;
#include<fstream>
#include "Note.h"
#include <GLUT/glut.h>
#include<math.h>

Color noteColor(152,60,63);
int firstXcoord = 250;
int spacing = 110;
int Cxcoord = firstXcoord;
int Dxcoord = firstXcoord+spacing*1;
int Excoord = firstXcoord+spacing*2;
int Fxcoord = firstXcoord+spacing*3;
int Gxcoord = firstXcoord+spacing*4;
int Axcoord = firstXcoord+spacing*5;
int Bxcoord = firstXcoord+spacing*6;

Note::Note() {
  name = 0; accidental = 0; hit = 0;
}

Note::Note(Point p, int r, int n, int a) {
  position = p; radius = r; name = n; accidental = a; hit = 0;
}

void Note::updateY(int y){
  position.ycoord = y;
  //cout << position.ycoord << endl;
}
		     
void Note::drawNote(double x, double y, Note &c){
  c.position.xcoord = x;
  c.position.ycoord = y;
  //  c.setColor(noteColor);
  c.draw();
}
