#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Album.h"

using namespace std;

class Collection
{
private:
	vector<Album*> collection;
public:
	inline void addAlbumToCollection(Album* a)
	{
		collection.push_back(a);
	}

	inline vector<Album*>& getCollectionVector()
	{
		return collection;
	}

	Collection()
	{
		vector<Album*> collect;
	}
	//Rule of three:
	//Copy assignment
	Collection& operator=(const vector<Album*> col)
	{
		collection = col;
		return *this;
	}
	//Copy constructor
	Collection(const vector<Album*>& col)
	{
		vector<Album*> copy = col;
	}
	//Destructor
	~Collection()
	{
		for(Album* a : collection)
		{
			delete a;
		}
		collection.clear();
	}

	friend istream& operator>>(istream& in, Collection& c);
	Duration getArtistTotalDuration(const string& artist);
	string albumWithMostTracks() const;
	string longestTrackInfo() const;

};

string operator+(const string& cs, const Duration& rhs);
ostream& operator<<(ostream& os, Collection &d);
