#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Duration
{
private:
	int ss, mm, hh, totalSec;
	
public:
	//default constructor, setting time to 0
	Duration()
	{
		hh = 0;
		mm = 0;
		ss = 0;

		totalSec = ((hh * 3600) + (mm * 60) + ss);
	}
	//Constructor setting time to given arguments
	Duration(int hrs, int min, int sec)
	{
		int remainMin;
		totalSec = ((hrs * 3600) + (min * 60) + sec);
		hh = totalSec / 3600;
		remainMin = totalSec - (hh * 3600);
		mm = remainMin / 60;
		ss = remainMin - (mm * 60);

	}

	inline int getSeconds()
	{	
		return ss;
	}
	inline int getMinutes()
	{
		return mm;
	}
	inline int getHours()
	{
		return hh;
	}
	inline int getTotalSec()
	{
		return totalSec;
	}


	friend istream& operator>> (istream& instr, Duration &a);//friend so it can access Duration privates from outside the class
	friend string getDuration();
};
//prototyping operator overloading for the .cpp file
bool operator==(Duration &a, Duration &b);
bool operator!=(Duration &a, Duration &b);
bool operator<=(Duration &a, Duration &b);
bool operator>=(Duration &a, Duration &b);
bool operator<(Duration &a, Duration &b);
bool operator>(Duration &a, Duration &b);
int operator+(Duration &a, Duration &b);
int operator-(Duration &a, Duration &b);
ostream& operator<<(ostream& os, Duration &a);

