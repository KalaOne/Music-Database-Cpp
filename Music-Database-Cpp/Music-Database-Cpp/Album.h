#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Track.h"

class Album
{
private:
	string artistName;
	string albumTitle;
	Duration duration;
	vector<Track> album;

public:
	Album()
	{
		artistName = "Unkown";
		albumTitle = "Unkown";
	}

	Album(string artName, string albumName, Duration dur)
	{
		artistName = artName;
		albumTitle = albumName;
		duration = dur;
	}

	inline string getAlbumInfo()
	{
		return artistName + " " + albumTitle;
	}
	//not sure about the refference.
	inline void addTrackToAlbum(Track &t)
	{
		album.push_back(t);
	}

	inline vector<Track> getAllTracksVector()
	{
		return album;
	}
};

ostream& operator<<(ostream& os, Album &a);