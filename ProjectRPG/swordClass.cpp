#include "swordClass.h"

SwordClass::SwordClass(int x, int y, int idSword, int damage, int durability, int attackSpeed, int attackArea, bool inMap, string name, string sprite_location) {

	this->actorName = name;

	this->idSword = idSword;

	this->damage = damage;

	this->durability = durability;

	this->attackSpeed = attackSpeed;

	this->attackArea = attackArea;

	this->inMap = false;

	this->sprite_base = al_load_bitmap(("assets/objects/" + sprite_location + ".png").c_str());

}

void SwordClass::draw() {

	al_draw_bitmap(sprite_base, x, y, 0);

}

void SwordClass::update() {

}
