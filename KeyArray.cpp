#include <iostream>
#include "Key.h"
#include "KeyArray.h"
using namespace std;

KeyArray::KeyArray(){
  Key elt[DEFAULT_SIZE];
  size = DEFAULT_SIZE;
}

KeyArray::KeyArray(unsigned int sz){
  if (sz > 0)
    Key elt[sz];
  size = sz;
}

KeyArray::KeyArray(const KeyArray &k){
  elt = 0;
  size = k.size;
  if(size > 0)
    Key elt[size];
}

void KeyArray::draw(){
  for (int i = 0; i < 7; ++i){
    Point p = Point(110*i + 225, 900);
    const char* L;
    if (i == 0) L = "A";
    if (i == 1) L = "S";
    if (i == 2) L = "D";
    if (i == 3) L = "F";
    if (i == 4) L = "J";
    if (i == 5) L = "K";
    if (i == 6) L = "L";
    cout << L << endl;
    Key a;
    elt[1] = a;
    if (elt[i] == 0){}
    else
      elt[i].draw();
  }
}

Key &KeyArray::operator[](int i){
  if (i<0){
    cout << "WARNING1" << i << endl;
    return elt[0];
  }
  else if (i < size-1){
    return elt[i];
    cout << "hello" << endl;
  }
  else{
    return elt[size-1];
    cout << "WARNING2" << i << endl;
  }
}
