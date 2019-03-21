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

	Album(string artName, string albumName)
	{
		artistName = artName;
		albumTitle = albumName;
	}

	//not sure about the refference.
	inline void addTrackToAlbum(Track &t)
	{
		album.push_back(t);
	}

	inline string getAlbumInfo()
	{
		return artistName + " : " + albumTitle;
	}

	inline vector<Track> getAllTracksVector()
	{
		return album;
	}

	friend istream& operator>> (istream& instr, Album &a);
};

ostream& operator<<(ostream& os, Album &a);