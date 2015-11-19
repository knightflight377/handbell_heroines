#ifndef _Note_Array_
#define _Note_Array_


//THIS CLASS IS NOT USED

class Note;
class NoteArray{

  //STATE VARIABLES
  Note* elt;
  int size;

  //CLASS VARIABLES
  static const unsigned int DEFAULT_SIZE = 1;

public:
  //CONSTRUCTORS
  NoteArray(unsigned int sz);
  NoteArray();
  NoteArray(const NoteArray &n);
  ~NoteArray();

  //METHODS
  int getSize();
  void draw();
  Note& operator [] (int i);

};

#endif
