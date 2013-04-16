/*
 * XMLParse.cpp
 *
 *  Created on: Apr 16, 2013
 *      Author: Joey
 */




#include "XMLParse.h"

XMLParse::XMLParse(string inFileName):inputFile(inFileName.c_str()){

	//inputFile.open(inFileName);

	if(!inputFile.is_open()){
		cerr<<"File Not Found: "<<inFileName<<endl;
	}
}

/*
 * Currently will only work with line delimited tags (eg the tag is first on its line)
 */
string XMLParse::getNextTag(){
	stringstream ss;
	string line;
	if(inputFile.is_open() && !inputFile.eof()){
		do{
			getline(inputFile,line); //read through the file until you reach a tag
		}while(line[0] != '<' && !inputFile.eof());

		for(int i = 1; i < line.length() && line[i] != '>'; i++){
			ss<<line.at(i); //read in the tag text
		}
	} else{
		cerr<<"File Not Open or End Reached"<<endl;
	}

	if(inputFile.eof()) //close the file if we have reached the end of it
		inputFile.close();

	return ss.str();
}

/*
 * is the input file open?
 */
bool XMLParse::isInputFileOpen(){
	return inputFile.is_open();
}
