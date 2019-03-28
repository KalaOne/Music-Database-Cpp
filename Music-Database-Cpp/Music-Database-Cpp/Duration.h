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
	Duration(const int hrs,const int min, const int sec)
	{
		int remainMin;
		totalSec = ((hrs * 3600) + (min * 60) + sec);
		hh = totalSec / 3600;
		remainMin = totalSec - (hh * 3600);
		mm = remainMin / 60;
		ss = remainMin - (mm * 60);

	}

	inline int getSeconds() const
	{	
		return ss;
	}
	inline int getMinutes() const
	{
		return mm;
	}
	inline int getHours() const
	{
		return hh;
	}
	inline int getTotalSec() const
	{
		return totalSec;
	}

	inline void setTotalSec(const int hrs,const int min, const int sec)
	{
		totalSec = ((hrs * 3600) + (min * 60) + sec);
	}

	friend istream& operator>> (istream& instr,Duration &a);//friend so it can access Duration privates from outside the class
	friend string getDuration();
};
//prototyping operator overloading for the .cpp file
bool operator==(const Duration &a, const Duration &b);
bool operator!=(const Duration &a, const Duration &b);
bool operator<=(const Duration &a, const Duration &b);
bool operator>=(const Duration &a, const Duration &b);
bool operator<(const Duration &a, const Duration &b);
bool operator>(const Duration &a, const Duration &b);
int operator+(const Duration &a, const Duration &b);
int operator-(const Duration &a, const Duration &b);
ostream& operator<<(ostream& os,const Duration &a);

