#include "Track.h"
#include "Duration.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

ostream& operator<<(ostream& os, Track &a)
{
	os <<left<<a.getTitle() << "\t "<< right<<a.getDuration();
	return os;
}

istream& operator>> (istream& instr, Track &t)
{
	string delim;
	Duration d;
	char name[100];
//-------------------------- Add error checking for multiple lines - while loop to get inputs until correct format
	
	instr >> d >> delim;
	//when getline is called on the istream, the constructor is different...
	//takes WHERE, HOW MUCH, DELIMITER
	//getline is being called on object, not on random thing, so it knows the input
	instr.getline(name, 100,'\n');
	if (delim == "-") {
		//cout << "success!" << endl;
		t = Track(name, d);
	}
	else
		cerr << "Unexpected delimiter for Track..."<<endl;
	return instr;
	
}