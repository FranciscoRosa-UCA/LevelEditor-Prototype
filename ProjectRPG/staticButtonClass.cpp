#include "staticButtonClass.h"
#include "controlManager.h"


Buttons_Static::Buttons_Static(int x, int y, int id, Game* game, ALLEGRO_BITMAP* sprite_false, ALLEGRO_BITMAP* sprite_true) {
	this->id = id;
	this->game = game;

	relX = x + game->control_manager->CameraControl->cameraPosition[0];
	relY = y + game->control_manager->CameraControl->cameraPosition[1];
	this->x = relX;
	this->y = relY;

	this->typeActor = "Buttons_Static";

	this->sprite_true = sprite_true;
	this->sprite_false = sprite_false;

	this->sprite_w = al_get_bitmap_width(sprite_false);
	this->sprite_h = al_get_bitmap_height(sprite_false);


	Press_Range = false;
	Press_Button = false;

}

Buttons_Static::~Buttons_Static() {
	cout << "Destroyed Buttons_Static" << endl;
	al_destroy_bitmap(sprite_base);
	al_destroy_bitmap(sprite_false);
	al_destroy_bitmap(sprite_true);

}

void Buttons_Static::draw() {
	if (Press_Range) al_draw_bitmap(sprite_true, x, y, NULL);

	else al_draw_bitmap(sprite_false, x, y, NULL);


}

void Buttons_Static::update() {

	x = relX + game->control_manager->CameraControl->cameraPosition[0];
	y = relY + game->control_manager->CameraControl->cameraPosition[1];

	al_get_mouse_state(&game->mouseState);

	int Mx = game->control_manager->CameraControl->cameraPosition[0] + al_get_mouse_state_axis(&game->mouseState, 0);
	int My = game->control_manager->CameraControl->cameraPosition[1] + al_get_mouse_state_axis(&game->mouseState, 1);

	if (Mx >= x && Mx <= x + sprite_w && My >= y && My <= y + sprite_h) {

		Press_Range = true;

		if ((game->mousePressed)) {
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

bool Buttons_Static::Pressed() {
	if (Press_Button) {
		Press_Button = false;
		return true;
	}
	else return false;
}