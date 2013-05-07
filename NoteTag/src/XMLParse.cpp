/*
 * XMLParse.cpp
 *
 *  Created on: Apr 16, 2013
 *      Author: Joey
 */

#include "XMLParse.h"

XMLParse::XMLParse(string inFileName) :
		inputFile(inFileName.c_str()) {
	if (!inputFile.is_open()) {
		cerr << "File Not Found: " << inFileName << endl;
	}
}

/*
 * Currently will only work with line delimited tags (eg the tag is first on its line)
 */
string XMLParse::getNextTag() {
	return notes.front().getTag();
}

bool XMLParse::parse() {
	notes = vector<Note>();
	read();

	return true;
}
/*
 * is the input file open?
 */
bool XMLParse::isInputFileOpen() {
	return inputFile.is_open();
}

void XMLParse::outData() {
	int loopEnd = notes.size();
	cout << "size: " << loopEnd << endl;
	for (int i = 0; i < loopEnd; i++) {
		cout << "tag: " << notes.at(i).getTag() << endl;
		cout << "data: " << notes.at(i).getNote() << endl;
		//notes.pop();
	}
}

void XMLParse::readTag() {
	stringstream tag;
	notes.push_back(Note());
	char currChar = 0;

	while (inputFile.peek() != '>' && inputFile.get(currChar)) { //implicit check for EOF
			tag << currChar;
	}
	notes.back().setTag(tag.str());
	//cout << tag.str();
}

void XMLParse::read() {
	char currChar;
	while(inputFile.get(currChar)) { //imnplicit check for EOF
		switch (currChar) {
		case '<': //handle a tag
			readTag();
			break;
		default:
			readData();
			break;

		}
	}
}

void XMLParse::readData() {
	char currChar;// = 0;
	stringstream datum;
	while (inputFile.peek() != '<' && inputFile.get(currChar)) { //implicit check for EOF
			datum << currChar;
	}
	notes.back().setNote(datum.str());
	//if (datum.str().length() != 0)
		//cout << datum.str();

}
