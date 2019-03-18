#include "Duration.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>


bool operator==(Duration &a, Duration &b)
{
	if (a.getTotalSec() == b.getTotalSec())
		return true;
	else
		return false;
}

bool operator<=(Duration &a, Duration &b)
{
	if (a.getTotalSec() < b.getTotalSec()) 
		return true;
	else if (a.getTotalSec() == b.getTotalSec()) 
		return true;
	else
		return false;
}

bool operator>=(Duration &a, Duration &b)
{
	if (a.getTotalSec() > b.getTotalSec()) 
		return true;
	else if (a.getTotalSec() > b.getTotalSec()) 
		return true;
	else
		return false;
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
		os << setw(2) << a.getHours() << ":" << setw(2) << setfill('0') << a.getMinutes() << ":" << setw(2) << setfill('0') << a.getSeconds();
	}
	else if (a.getMinutes() < 10) {
		os << setw(2) << a.getHours() << ":" << setw(2)<<setfill('0') << a.getMinutes() << ":" << setw(2) << a.getSeconds();
	}
	else if (a.getSeconds() < 10)
	{
		os << setw(2) << a.getHours() << ":" << setw(2) << a.getMinutes() << ":" << setw(2)<<setfill('0') << a.getSeconds();
	}
	
	return os;
}

void operator>> (string instr, Duration &a)
{
	istringstream input(instr); //converts the input to istream to use for getline()
	char delim = ':';
	string output;
	vector<string> duration; //vector to store hh/mm/ss

	while(getline(input, output, delim))
	{
		duration.push_back(output);
	}
	a.hh = stoi(duration[0]);
	a.mm = stoi(duration[1]);
	a.ss = stoi(duration[2]);
}