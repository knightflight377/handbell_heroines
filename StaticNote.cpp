#include<iostream>
using namespace std;
#include "StaticNote.h"
#include <GLUT/glut.h>
#include <math.h>

const int numNotes = 7;
int noteRadius = 40;
int stemWidth = 10;
Circle StaticNoteArray[numNotes];
Rectangle StaticNoteStemArray[numNotes];
Color StaticNoteColor(3,44,42);
Color StaticSharpColor(94,51,52);
Color StaticFlatColor(42,105,79);
Color StaticNotUsedColor(0,0,0);
StaticNote test;

StaticNote::StaticNote() {
  for (int i = 0; i < numNotes; ++i){
    CP = Point(110*i + 250, 800);
    StaticNoteArray[i] = Circle(CP, noteRadius); 
    StaticNoteArray[i].setColor(StaticNoteColor);
  }
  for (int i = 0; i < numNotes; ++i){
    RP = Point(110*i + 250 + noteRadius - stemWidth, 0);
    StaticNoteStemArray[i] = Rectangle(RP, stemWidth, 800);
    StaticNoteStemArray[i].setColor(StaticNoteColor);
  }
}

void StaticNote::draw(int pos) {
  StaticNoteArray[pos].draw();
  StaticNoteStemArray[pos].draw();
}

void StaticNote::setSNColor(int pos, int acc) {
   if (acc == 0){
    StaticNoteArray[pos].setColor(StaticFlatColor);
    StaticNoteArray[pos].draw();

    StaticNoteStemArray[pos].setColor(StaticFlatColor);
    StaticNoteStemArray[pos].draw();
  }

  if (acc == 1){
    StaticNoteArray[pos].setColor(StaticNoteColor);
    StaticNoteArray[pos].draw();

    StaticNoteStemArray[pos].setColor(StaticNoteColor);
    StaticNoteStemArray[pos].draw();
  }
  else if (acc == 2){
    StaticNoteArray[pos].setColor(StaticSharpColor);
    StaticNoteArray[pos].draw();

    StaticNoteStemArray[pos].setColor(StaticSharpColor);
    StaticNoteStemArray[pos].draw();
  }
}

void StaticNote::notUsed(int pos) {
    StaticNoteArray[pos].setColor(StaticNotUsedColor);
    StaticNoteArray[pos].draw();

    StaticNoteStemArray[pos].setColor(StaticNotUsedColor);
    StaticNoteStemArray[pos].draw();
	
	
}

