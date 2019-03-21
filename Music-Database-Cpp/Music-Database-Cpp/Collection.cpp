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