#ifndef KEYBOARDCLASS_H
#define KEYBOARDCLASS_H

#include <allegro5/allegro5.h>
#include <string>
using namespace std;

class Keyboard {

private:
	//string actual_Key;
	//string old_Key;

public:
	ALLEGRO_KEYBOARD_STATE KeyboardState;
	bool Pressing = false;

	Keyboard();
	virtual void update();


	/*
	typedef enum {
		REALICE,
		PRESSING
	}typePress;
	*/
	//typePress magnitude();

	//string get_Key();
};


#endif // !KEYBOARDCLASS_H
