#include<iostream>
#include<fstream>
#include"Note.h"

using namespace std;
Note *Carray, *Dbarray, *Darray, *Ebarray, *Earray, *Farray, *Gbarray, *Garray, *Abarray, *Aarray, *Bbarray, *Barray;
int *Cstarts, *Dbstarts, *Dstarts, *Ebstarts, *Estarts, *Fstarts, *Gbstarts, *Gstarts, *Abstarts, *Astarts, *Bbstarts, *Bstarts;
int Csz, Dbsz, Dsz, Ebsz, Esz, Fsz, Gbsz, Gsz, Absz, Asz, Bbsz, Bsz;
int startPos;
// float songSpeed;
int offset = 200;
float songSpeed = 4.2;

void initStartPositions()
{
  ifstream fileC("Cnotes.txt");
  ifstream fileDb("Dbnotes.txt");
  ifstream fileD("Dnotes.txt");
  ifstream fileEb("Ebnotes.txt");
  ifstream fileE("Enotes.txt");
  ifstream fileF("Fnotes.txt");
  ifstream fileGb("Gbnotes.txt");
  ifstream fileG("Gnotes.txt");
  ifstream fileAb("Abnotes.txt");
  ifstream fileA("Anotes.txt");
  ifstream fileBb("Bbnotes.txt");
  ifstream fileB("Bnotes.txt");

  fileC >> Csz;
  fileDb >> Dbsz;
  fileD >> Dsz;
  fileEb >> Ebsz;
  fileE >> Esz;
  fileF >> Fsz;
  fileGb >> Gbsz;
  fileG >> Gsz;
  fileAb >> Absz;
  fileA >> Asz;
  fileBb >> Bbsz;
  fileB >> Bsz;

  Carray = new Note[Csz];
  Dbarray = new Note[Dbsz];
  Darray = new Note[Dsz];
  Ebarray = new Note[Ebsz];
  Earray = new Note[Esz];
  Farray = new Note[Fsz];
  Gbarray = new Note[Gbsz];
  Garray = new Note[Gsz];
  Abarray = new Note[Absz];
  Aarray = new Note[Asz];
  Bbarray = new Note[Bbsz];
  Barray = new Note[Bsz];

  Cstarts = new int[Csz];
  Dbstarts = new int[Dbsz];
  Dstarts = new int[Dsz];
  Ebstarts = new int[Ebsz];
  Estarts = new int[Esz];
  Fstarts = new int[Fsz];
  Gbstarts = new int[Gbsz];
  Gstarts = new int[Gsz];
  Abstarts = new int[Absz];
  Astarts = new int[Asz];
  Bbstarts = new int[Bbsz];
  Bstarts = new int[Bsz];

  for (int i = 0; i < Csz; i++){
    fileC >> startPos;
    Cstarts[i] = startPos + offset;
  }

  for (int i = 0; i < Dbsz; i++){
    fileDb >> startPos;
    Dbstarts[i] = startPos + offset;
  }

  for (int i = 0; i < Dsz; i++){
    fileD >> startPos;
    Dstarts[i] = startPos + offset;
  }

  for (int i = 0; i < Ebsz; i++){
    fileEb >> startPos;
    Ebstarts[i] = startPos + offset;
  }

  for (int i = 0; i < Esz; i++){
    fileE >> startPos;
    Estarts[i] = startPos + offset;
  }

  for (int i = 0; i < Fsz; i++){
    fileF >> startPos;
    Fstarts[i] = startPos + offset;
  }

  for (int i = 0; i < Gbsz; i++){
    fileGb >> startPos;
    Gbstarts[i] = startPos + offset;
  }

  for (int i = 0; i < Gsz; i++){
    fileG >> startPos;
    Gstarts[i] = startPos + offset;
  }

  for (int i = 0; i < Absz; i++){
    fileAb >> startPos;
    Abstarts[i] = startPos + offset;
  }

  for (int i = 0; i < Asz; i++){
    fileA >> startPos;
    Astarts[i] = startPos + offset;
  }


  for (int i = 0; i < Bbsz; i++){
    fileBb >> startPos;
    Bbstarts[i] = startPos + offset;
  }

  for (int i = 0; i < Bsz; i++){
    fileB >> startPos;
    Bstarts[i] = startPos + offset;
  }

}
