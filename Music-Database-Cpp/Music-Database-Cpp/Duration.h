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
	operator int() const;
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
		totalSec = ((hrs * 3600) + (min * 60) + sec);
		hh = totalSec / 3600;
		int remainMin = totalSec - (hh * 3600);
		mm = remainMin / 60;
		ss = remainMin - (mm * 60);
	}
	Duration(const int seconds)
	{
		totalSec = seconds;
		hh = totalSec / 3600;
		totalSec %= 3600;
		mm = totalSec / 60;
		totalSec %= 60;
		ss = totalSec;
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
	//Adds duration to the current duration
	inline void addDuration(const Duration& dur)
	{
		this->hh += dur.getHours();
		this->mm += dur.getMinutes();
		this->ss += dur.getSeconds();
		setTotalSec(this->hh, this->mm, this->ss);

	}

	inline void setTotalSec(const int hrs,const int min, const int sec)
	{
		totalSec = ((hrs * 3600) + (min * 60) + sec);
	}

	friend istream& operator>> (istream& instr,Duration &a);//friend so it can access Duration privates from outside the class
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

