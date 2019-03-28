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

	
	inline void addTrackToAlbum(const Track &t) 
	{
		album.push_back(t);
	}

	inline string getAlbumInfo()  const
	{
		return artistName + " : " + albumTitle;
	}

	inline vector<Track> getAllTracksVector() const
	{
		return album;
	}


	inline string getArtistName() const
	{
		return artistName;
	}

	inline string getAlbumName() const
	{
		return albumTitle;
	}
	//less than operator overload - used for sorting function
	// will sort in ascending Artist -> Album
	bool operator<(const Album& a) const
	{
		if(artistName.compare(a.getArtistName())< 0)
		{
			return true;
		}
		else if(artistName.compare(a.getArtistName()) > 0)
		{
			return false;
		}
		else
		{
			if(albumTitle.compare(a.getAlbumName()) < 0)
			{
				return true;
			}
			else
				return false;
		}
	}
	friend istream& operator>> (istream& instr, Album &a);
};

ostream& operator<<(ostream& os, Album &a);