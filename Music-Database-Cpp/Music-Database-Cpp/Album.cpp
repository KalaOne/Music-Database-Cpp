#include "Album.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <iterator>


ostream& operator<<(ostream& os, Album &a)
{
	vector<Track> v = a.getAllTracksVector();
	os << a.getAlbumInfo()<< endl;;
	for(vector<Track>::iterator it = v.begin(); it !=v.end(); it++)
	{
		os << *it << endl;
	}

	return os;
}

istream& operator>> (istream& instr, Album &a)
{
	vector<string> v;
	string album;
	Track track;
	getline(instr, album, ':');
	v.push_back(album);
	getline(instr, album, '\n');
	v.push_back(album);
	a = Album(v[0], v[1]);
	while (instr >>track) // add track to album
	{
		//cout << track <<endl;
		a.addTrackToAlbum(track);
	}

	return instr;
}