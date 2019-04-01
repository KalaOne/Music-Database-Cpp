#pragma once
#include <iostream>
#include "Duration.h"

using namespace std;

class Track
{
private:
	string title;
	Duration duration;

public:
	//Constructors
	Track()
	{
		title = "Unknown";
	}

	Track(string newTitle, Duration dur)
	{
		title = newTitle;
		duration = dur;
	}

	inline string getTitle() const
	{
		return title;
	}

	inline const Duration getDuration() const
	{
		return duration;
	}


	friend istream& operator>> (istream& instr,Track &t);
};
bool operator>(const Duration& a, const int b);
ostream& operator<<(ostream& os, const Track &a);