#include "Album.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>


//for album check if the " : " exists, then use getline on the given delimiter. 

ostream& operator<<(ostream& os, Album &a)
{
	vector<Track> v = a.getAllTracksVector();
// ---------------------- Need to pass the vector(Album) of Tracks to iterator over it and get every track. How?
	for(vector<Track>::iterator it = v.begin(); it !=v.end(); it++)
	{
		os << *it << endl;
	}

	return os;
}