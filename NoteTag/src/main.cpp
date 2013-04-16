/*
 * main.cpp
 *
 *  Created on: Apr 16, 2013
 *      Author: Joey
 */

#include "XMLParse.h"

int main(){
	XMLParse parser("testFiles/testFile1");
	while(parser.isInputFileOpen()){
		cout<<parser.getNextTag()<<endl;
	}
	return 0;
}

