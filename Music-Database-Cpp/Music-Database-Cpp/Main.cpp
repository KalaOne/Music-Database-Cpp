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
	//cin >> dur;
	cout << dur << endl;
	
	Track t("Testing", dur);
	Track t2;
	//cout << dur.getTotalSec()<< endl;
	//cout << (dur>dur2) << endl;
	//cout << dur + dur2 << endl;
	cout << t << endl;
	cin >> t2;
	cout << t2 << endl;
	return 0;
}