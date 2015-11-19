# this Makefile is intended to make any of the examples in this directory
#all:  proto-texture proto-ui proto-ui2 proto-counting proto-windows proto-sound proto-chat proto-multiplayer

# the following lines pertain to using sound
# if you download FMOD onto your own machine, change the line below
FMOD_DIR = ./fmod
FMOD_INCLUDE = -I$(FMOD_DIR)/api/inc -I$(FMOD_DIR)/examples/common
FMOD_LIB = $(FMOD_DIR)/api/lib/libfmodex.dylib

# the following lines pertain to setting up compiler options and libraries
CC = clang++
OPTS = -Wall -g -std=c++11 -Wno-deprecated-declarations -Wno-unused-private-field
LIBS = -lGL -lglut -lm
ARCH := $(shell uname)
ifeq ($(ARCH), Linux)
else
	MACOSX_DEFINE = -DMACOSX -I/sw/include
	LIBS = -I/usr/common/include -I/usr/include/GL -L/System/Library/Frameworks/OpenGL.framework/Libraries -framework GLUT -framework OpenGL -lGL -lm -lobjc -lstdc++
endif

Demo: Demo.o texture.o Rectangle.o Circle.o Shape.o ColorPoint2.o Key.o InitializeKeyboard.o MusicalityMeter.o sound.o Note.o StaticNote.o initializeSound.o Text.o NoteArray.o InitializeStartPositions.o initNoteSelection.o network.o
	install_name_tool -id ./libfmodex.dylib ./libfmodex.dylib
	export DYLD_LIBRARY_PATH=$DYLD_LIBRARY_PATH:$(FMOD_DIR)/api/lib
	$(CC) $(OPTS) -o Demo $^ $(LIBS) $(FMOD_LIB) -pthread

Demo.o: Demo.cpp
	$(CC) $(OPTS) $(FMOD_INCLUDE)  $(MACOSX_DEFINE) -c Demo.cpp

InitializeKeyboard.o: InitializeKeyboard.cpp Key.h Rectangle.h Shape.h ColorPoint2.h Text.h
	$(CC) -g -Wall -std=c++11 -c InitializeKeyboard.cpp

initializeSound.o: initializeSound.cpp sound.h
	$(CC) $(OPTS) $(FMOD_INCLUDE) -c initializeSound.cpp

initNoteSelection.o: initNoteSelection.cpp StaticNote.h InitializeKeyboard.h Key.h InitializeStartPositions.h KeyArray.h NoteArray.h Note.h
	$(CC) -g -Wall -std=c++11 -c initNoteSelection.cpp

texture.o: texture.cpp texture.h
	$(CC) $(OPTS) $(MACOSX_DEFINE) -c texture.cpp

Note.o: Note.cpp Circle.h Shape.h ColorPoint2.h
	$(CC) -g -Wall -std=c++11 -c Note.cpp

NoteArray.o: NoteArray.cpp Note.h Circle.h Shape.h ColorPoint2.h
	$(CC) -g -Wall -std=c++11 -c NoteArray.cpp

InitializeStartPositions.o: InitializeStartPositions.cpp NoteArray.h Note.h
	$(CC) -g -Wall -std=c++11 -c InitializeStartPositions.cpp

StaticNote.o: StaticNote.cpp Circle.h Rectangle.h Shape.h ColorPoint2.h
	$(CC) -g -Wall -std=c++11 -c StaticNote.cpp

Key.o: Key.cpp Rectangle.h Shape.h ColorPoint2.h
	$(CC) -g -Wall -std=c++11 -c Key.cpp

MusicalityMeter.o: MusicalityMeter.cpp Rectangle.h ColorPoint2.h Text.h
	$(CC) -g -Wall -std=c++11 -c MusicalityMeter.cpp

Rectangle.o: Rectangle.cpp Shape.h ColorPoint2.h
	$(CC) -g -Wall -std=c++11 -c Rectangle.cpp 

Circle.o: Circle.cpp Shape.h ColorPoint2.h
	$(CC) -g -Wall -std=c++11 -c Circle.cpp 

Shape.o: Shape.cpp ColorPoint2.h
	$(CC) -g -Wall -std=c++11 -c Shape.cpp

ColorPoint2.o: ColorPoint2.cpp 
	$(CC) -g -Wall -std=c++11 -c ColorPoint2.cpp

sound.o: sound.cpp sound.h
	$(CC) $(OPTS) $(FMOD_INCLUDE) -c sound.cpp

Text.o: Text.cpp ColorPoint2.h
	$(CC) $(OPTS) $(FMOD_INCLUDE)  $(MACOSX_DEFINE) -c Text.cpp

network.o: network.cpp network.h
	$(CC) $(OPTS) -c network.cpp

clean:
	rm -rf *.o Demo
