#vardefs
CC=g++

SRCPATH=src

SOURCES=$(SRCPATH)/main.cpp $(SRCPATH)/Note.cpp $(SRCPATH)/XMLParse.cpp

HEADERS=$(SRCPATH)/Note.h $(SRCPATH)/XMLParse.h

EXECUTABLE=noteTag

#recipes

all:
	$(CC) $(HEADERS) $(SOURCES) -o $(EXECUTABLE)

clean:
	@rm -rf *o *exe *gch
