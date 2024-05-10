#include "WRdataClass.h"

WRdata::WRdata() {

}

void WRdata::WritePlayer(int id, int x, int y, string location) {
	ofstream DataWrite;

	DataWrite.open(location, ios_base::app);
	DataWrite << id << " " << x << " " << y << "\n";
	DataWrite.close();

}

void WRdata::ReadPlayer(int id, int* x, int* y, string location) {
	ifstream DataRead(location);

	int id_;
	int x_;
	int y_;
	while (DataRead >> id_ >> x_ >> y_) {
		if (id == id_) {
			*x = x_;
			*y = y_;
			break;
		}
	}

	DataRead.close();
}

void WRdata::Clear(string location) {
	ofstream DataWrite;

	DataWrite.open(location, ios_base::out);
	DataWrite << "";
	DataWrite.close();

}