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

using namespace std;

class XMLParse{
private:
	ifstream inputFile; //input file stream... duh

public:
	XMLParse(string inFileName);
	string getNextTag();
	bool isInputFileOpen();


};



#endif /* XMLPARSE_H_ */