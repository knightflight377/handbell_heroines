#ifndef _KEY_ARRAY_H
#define _KEY_ARRAY_H
#include "Key.h"

//THIS CLASS IS NOT USED

class Key;
class KeyArray{

  //STATE VARIABLES
  Key* elt;
  int size;

  //CLASS VARIABLES
  static const unsigned int DEFAULT_SIZE = 7;

public:
  //CONSTRUCTORS
  KeyArray(unsigned int sz);
  KeyArray();
  KeyArray(const KeyArray &k);

  //METHODS
  Key& operator [] (int i);
  void draw();
};

#endif
