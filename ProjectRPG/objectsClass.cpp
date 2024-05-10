
#include "objectsClass.h"
#include <iostream>
using namespace std;

Objects::Objects() {
	this->typeActor = "Objects";
}

Objects::~Objects() {
	cout << "destroyedObject" << endl;
	al_destroy_bitmap(sprite_base);
}


