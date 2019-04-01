#include "Collection.h"
#include <algorithm>


Duration Collection::getArtistTotalDuration(const string& artist)
{
	int totalSeconds = 0;
	for(int i = 0; i < collection.size();i++)
	{
		if(collection[i].getArtistName().compare(artist) == 0)
		{
			totalSeconds += collection[i].getTotalDuration();
		}
	}
	Duration totalTime = Duration(totalSeconds);
	return totalTime;
}

string Collection::albumWithMostTracks() const
{
	int trackNum = 0;
	Album album;
	for (int i = 0; i < collection.size(); i++)
	{
		if (collection[i].getAllTracksVector().size() > trackNum){			
			trackNum = collection[i].getAllTracksVector().size();
			album = collection[i];
		}
	}
	return album.getAlbumInfo();
}



string Collection::longestTrackInfo() const
{
	int minimum = -1;
	Track longestTrack;
	//loop through albums in collection
	for(Album alb : collection)
	{
		//loop through tracks in each album
		for(Track thisTrack : alb.getAllTracksVector())
		{
			if(thisTrack.getDuration() > minimum)
			{
				longestTrack = thisTrack;
				minimum = thisTrack.getDuration().getTotalSec();
			}
		}
	}
	return longestTrack.getTitle() + " " + longestTrack.getDuration();
}

string operator+(const string& cs, const Duration& rhs)
{
	return cs + " " + to_string(rhs.getHours()) + ":" + to_string(rhs.getMinutes()) + ":" + to_string(rhs.getSeconds());
}

ostream& operator<<(ostream& os, Collection &c)
{
	vector<Album> v = c.getCollectionVector();
	for (vector<Album>::iterator it = v.begin(); it != v.end(); it++)
	{
		os << *it << endl;
	}

	return os;
}

istream& operator>>(istream& in, Collection& c)
{
	Album album;
	//Specify how its read from the file.
	while(!in.eof())
	{
		in >> album;
		c.addAlbumToCollection(album);
		if (in.eof())
		{
			break;
		}
		in.clear();
	}
	return in;
}
