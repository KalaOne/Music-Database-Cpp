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

	inline string getTitle()
	{
		return title;
	}

	inline Duration getDuration()
	{
		return duration;
	}

	inline string getTrack()
	{
		string track = title + duration.getDuration();
		return track;
	}



};
////prototyping operator overloading for the .cpp file
//bool operator==(Duration &a, Duration &b);
//bool operator!=(Duration &a, Duration &b);
//bool operator<=(Duration &a, Duration &b);
//bool operator>=(Duration &a, Duration &b);
//bool operator<(Duration &a, Duration &b);
//bool operator>(Duration &a, Duration &b);
//int operator+(Duration &a, Duration &b);
//int operator-(Duration &a, Duration &b);
//ostream& operator<<(ostream& os, Duration &a); & os, Duration &a);