#include "Duration.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>


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
		os << a.getHours() << ":" << a.getMinutes() << ":" << a.getSeconds();
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
	/*else
		cerr << "Wrong delimiter between integers." << endl;*/

	d.totalSec = ((d.hh * 3600) + (d.mm * 60) + d.ss);

	return instr;
}