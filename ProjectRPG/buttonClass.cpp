#include "buttonClass.h"
#include "controlManager.h"


Buttons::Buttons(int x, int y, int id, Game * game, ALLEGRO_BITMAP* sprite_false, ALLEGRO_BITMAP* sprite_true) {
	this->id = id;
	this->x = x;
	this->y = y;
	this->game = game;
	this->typeActor = "Buttons_Dynamic";

	this->sprite_true = sprite_true;
	this->sprite_false = sprite_false;

	this->sprite_w = al_get_bitmap_width(sprite_false);
	this->sprite_h = al_get_bitmap_height(sprite_false);


	Press_Range = false;
	Press_Button = false;

}

Buttons::~Buttons() {
	al_destroy_bitmap(sprite_false);
	al_destroy_bitmap(sprite_true);
}

void Buttons::draw() {
	if (Press_Range) al_draw_bitmap(sprite_true, x, y, NULL);

	else al_draw_bitmap(sprite_false, x, y, NULL);


}

void Buttons::update() {



	al_get_mouse_state(&game->mouseState);

	int Mx = game->control_manager->CameraControl->cameraPosition[0] + al_get_mouse_state_axis(&game->mouseState, 0);
	int My = game->control_manager->CameraControl->cameraPosition[1] + al_get_mouse_state_axis(&game->mouseState, 1);

	if (Mx >= x && Mx <= x + sprite_w && My >= y && My <= y + sprite_h ) {

		Press_Range = true;

		if ( (game->mousePressed) ) {
			Press_Button = true;
			time_Waiting = true;
		} 
		else Press_Button = false;

	}
	else {
		Press_Range = false;
	}


	if (time_Waiting && time_Wait < 100) time_Wait++; // tiempo de espera antes de reaccionar a otra llamada
	else {
		time_Wait = 0;
		time_Waiting = false;
	}

	

}

bool Buttons::Pressed() {
	if (Press_Button) {
		Press_Button = false;
		return true;
	}
	else return false;
}