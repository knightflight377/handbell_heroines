#include<iostream>
#include<fstream>
#include<iomanip>
#include<sstream>
#include<vector>
#include<cmath>
#ifdef MACOSX
#include<GLUT/glut.h>
#else
#include <GLUT/glut.h>
#endif
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<sys/time.h>
#include"texture.h"
#include"Key.h"
#include"Shape.h"
#include"Circle.h"
#include"Rectangle.h"
#include"sound.h"
#include"Note.h"
#include"InitializeStartPositions.h"
#include"MusicalityMeter.h"
#include"InitializeKeyboard.h"
#include"StaticNote.h"
#include"initializeSound.h"
 #include"initNoteSelection.h"
using namespace std;


//INITIALIZED GLOBAL VARIABLES

//sound stuff
extern FMOD::Sound *C, *Db, *D, *Eb, *E, *F, *Gb, *G, *Ab, *A, *Bb, *B, *PofC, *PofCslow;

//note stuff
extern int Cxcoord, Dxcoord, Excoord, Fxcoord, Gxcoord, Axcoord, Bxcoord;
extern StaticNote test;

//user tells us what notes he/she wants to play
int notesSz, notePos;
int *noteChoices;
//ifstream initNoteFile("initNotes.txt");

//general game aspects
int rate = 50;
int keyWidth = 40;
int keyBorderWidth = 10;
double elapsedTime;
int counter;
double startTime;
bool mouseIsDragging = false;
int WIDTH = 1400;
int HEIGHT = 1000;
char programName[] = "Demo";
int jdep; //texture IDs

//arrays of notes (according to size) and their starting y coordinates
extern int Csz, Dbsz, Dsz, Ebsz, Esz, Fsz, Gbsz, Gsz, Absz, Asz, Bbsz, Bsz;
extern Note *Carray, *Dbarray, *Darray, *Ebarray, *Earray, *Farray, *Gbarray, *Garray, *Abarray, *Aarray, *Bbarray, *Barray;
extern int *Cstarts, *Dbstarts, *Dstarts, *Ebstarts, *Estarts, *Fstarts, *Gbstarts, *Gstarts, *Abstarts, *Astarts, *Bbstarts, *Bstarts;
extern float songSpeed;
extern int startPos;
int noteCounter = 0;

//keyboard stuff
extern Key KeyArray[7];
Color myColor(50,50,50);

//for musicality meter
MusicalityMeter MM; //musicality meter
bool accurate;


double getCurrentTime()
{
  struct timeval tv = {0,0};
  struct timezone tz;
  gettimeofday(&tv, &tz);
  return tv.tv_sec + tv.tv_usec/(double)1000000.;
}


void drawWindow()
{
  // clear the buffer
  glClear(GL_COLOR_BUFFER_BIT);
  //draw texture
  drawTexture(jdep, 0,0,  1400,925); //textID,  x,y  width,height
  //draw musicality meter
  MM.draw();

  //draw static notes and keyboard
  for (int i = 0; i < notesSz; i++){
    test.draw(noteChoices[i]);
    KeyArray[(noteChoices[i])].used = 1;}

  //draw moving notes
  for (int i = 0; i < notesSz; i++){
    if (noteChoices[i] == 0)
      for (int i = 0; i < Csz; i++)
	Carray[i].drawNote(Cxcoord, counter*songSpeed+ Cstarts[i], Carray[i]);

    if (noteChoices[i] == 1)
      for (int i = 0; i < Dsz; i++)
	Darray[i].drawNote(Dxcoord, counter*songSpeed+ Dstarts[i], Darray[i]);

    if (noteChoices[i] == 2)
      for (int i = 0; i < Esz; i++)
	Earray[i].drawNote(Excoord, counter*songSpeed+ Estarts[i], Earray[i]);

    if (noteChoices[i] == 3)
      for (int i = 0; i < Fsz; i++)
	Farray[i].drawNote(Fxcoord, counter*songSpeed+ Fstarts[i], Farray[i]);

    if (noteChoices[i] == 4)
      for (int i = 0; i < Gsz; i++)
	Garray[i].drawNote(Gxcoord, counter*songSpeed+ Gstarts[i], Garray[i]);

    if (noteChoices[i] == 5)
      for (int i = 0; i < Asz; i++)
	Aarray[i].drawNote(Axcoord, counter*songSpeed+ Astarts[i], Aarray[i]);

    if (noteChoices[i] == 6)
      for (int i = 0; i < Bsz; i++)
    Barray[i].drawNote(Bxcoord, counter*songSpeed+ Bstarts[i], Barray[i]);

    if (noteChoices[i] == 6)
      for (int i = 0; i < Bbsz; i++)
    Bbarray[i].drawNote(Bxcoord, counter*songSpeed+ Bbstarts[i], Bbarray[i]);
  }
  initKeyboard();
  glutSwapBuffers();

}

//when a key is hit, this function is called to check whether a note was in range
bool accuracy(Note* array, int* &starts, int sz)
{
  accurate = 0;
  for(int i = 0; i < sz; i++)
    {
      if (abs((array[i].position.ycoord) - 800) < 50 && array[i].hit==0){
    accurate = 1;
    array[i].hit = 1;
      }
    }
  return accurate;
}

//when a key moves below its hit range and has not been hit,
//this function sets the variable "hit" to -1 and updates the musicality meter
void checkNotHit(Note* array, int* starts, int sz){
  for (int i = 0; i < sz; i++){
    array[i].updateY(counter*songSpeed + starts[i]);
    if (array[i].position.ycoord  > 820 && array[i].hit == 0 ){
      array[i].hit = -1;
      MM.update(0); MM.draw();
    }
  }
}


// process keyboard events
void keyboard( unsigned char c, int x, int y )
{
  //if (screen == 1)
  {
    int win = glutGetWindow();
    switch(c) {

    case ' ': {
      //Hit the space bar when you want notes to be played in order to cout the starting positions of those notes.
      cout << 800 - counter*songSpeed /* elapsedTime */ << " ";
      noteCounter++;
      break;
    }
      if (KeyArray[0].used){
      case 'a':{
    //plays C
    if (KeyArray[0].used){
      if (USE_SOUND) playSound(C, 0);
      test.setSNColor(0,1);
      MM.update(accuracy(Carray, Cstarts, Csz)); MM.draw();
      KeyArray[0].draw(myColor);
    }
    break;
      }
      case 'q': {
    //plays Csharp (also known as Db)
    if (KeyArray[0].used){
      if (USE_SOUND) playSound(Db, 1);
      test.setSNColor(0,2);
      MM.update(accuracy(Dbarray, Dbstarts, Dbsz)); MM.draw();
    }
    break;
      }
      case 'z': {
    //plays B
    if (KeyArray[0].used){
      if (USE_SOUND) playSound(B, 2);
      test.setSNColor(0,0);
      MM.update(accuracy(Barray, Bstarts, Bsz)); MM.draw();
    }
    break;
      }

      case 's': {
    //plays D
    if (KeyArray[1].used){
      if (USE_SOUND) playSound(D, 3);
      MM.draw();
      test.setSNColor(1,1);
      MM.update(accuracy(Darray, Dstarts, Dsz)); MM.draw();

    }
    break;
      }
      case 'w': {
    //plays Eb
    if (KeyArray[1].used){
      if (USE_SOUND) playSound(Eb, 4);
      test.setSNColor(1,2);
      MM.update(accuracy(Ebarray, Ebstarts, Ebsz)); MM.draw();
    }
    break;
      }
      case 'x': {
    //plays Db
    if (KeyArray[1].used){
      if (USE_SOUND) playSound(Db, 5);
      test.setSNColor(1,0);
      MM.update(accuracy(Dbarray, Dbstarts, Dbsz)); MM.draw();
    }
    break;
      }

      case 'd': {
    //plays E
    if (KeyArray[2].used){
      if (USE_SOUND) playSound(E, 6);
      test.setSNColor(2,1);
      MM.update(accuracy(Earray, Estarts, Esz)); MM.draw();
    }
    break;
      }

      case 'e': {
    //plays F
    if (KeyArray[2].used){
      if (USE_SOUND) playSound(F, 7);
      test.setSNColor(2,2);
      MM.update(accuracy(Farray, Fstarts, Fsz)); MM.draw();
    }
    break;
      }
      case 'c': {
    //plays Eb
    if (KeyArray[2].used){
      if (USE_SOUND) playSound(Eb, 8);
      test.setSNColor(2,0);
      MM.update(accuracy(Ebarray, Ebstarts, Ebsz)); MM.draw();
    }
    break;
      }

      case 'f': {
    //plays Esharp (also known as F)
    if (KeyArray[3].used){
      if (USE_SOUND) playSound(F, 9);
      test.setSNColor(3,1);
      MM.update(accuracy(Farray, Fstarts, Fsz)); MM.draw();
    }
    break;
      }
      case 'r': {
    //plays Gb
    if (KeyArray[3].used){
      if (USE_SOUND) playSound(Gb, 10);
      test.setSNColor(3,2);
      MM.update(accuracy(Gbarray, Gbstarts, Gbsz)); MM.draw();
    }
    break;
      }
      case 'v': {
    //plays E
    if (KeyArray[3].used){
      if (USE_SOUND) playSound(E, 11);
      test.setSNColor(3,0);
      MM.update(accuracy(Earray, Estarts, Esz)); MM.draw();
    }
    break;
      }

      case 'j': {
    //plays G
    if (KeyArray[4].used){
      if (USE_SOUND) playSound(G, 12);
      test.setSNColor(4,1);
      MM.update(accuracy(Garray, Gstarts, Gsz)); MM.draw();
    }
    break;
      }
      case 'u': {
    //plays Ab
    if (KeyArray[4].used){
      if (USE_SOUND) playSound(Ab, 13);
      test.setSNColor(4,2);
      MM.update(accuracy(Abarray, Abstarts, Absz)); MM.draw();
    }
    break;
      }
      case 'm': {
    //plays Gb
    if (KeyArray[4].used){
      if (USE_SOUND) playSound(Gb, 14);
      test.setSNColor(4,0);
      MM.update(accuracy(Gbarray, Gbstarts, Gbsz)); MM.draw();
    }
    break;
      }

      case 'k': {
    //plays A
    if (KeyArray[5].used){
      if (USE_SOUND) playSound(A, 15);
      test.setSNColor(5,1);
      MM.update(accuracy(Aarray, Astarts, Asz)); MM.draw();
    }
    break;
      }
      case 'i': {
    //plays Bb
    if (KeyArray[5].used){
      if (USE_SOUND) playSound(Bb, 16);
      test.setSNColor(5,2);
      MM.update(accuracy(Bbarray, Bbstarts, Bbsz)); MM.draw();
    }
    break;
      }
      case ',': {
    //plays Ab
    if (KeyArray[5].used){
      if (USE_SOUND) playSound(Ab, 17);
      test.setSNColor(5,0);
      MM.update(accuracy(Abarray, Abstarts, Absz)); MM.draw();
    }
    break;
      }

      case 'l': {
    //plays B
    if (KeyArray[6].used){
      if (USE_SOUND) playSound(B, 18);
      test.setSNColor(6,1);
      MM.update(accuracy(Barray, Bstarts, Bsz)); MM.draw();
    }
    break;
      }
      case 'o': {
    //plays C
    if (KeyArray[6].used){
      if (USE_SOUND) playSound(C, 19);
      test.setSNColor(6,2);
      MM.update(accuracy(Carray, Cstarts, Csz)); MM.draw();
    }
    break;
      }
      case '.': {
    //plays Bb
    if (KeyArray[6].used){
      if (USE_SOUND) playSound(Bb, 20);
      test.setSNColor(6,0);
      MM.update(accuracy(Bbarray, Bbstarts, Bbsz)); MM.draw();
    }
    break;
      }

      case 27:{ // get rid of the window + turn off sound system
	cout << "Total notes: " << noteCounter;
	soundoff(); glutDestroyWindow(win); exit(0);
      }
	break;
      }
    }
    glutPostRedisplay();
  }
}

void idle(){

  elapsedTime = getCurrentTime() - startTime;
  if (elapsedTime*100 > counter)
    ++counter;

  if (counter >= 1000000)
    exit(0);
  glutPostRedisplay();

  if (KeyArray[0].used)
    checkNotHit(Carray, Cstarts, Csz);
  if (KeyArray[1].used){
    checkNotHit(Dbarray, Dbstarts, Dbsz);
    checkNotHit(Darray, Dstarts, Dsz);}
  if (KeyArray[2].used){
    checkNotHit(Ebarray, Ebstarts, Ebsz);
    checkNotHit(Earray, Estarts, Esz);}
  if (KeyArray[3].used)
    checkNotHit(Farray, Fstarts, Fsz);
  if (KeyArray[4].used){
    checkNotHit(Gbarray, Gbstarts, Gbsz);
    checkNotHit(Garray, Gstarts, Gsz);}
  if (KeyArray[5].used){
    checkNotHit(Abarray, Abstarts, Absz);
    checkNotHit(Aarray, Astarts, Asz);}
  if (KeyArray[6].used){
    checkNotHit(Bbarray, Bbstarts, Bbsz);
    checkNotHit(Barray, Bstarts, Bsz);}
}


// the init function sets up the graphics card to draw properly
void init(void)
{
  // clear the window to black
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  // set up the coordinate system:  number of pixels along x and y
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0., WIDTH-1, HEIGHT-1, 0., -1.0, 1.0);

  // allow blending (for transparent textures)
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_BLEND);
}

void init_gl_window()
{
  char *argv[] = { programName };
  int argc = sizeof(argv) / sizeof(argv[0]);
  glutInit(&argc, argv);
  glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
  glutInitWindowSize(WIDTH,HEIGHT);
  glutInitWindowPosition(100,100);
  glutCreateWindow(programName);
  init();

  jdep = loadTexture("johnnydepp.pam");
  glutDisplayFunc(drawWindow);
  glutKeyboardFunc(keyboard);
  glutIdleFunc(idle);
  glutMainLoop();
}

int main()
{
  cout << "Please enter how many bells you would like to play (between 1 and 7): " << endl;
  cin >> notesSz;
  if (notesSz < 0 || notesSz > 7)
    cout << "Woah, easy tiger! Choose a number between 1 and 7." << endl;
  noteChoices = new int[notesSz];
  for (int i = 0; i < notesSz; ++i) {
    cout << "Enter your bell selection (between 0 and 7): ";
    cin >> notePos;
    noteChoices[i] = notePos;
  }
  char c;
  cout << "Ready to play the game? (y/n)" << endl;
  cin >> c;
  if (c=='y'){
    initStartPositions();
    startTime = getCurrentTime();
    init_sound_system();
    init_sound();
    if (USE_SOUND) playSound(PofC,7);
    init_gl_window();  }
  else
    cout << "Your loss." << endl;
  delete [] noteChoices;

}
