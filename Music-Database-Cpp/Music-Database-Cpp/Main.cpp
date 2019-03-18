#include <iostream>
#include "Duration.h"

using namespace std;


int main(int argc, char* argv) {
	cout << "Testing beibe" << endl;
	Duration dur;
	cout << dur << endl;
	"20:05:05" >> dur;
	cout << dur << endl;

	return 0;
}