#include "keyboardClass.h"

Keyboard::Keyboard() {
	//actual_Key == "";
	//old_Key == "";
}

void Keyboard::update() {

	al_get_keyboard_state(&KeyboardState);



	/*
	if (old_Key == actual_Key && old_Key != "") Pressing = true;
	if (old_Key == "" && actual_Key != "") Pressing = true;
	else Pressing = false;
	if (old_Key == "" && actual_Key != "") Pressing = true;
	

	old_Key = actual_Key;
	*/
}

/*
string Keyboard::get_Key() {
	return actual_Key;
}
*/