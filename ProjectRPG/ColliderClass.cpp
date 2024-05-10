
#include "ColliderClass.h"
#include <allegro5/allegro_primitives.h>

Collider::Collider(int x, int y, int dim_x, int dim_y) {
	this->x = x;
	this->y = y;
	this->dim_x = dim_x;
	this->dim_y = dim_y;
	this->show = false;
	this->active = true;
	
}

Collider::~Collider() {

}


void Collider::set_x(int x) {
	this->x = x;
}

void Collider::set_y(int y) {
	this->y = y;
}

void Collider::set_dim_x(int dim_x) {
	this->dim_x = dim_x;
}

void Collider::set_dim_y(int dim_y) {
	this->dim_y = dim_y;
}

int Collider::get_x() {
	return x;
}

int Collider::get_y() {
	return y;
}

int Collider::get_dim_x() {
	return dim_x;
}

int Collider::get_dim_y() {
	return dim_y;
}


bool Collider::CollingTo(Collider* C) {
	if (this != C) {
		if (
			!(
				(x > C->get_x() + C->get_dim_x()) ||
				(C->get_x() > x + dim_x) ||
				(y > C->get_y() + C->get_dim_y()) ||
				(C->get_y() > y + dim_y)

				)
			)
			return true;
	}
	return false;
}

void Collider::showCollider() {
	al_draw_rectangle(x, y, x + dim_x, y + dim_y, al_map_rgb(255, 255, 255), 2);
}