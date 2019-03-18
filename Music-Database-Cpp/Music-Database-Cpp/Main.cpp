#include <iostream>
#include "Duration.h"
#include "Track.h"

using namespace std;


int main(int argc, char* argv) {
	cout << "Testing beibe" << endl;
	Duration dur;
	Duration dur2;
	Track t;
	"20:05:05" >> dur;
	"19:05:05" >> dur2;
	cout << dur << endl;
	cout << dur2 << endl;
	cout << dur.getTotalSec()<< endl;
	cout << (dur>dur2) << endl;
	cout << dur + dur2 << endl;
	cout << dur.getDuration() << endl;
	return 0;
}