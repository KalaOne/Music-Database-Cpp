#include <iostream>
#include "Collection.h"
#include <sstream>

using namespace std;


int main(int argc, char* argv) {
	Duration dur(1,1,1);
	Duration dur2(2,2,2);
	Duration dur3(3,3,3);
	Track t("First Track", dur);
	Track t2("Second Track",dur2);
	Track t3("Another one", dur3);
	Album alb;
	Album alb2;
	Collection col;
	//cin >> dur;
	//cout << dur << endl;
	//cout << dur.getTotalSec()<< endl;
	//cout << (dur>dur2) << endl;
	//cout << dur + dur2 << endl;
	//cout << "Enter duration for album" << endl;
	//cin >> dur3;
	//cout << t2 << endl;
	alb = Album("Toshko", "The best rapper", dur3);
	alb2 = Album("Huehue","The obsidian" ,dur3);
	alb.addTrackToAlbum(t);
	alb.addTrackToAlbum(t2);
	alb2.addTrackToAlbum(t3);
	col.addAlbumToCollection(alb);
	col.addAlbumToCollection(alb2);
	cout << col << endl;
	return 0;
}