/*
 * Note.hpp
 *
 *  Created on: May 7, 2013
 *      Author: Joey
 */

#ifndef NOTE_HPP_
#define NOTE_HPP_
#include <string>

using namespace std;

class Note{

private:
	string note;
	string tag;

public:
	string getNote();
	string getTag();
	void setNote(string n);
	void setTag(string t);
	Note();
	Note(string n, string t);

};

#endif /* NOTE_HPP_ */
