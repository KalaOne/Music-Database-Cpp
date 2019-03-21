#include "Track.h"
#include "Duration.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

ostream& operator<<(ostream& os, Track &a)
{
	os << a.getTitle() << " "<< a.getDuration();
	return os;
}

istream& operator>> (istream& instr, Track &t)
{
	//istringstream input(instr); //converts the input to istream to use for getline()
	////for album check if the " : " exists, then use getline on the given delimiter. 
	//char delim = '-';
	//string trackInfo;
	//vector<string> track; //vector to store duration/title;
	//while (getline(instr, trackInfo, delim))
	//{
	//	track.push_back(trackInfo);
	//}
	//call splitter twice (first for '-' and then for ':')
	//splitter takes char '-' instead ' - '
	//vector X = stringSplitter (string, delimiter)
	//return the vector that has been created
	/*t.title = track[1];*/
	string delim;
	Duration d;
	string name;
//-------------------------- Add error checking for multiple lines - while loop to get inputs until correct format
	
	instr >> d >>delim >> name;
	if (delim == "-") {
		cout << "success!" << endl;
		t= Track(name, d);
	}
	else
		cerr << "The delimiter between duration and title is different than expected..."<<endl;
	return instr;
	
}