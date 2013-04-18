/*
 * main.cpp
 *
 *  Created on: Apr 16, 2013
 *      Author: Joey
 */

#include "XMLParse.h"

int main(){
	XMLParse parser("testFiles/testFile2");
	if(parser.parse())
		parser.outData();
	else
		cerr<<"uh oh"<<endl;
	return 0;
}

