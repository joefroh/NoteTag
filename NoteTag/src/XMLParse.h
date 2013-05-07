/*
 * XMLParse.h
 *
 *  Created on: Apr 16, 2013
 *      Author: Joey
 */

#ifndef XMLPARSE_H_
#define XMLPARSE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <queue>
#include "Note.h"

using namespace std;

class XMLParse{
private:
	ifstream inputFile; //input file stream... duh
	vector<Note> notes;
	void readTag();
	void read();
	void readData();

public:
	XMLParse(string inFileName);
	string getNextTag();
	bool isInputFileOpen();
	bool parse();
	void outData();


};



#endif /* XMLPARSE_H_ */
