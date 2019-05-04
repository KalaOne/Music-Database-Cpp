#include "Album.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <iterator>

//Trimming string functions to remove white spaces from the strings
string& beginTrim(std::string& s)
{
	auto it = std::find_if(s.begin(), s.end(),[](char c)
	{
		return !isspace(c);
	});
	s.erase(s.begin(), it);
	return s;
}

string& endTrim(std::string& s)
{
	auto it = find_if(s.rbegin(), s.rend(),
		[](char c) {
		return !isspace(c);
	});
	s.erase(it.base(), s.end());
	return s;
}

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


istream& operator>> (istream& instr,Album &a)
{
	vector<string> v;
	string album;
	Track track;
	getline(instr, album, ':');
	endTrim(album);
	v.push_back(album);
	getline(instr, album, '\n');
	beginTrim(album);
	v.push_back(album);
	a = Album(v[0], v[1]);
	while (instr >>track) // add track to album
	{
		//cout << track <<endl;
		a.addTrackToAlbum(track);
	}

	return instr;
}
