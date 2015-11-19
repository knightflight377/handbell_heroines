#include <iostream>
#include "Note.h"
#include "NoteArray.h"
using namespace std;

NoteArray::NoteArray(unsigned int sz){
  elt = 0;
  if (sz > 0)
    elt = new Note[sz];
  size = sz;
}

NoteArray::NoteArray(){

  elt = new Note[DEFAULT_SIZE];
  size = DEFAULT_SIZE;
}

NoteArray::NoteArray(const NoteArray &n){
  elt = 0;
  size = n.size;
  if(size > 0)
    elt = new Note[size];
}


NoteArray::~NoteArray(){
  delete[] elt;
}

int NoteArray::getSize(){
  return size;
}

void NoteArray::draw(){
  for(int j=0; j < size; j++)  
    elt[j].draw();
}

Note &NoteArray::operator[](int i){
  if (i<0){
    cout << "WARNING! i < 0" << i << endl;
    return elt[0];
  }
  else if (i < size-1){
    return elt[i];
  }
  else{
    return elt[size-1];
    cout << "WARNING! i > size of array" << i << endl;
  }
}
