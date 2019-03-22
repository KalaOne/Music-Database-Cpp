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
	else
	{
		os << a.getHours() << ":" << setw(2) << a.getMinutes() << ":" << a.getSeconds();
	}
	
	return os;
}

istream& operator>> (istream& instr, Duration &d)
{
	char temp;
	int hrs, min, sec;
	instr >> hrs >> temp >> min>> temp >> sec;
	if (temp == ':') //check if the delimiter is ":"
	{
		//cout << "correct date format." << endl;
		d = Duration(hrs, min, sec);
	}
	else
		cerr << "Wrong delimiter between integers." << endl;

	d.totalSec = ((d.hh * 3600) + (d.mm * 60) + d.ss);

	return instr;
}