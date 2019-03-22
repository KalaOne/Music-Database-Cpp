#include "Collection.h"


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