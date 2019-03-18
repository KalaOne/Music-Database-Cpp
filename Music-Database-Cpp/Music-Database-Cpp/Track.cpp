#include "Track.h"
#include "Duration.h"
#include <iostream>
#include <iomanip>

using namespace std;


ostream& operator<<(ostream& os, Track &a)
{
	os << a.getTrack();
	return os;
}