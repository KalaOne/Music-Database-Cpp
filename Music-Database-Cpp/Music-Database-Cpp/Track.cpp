#include "Track.h"
#include "Duration.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>

using namespace std;

//Unfortunately the method is redundant with Album one, they have to be global (c++ thing)
string& trim(std::string& s)
{
	auto it = std::find_if(s.begin(), s.end(), [](char c)
	{
		return !isspace(c);
	});
	s.erase(s.begin(), it);
	return s;
}

bool operator>(const Duration& a, const int b)
{
	return a.getTotalSec() > b;
}

ostream& operator<<(ostream& os, const Track &a)
{
	os <<a.getTitle() << "\t "<<a.getDuration();
	return os;
}

istream& operator>> (istream& instr, Track &t)
{
	string delim;
	Duration d;
	char name[100];
	string nameWithoutSpace;
	instr >> d >> delim;
	//when getline is called on the istream, the constructor is different...
	//takes WHERE, HOW MUCH, DELIMITER
	//getline is being called on object, not on random thing, so it knows the input

	instr.getline(name, 100,'\n');
	if (delim == "-") {
		//cout << "success!" << endl;
		nameWithoutSpace = name;
		trim(nameWithoutSpace);
		t = Track(nameWithoutSpace, d);
	}
	
	return instr;
	
}