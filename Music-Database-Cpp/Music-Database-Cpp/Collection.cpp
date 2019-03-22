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

ifstream& operator>>(ifstream& in, Collection& c)
{
	string albums;
	//Specify how its read from the file.
	while(getline(in, albums){}

}