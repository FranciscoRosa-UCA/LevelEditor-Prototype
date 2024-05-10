#include <vector>

#include <allegro5/allegro5.h>

#include "controlmanager.h"


ControlManager::ControlManager()
{
	KeyboardControl = new Keyboard;
	CameraControl = new Camera;
}

ControlManager::~ControlManager()
{
	delete KeyboardControl;
}

void ControlManager::update()
{
	KeyboardControl->update();
}

void ControlManager::set_keyboard(Actor* ThisActor) {
	ThisActor->ControllableKeyboard = true;
}

void ControlManager::set_Camera(Actor* ThisActor) {
	CameraControl->CameraUpdate(CameraControl->cameraPosition, ThisActor->get_x(), ThisActor->get_y(), ThisActor->get_w(), ThisActor->get_h());

}


void ControlManager::set_CameraArrowFree() {
	ALLEGRO_KEYBOARD_STATE Kstate = KeyboardControl->KeyboardState;
	if (al_key_down(&Kstate, ALLEGRO_KEY_UP)) {
		y -= 10;
	}
	if (al_key_down(&Kstate, ALLEGRO_KEY_DOWN)) {
		y += 10;
	}
	if (al_key_down(&Kstate, ALLEGRO_KEY_LEFT)) {
		x -= 10;
	}
	if (al_key_down(&Kstate, ALLEGRO_KEY_RIGHT)) {
		x += 10;
	}
	CameraControl->CameraUpdate(CameraControl->cameraPosition, x, y, 48, 48);
}


void ControlManager::reset_Camera() {
	CameraControl->CameraReset();
}



















 /*
ControlManager::ControlManager(Game* g) {
	ControlsAvailable = true;
	game = g;

}

void ControlManager::set_Controls() {

}

void ControlManager::set_Controls_ON_OF(bool Change) {
	ControlsAvailable = Change;
}

void ControlManager::set_KeyBoardPlayer() {
	if (ControlsAvailable) {


		
	}
}
*/