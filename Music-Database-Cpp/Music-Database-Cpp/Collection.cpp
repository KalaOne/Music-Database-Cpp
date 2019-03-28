#include "Collection.h"
#include <algorithm>


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

template <typename T> void exchange(T a, T b)
{
	T temp = b;
	b = a;
	a = temp;
}

//struct {
//	void operator()(Album& a, Album& b) const
//	{
//		if (a.getArtistName() > b.getArtistName())
//		{
//			//ask TA what to return?!
//			exchange(a, b);
//
//		}
//		else if (a.getArtistName() == b.getArtistName())
//		{
//			if (a.getAlbumName() > b.getAlbumName())
//			{
//				exchange(a, b);
//
//			}
//		}
//		
//	}
//} sortFunctAsc;


template <typename T> bool descending(T& a, T&b)
{
	return a > b;
}


//void Collection::sortAscending()
//{
//	
//	for(int i = 0; i < sizeof(collection); i++)
//	{
//		cout << i << endl;
//		//check if this artist > next one
//		if(collection[i].getArtistName().compare(collection[i+1].getArtistName()) > 0)
//		{
//			//swap them
//			exchange(collection[i], collection[i + 1]);
//			cout << "swapping artists" << endl;
//		}
//		//artists are the same
//		else if(collection[i].getArtistName().compare(collection[i + 1].getArtistName()) == 0)
//		{
//			cout << "swapping albums" << endl;
//			//check if albums are > and orders them
//			if(collection[i].getAlbumName().compare(collection[i+1].getAlbumName()) > 0)
//			{
//				exchange(collection[i], collection[i + 1]);
//			}
//		}
//	}
//}