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

	inline void addAlbumToCollection(Album &a)
	{
		collection.push_back(a);
	}

	inline vector<Album> getCollectionVector()
	{
		return collection;
	}

	//friend ifstream& operator>>(ifstream& in, Collection& c);
};

ostream& operator<<(ostream& os, Collection &d);