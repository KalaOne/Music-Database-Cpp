#pragma once

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

	bool operator==(Duration &a, Duration &b)
	{
		if (a.getTotalSec() == b.getTotalSec())
			return true;
		else
			return false;
	}

	bool operator<=(Duration &a, Duration &b)
	{
		if (a.getTotalSec() < b.getTotalSec()) return true;
		else if (a.getTotalSec() == b.getTotalSec()) return true;
		else
			return false;
	}

	bool operator>=(Duration &a, Duration &b)
	{
		if (a.getTotalSec() > b.getTotalSec()) return true;
		else if (a.getTotalSec() > b.getTotalSec()) return true;
	}
	//<< is toString
	//>> splits the input into different stuff and creates a new object with the input

};