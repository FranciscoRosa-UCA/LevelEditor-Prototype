
#include "tilesClass.h"

#include <iostream>
using namespace std;

Tiles::Tiles() {
	this->typeActor = "Tiles";
}

Tiles::~Tiles() {
	cout << "destroyedTile" << endl;
	al_destroy_bitmap(sprite_base);
	delete ThisCollider;

}

void Tiles::draw() {
	al_draw_bitmap(sprite_base, x, y, 0);
	//ThisCollider->showCollider();
}

void Tiles::update() {

}




