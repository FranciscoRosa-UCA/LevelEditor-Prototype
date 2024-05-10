#include "grassTileClass.h"

GrassTile::GrassTile(int x, int y, Game* g) {
	this->x = x;
	this->y = y;
	this->idClass = 0;
	this->sprite_base = al_load_bitmap("assets/mapTiles/grass.png");
	this->game = g;
	this->ThisCollider = new Collider(x, y, get_w(), get_h());
	game->collider_manager->add(ThisCollider);
}