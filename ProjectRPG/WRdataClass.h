#ifndef WRDATACLASS_H
#define WRDATACLASS_H

#include <iostream>
#include <fstream>

using namespace std;


class WRdata {
private:

	string MasterData;


public:

	WRdata();
	void WritePlayer(int, int, int, string);
	void ReadPlayer(int, int*, int*, string);
	void Clear(string);

};

#endif