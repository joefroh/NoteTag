/*
 * XMLParse.cpp
 *
 *  Created on: Apr 16, 2013
 *      Author: Joey
 */

#include "XMLParse.h"

XMLParse::XMLParse(string inFileName) :
		inputFile(inFileName.c_str()) {

	//inputFile.open(inFileName);

	if (!inputFile.is_open()) {
		cerr << "File Not Found: " << inFileName << endl;
	}
}

/*
 * Currently will only work with line delimited tags (eg the tag is first on its line)
 */
string XMLParse::getNextTag() {
	return tags.front();
}

bool XMLParse::parse() {
	tags = queue<string>();
	data = queue<string>();
	stringstream ss;
	stringstream lineData;
	string line;
	int i;

	if (inputFile.is_open() && !inputFile.eof()) {
		getline(inputFile, line); //read through the file until you reach a tag
		if (line[0] == '<') {
			for (i = 1; i < line.length() && line[i] != '>'; i++) {
				ss << line.at(i); //read in the tag text
			}
			tags.push(ss.str());
			if (i != line.length())
				i++;

		} else {
			cerr << "First line does not begin with a tag" << endl;
			return false;
		}
	}
	if (inputFile.is_open() && !inputFile.eof()) {
		do {
			if (i != line.size())
				lineData << line.substr(i, line.size()) << " ";
			i = 0;
			getline(inputFile, line); //read through the file until you reach a tag
		} while (line[0] != '<' && !inputFile.eof());

		if (line[1] == '/') { //end tag
			ss.clear();
			ss.str(string());
			data.push(lineData.str());
			for (i = 2; i < line.length() && line[i] != '>'; i++) {
				ss << line[i];
			}
			if (ss.str() != tags.back()) {
				cerr << "tag mismatch: " << ss.str() << " " << tags.back()
						<< endl;
				return false;
			}
		} else {
			ss.clear();
			for (int i = 1; i < line.length() && line[i] != '>'; i++) {
				ss << line.at(i); //read in the tag text
			}
		}
	} else {
		cerr << "File Not Open or End Reached" << endl;
	}

	if (inputFile.eof()) //close the file if we have reached the end of it
		inputFile.close();

	if (data.size() != tags.size()) {
		cerr << "q length mismatch " << tags.size() << " " << data.size()
				<< endl;
		return false;
	}

	return true;
}
/*
 * is the input file open?
 */
bool XMLParse::isInputFileOpen() {
	return inputFile.is_open();
}

void XMLParse::outData() {
	int loopEnd = tags.size();
	cout << "size: " << loopEnd << endl;
	for (int i = 0; i < loopEnd; i++) {
		cout << "tag: " << tags.front() << endl;
		cout << "data: " << data.front() << endl;
		tags.pop();
		data.pop();
	}
}
