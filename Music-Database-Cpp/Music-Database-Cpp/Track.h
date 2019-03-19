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
ostream& operator<<(ostream& os, Track &a);