#include <iostream>
#include "Duration.h"
#include "Track.h"
#include "Album.h"
#include <sstream>

using namespace std;


int main(int argc, char* argv) {
	cout << "Testing beibe" << endl;
	Duration dur;
	Duration dur2;
	cin >> dur;
	cout << dur << endl;
	
	Track t("Testing", dur);
	//cout << dur.getTotalSec()<< endl;
	//cout << (dur>dur2) << endl;
	//cout << dur + dur2 << endl;
	cout << t << endl;
	return 0;
}