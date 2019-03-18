#pragma once
#include <iostream>

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
	Duration(int hh, int mm, int ss)
	{
		Duration::hh = hh;
		Duration::mm = mm;
		Duration::ss = ss;

		totalSec = ((Duration::hh * 3600) + (Duration::mm * 60) + Duration::ss);
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
	
	friend void operator>> (string instr, Duration &a);//friend so it can access Duration privates from outside the class
};
//prototyping operator overloading for the .cpp file
bool operator==(Duration &a, Duration &b);
bool operator<=(Duration &a, Duration &b);
bool operator>=(Duration &a, Duration &b);
int operator+(Duration &a, Duration &b);
int operator-(Duration &a, Duration &b);
ostream& operator<<(ostream& os, Duration &a);

