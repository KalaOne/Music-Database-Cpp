#include "Duration.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>


string Duration::getDuration()
{
	int ttlHrs = getTotalSec()/ 3600; //hours from seconds
	int remainingSec = getTotalSec() % 3600; //seconds - hours
	int ttlMin = remainingSec / 60; // minutes from remaining sec
	int seconds = getTotalSec() - (ttlHrs * 3600) - (ttlMin * 60); // seconds left without hours and mins

	//casting ints to string to create one Duration string
	string hours = to_string(ttlHrs);
	string minutes = to_string(ttlMin);
	string sec = to_string(seconds);
	string totalTime = hours + ":" + minutes + ":" + sec;
	return totalTime;
}

bool operator==(Duration &a, Duration &b)
{
	return a.getTotalSec() == b.getTotalSec();
}

bool operator!=(Duration &a, Duration &b)
{
	return a.getTotalSec() != b.getTotalSec();
}

bool operator<=(Duration &a, Duration &b)
{
	return !(a > b);
}

bool operator>=(Duration &a, Duration &b)
{
	return !(a < b);
}

bool operator<(Duration &a, Duration &b)
{
	return a.getTotalSec() < b.getTotalSec();
}


bool operator>(Duration &a, Duration &b)
{
	return a.getTotalSec() > b.getTotalSec();
}


int operator+(Duration &a, Duration &b)
{
	return a.getTotalSec() + b.getTotalSec();
}

int operator-(Duration &a, Duration &b)
{
	return a.getTotalSec() - b.getTotalSec();
}

ostream& operator<<(ostream& os, Duration &a)
{
	if (a.getSeconds() < 10 && a.getMinutes() < 10)
	{
		os << a.getHours() << ":" << setw(2) << setfill('0') << a.getMinutes() << ":" << setw(2) << setfill('0') << a.getSeconds();
	}
	else if (a.getMinutes() < 10) {
		os << a.getHours() << ":" << setw(2)<<setfill('0') << a.getMinutes() << ":" << setw(2) << a.getSeconds();
	}
	else if (a.getSeconds() < 10)
	{
		os << a.getHours() << ":" << setw(2) << a.getMinutes() << ":" << setw(2)<<setfill('0') << a.getSeconds();
	}
	
	return os;
}

istream& operator>> (istream& instr, Duration &a)
{
	 //converts the input to istream to use for getline()
	char delim = ':';
	string output;
	vector<string> duration; //vector to store hh/mm/ss

	char temp; 
	instr >> a.hh >> temp >> a.mm >> temp >> a.ss;

	//for album check if the " : " exists, then use getline on the given delimiter. 
	//
	

	/*while(getline(instr, output, delim))
	{
		if (delim == ':')
			duration.push_back(output);
		else
			cerr << "Error: not expected delimiter" << endl;
	}
	a.hh = stoi(duration[0]);
	a.mm = stoi(duration[1]);
	a.ss = stoi(duration[2]);
	*/
	a.totalSec = ((a.hh * 3600) + (a.mm * 60) + a.ss);

	return instr;
}