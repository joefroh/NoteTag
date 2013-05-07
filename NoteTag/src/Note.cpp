/*
 * Note.cpp
 *
 *  Created on: May 7, 2013
 *      Author: Joey
 */

#include "Note.h"

void Note::setNote(string n){
	note = n;
}

void Note::setTag(string t){
	tag = t;
}


string Note::getTag(){
	return tag;
}

string Note::getNote(){
	return note;
}

Note::Note(){
	tag = "";
	note = "";
}

Note::Note(string n, string t){
	tag = t;
	note = n;
}
