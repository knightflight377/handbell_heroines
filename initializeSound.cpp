#include<iostream>
#include "initializeSound.h"
#include "sound.h"

FMOD::Sound *C;
FMOD::Sound *Db;
FMOD::Sound *D;
FMOD::Sound *Eb;
FMOD::Sound *E;
FMOD::Sound *F;
FMOD::Sound *Gb;
FMOD::Sound *G;
FMOD::Sound *Ab;
FMOD::Sound *A;
FMOD::Sound *Bb;
FMOD::Sound *B;
FMOD::Sound *PofC;

void init_sound()
{
  C = loadSoundFile("C.wav");
  Db = loadSoundFile("Db.wav");
  D = loadSoundFile("D.wav");
  Eb = loadSoundFile("Eb.wav");
  E = loadSoundFile("E.wav");
  F = loadSoundFile("F.wav");
  Gb = loadSoundFile("Gb.wav");
  G = loadSoundFile("G.wav");
  Ab = loadSoundFile("Ab.wav");
  A = loadSoundFile("A.wav");
  Bb = loadSoundFile("Bb.wav");
  B = loadSoundFile("B.wav");
  PofC = loadSoundFile("PofC.wav");
}
