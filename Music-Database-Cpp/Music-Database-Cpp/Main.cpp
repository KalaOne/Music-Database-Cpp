#include <iostream>
#include "Collection.h"
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;


int main(int argc, char* argv) {
	//Duration dur(1,1,1);
	//Duration dur2(2,2,2);
	//Duration dur3(3,3,3);
	//Track t("First Track", dur);
	//Track t2("Second Track",dur2);
	//Track t3("Another one", dur3);
	Track t4;
	//Album alb;
	//Album alb2;
	Collection collect;
	////cin >> dur;
	////cout << dur << endl;
	////cout << dur.getTotalSec()<< endl;
	////cout << (dur>dur2) << endl;
	////cout << dur + dur2 << endl;
	////cout << "Enter duration for album" << endl;
	////cin >> dur3;
	////cout << t2 << endl;
	//alb = Album("Toshko", "The best rapper");
	//alb2 = Album("Huehue","The obsidian");
	//alb.addTrackToAlbum(t);
	//alb.addTrackToAlbum(t2);
	//alb2.addTrackToAlbum(t3);
	//col.addAlbumToCollection(alb);
	//col.addAlbumToCollection(alb2);
	////cout << col << endl;
	//cout << "Enter track: " << endl;
	/*cin >> t4;
	cout << t4 << endl;
	Album alb3;
	Album alb4;*/
	ifstream file;
	file.open("album.txt");
	if (file.is_open())
	{
		cout << "File read successfully." << endl;
		cout << "-------------------------------------------------------------------" << endl;
		//cout << alb3 << endl;
		//cout <<"t"<< file.rdbuf() << endl;
		//file.clear();
		//file >> alb4;
		//cout << alb4 << endl;
		file >> collect;
		sort(collect.getCollectionVector().begin(), collect.getCollectionVector().end());
		cout << collect << endl;
		cout << "3. Total play time of 'Pink Floyd'" << endl;
		cout << collect.getArtistTotalDuration("Pink Floyd ") << endl;
		cout << "4. Album with largest number of tracks" << endl;
		cout << collect.albumWithMostTracks() << endl;
//Sort out seconds distribution because it prints a mess.
//IF TIME PERMITS : 
//Also try to get rid of the " " spaces before and after strings. IF TIME PERMITS.
	}
	else
	{
		cout << "Unable to open file..." << endl;
	}
	

	return 0;
}