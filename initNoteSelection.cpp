#include<iostream>
#include<fstream>
using namespace std;
#include "initNoteSelection.h"
#include "StaticNote.h"
#include "InitializeKeyboard.h"
#include "Key.h"
#include "InitializeStartPositions.h"
#include "KeyArray.h"
#include "NoteArray.h"
#include "Note.h"

/*int notesSz;
int *noteChoices;
int notePos; */
//NoteArray Carray, Dbarray, Darray, Ebarray, Earray, Farray, Gbarray, Garray, Abarray, Aarray, Bbarray, Barray;

extern StaticNote test;
extern Key KeyArray;
extern int *Cstarts, *Dbstarts, *Dstarts, *Ebstarts, *Estarts, *Fstarts, *Gbstarts, *Gstarts, *Abstarts, *Astarts, *Bbstarts, *Bstarts;
extern int Csz, Dbsz, Dsz, Ebsz, Esz, Fsz, Gbsz, Gsz, Absz, Asz, Bbsz, Bsz;
extern int startPos;
extern int firstXcoord, Cxcoord, Dxcoord, Excoord, Fxcoord, Gxcoord, Axcoord, Bxcoord, spacing;


void initNoteSelection() {


  /*  ifstream initNoteFile("initNotes.txt");
  for (notesSz = 0; notesSz != '/0'; ++notesSz);

  noteChoices = new int[notesSz];

  for (int i = 0; i < notesSz; i++){
    initNoteFile >> notePos;
    noteChoices[i] = notePos;} */
  /*
  for (int i = 0; i < notesSz; i++){
  test.draw(noteChoices[i]);} */
    //    KeyArray[(noteChoices[i])].used = 1;}

	/*	if (notePos == 0)
		for (int i = 0; i < Csz; i++){
			Carray[i].drawNote(Cxcoord, counter*songSpeed+ Cstarts[i], Carray[i]);
			//cout << Cstarts[i] << endl;
		}
		
	if (notePos == 1)
		for (int i = 0; i < Dsz; i++)
			Darray[i].drawNote(Dxcoord, counter*songSpeed+ Dstarts[i], Darray[i]);
		
	if (notePos == 2)
		for (int i = 0; i < Esz; i++)
			Earray[i].drawNote(Excoord, counter*songSpeed+ Estarts[i], Earray[i]);
			
	if (notePos == 3)
		for (int i = 0; i < Fsz; i++)
			Farray[i].drawNote(Fxcoord, counter*songSpeed+ Fstarts[i], Farray[i]);
			
	if (notePos == 4)
		for (int i = 0; i < Gsz; i++)
			Garray[i].drawNote(Gxcoord, counter*songSpeed+ Gstarts[i], Garray[i]);
			
	if (notePos == 5)
		for (int i = 0; i < Asz; i++)
			Aarray[i].drawNote(Axcoord, counter*songSpeed+ Astarts[i], Aarray[i]);
			
	if (notePos ==6)
		for (int i = 0; i < Bsz; i++)
		Barray[i].drawNote(Bxcoord, counter*songSpeed+ Bstarts[i], Barray[i]);*/ 
	// }
	
}


