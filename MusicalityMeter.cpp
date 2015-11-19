#include"MusicalityMeter.h"
#include"Rectangle.h"
#include"Text.h"
#include<iostream>
using namespace std;

int win = glutGetWindow();
int notesHit = 1;
int notesAppeared = 1;

//Point MMText(30, 350);
Point MMPosition(30,400);
Rectangle MMBackground(MMPosition, 150, 400);
Color MMBackgroundColor(255,250,250);

MusicalityMeter::MusicalityMeter()
{
  health = 70;
}

void MusicalityMeter::update(bool n) {
  if (n == 0 && health > 1){
    ++notesAppeared;
    health = 100*notesHit/notesAppeared;

  }
  if (n == 1){
    ++notesHit;
    ++notesAppeared;
    health = 100*notesHit/notesAppeared;
  }

  if (health < 5){
    cout << "YOU DIED." << endl;
    glutDestroyWindow(win); exit(0);
  }
}

void MusicalityMeter::draw()
{
  // sendGLColor();
  drawText(40,375, "Musicality Meter");
  Point HealthPosition(30,800 - health*4);
  Rectangle MMHealth(HealthPosition, 150, health*4);
  Color MMColor(155,48,255);
  if (health >= 85)
    MMColor = Color(155,48,255);
  if (health >= 70 && health < 85)
    MMColor = Color(0,0,255);
  if (health >= 55 && health < 70)
    MMColor = Color(0,255,0);
  if (health >= 40 && health < 55)
    MMColor = Color(255,255,0);
  if (health >= 25 && health < 40)
    MMColor = Color(255,165,0);
  if (health < 25){
    MMColor = Color(255,0,0);
  }

  MMBackground.setColor(MMBackgroundColor);
  MMHealth.setColor(MMColor);
  MMBackground.draw();
  MMHealth.draw();
}
