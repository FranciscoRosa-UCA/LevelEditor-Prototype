#include "actor.h"
Actor::Actor()
{
}
Actor::~Actor()
{
}
void Actor::draw()
{
}
void Actor::update()
{
}

int Actor::get_w() {
	return al_get_bitmap_width(sprite_base);
}

int Actor::get_h() {
	return al_get_bitmap_height(sprite_base);
}