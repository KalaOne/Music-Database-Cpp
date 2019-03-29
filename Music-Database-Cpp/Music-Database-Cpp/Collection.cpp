#include "Collection.h"
#include <algorithm>


Duration Collection::getArtistTotalDuration(const string& artist)
{
	Duration totalTime;
	for(int i = 0; i < collection.size();i++)
	{
		if(collection[i].getArtistName().compare(artist) == 0)
		{
			totalTime.addDuration(collection[i].getTotalDuration());
		}
	}
	return totalTime;
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
