#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Album.h"

using namespace std;

class Collection
{
private:
	vector<Album> collection;
public:
	inline void addAlbumToCollection(const Album &a)
	{
		collection.push_back(a);
	}

	inline vector<Album>& getCollectionVector()
	{
		return collection;
	}

	friend istream& operator>>(istream& in, Collection& c);
	Duration getArtistTotalDuration(const string& artist);
	string albumWithMostTracks() const;
	string longestTrackInfo() const;

};

string operator+(const string& cs, const Duration& rhs);
ostream& operator<<(ostream& os, Collection &d);
