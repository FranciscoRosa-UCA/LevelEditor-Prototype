#include "basicBlock.h"

BasicBlock::BasicBlock(int x, int y, int idClass, Game* g) {
	this->x = x;
	this->y = y;
	this->idClass = idClass;
	this->sprite_base = al_load_bitmap("assets/mapTiles/smb_blocks.png");
	this->game = g;
	this->ThisCollider = new Collider(x, y, get_w(), get_h());
	game->collider_manager->add(ThisCollider);
}


void BasicBlock::draw() {
	//al_draw_bitmap_region(sprite_base, ((idClass-1) %3) * 16, (idClass/3)*16, 16, 16, x, y, 0);
	//cout << idClass << " " << (idClass - 2) % 3 << " " << (idClass - 2) / 3 << endl;  //coordenada de sprite
	al_draw_tinted_scaled_rotated_bitmap_region(sprite_base, ((idClass - 2) % 3) * 16, ((idClass-2) / 3) * 16, 16, 16, al_map_rgb(255, 255, 255), 0, 0, x, y, 3, 3, 0, 0);

	//ThisCollider->showCollider();
}

int BasicBlock::get_w() {
	return 16*3;
}

int BasicBlock::get_h() {
	return 16*3;
}

void BasicBlock::update() {

}