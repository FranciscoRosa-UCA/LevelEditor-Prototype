#ifndef MENUCLASS_H
#define MENUCLASS_H

#include "game.h"
#include "buttonClass.h"
#include "staticButtonClass.h"

class Menu : public Game{
private:
	ALLEGRO_KEYBOARD_STATE keyboardState;
	bool exitloop = false;



public:

	void main();

	void GameIn();

	void EditorIn();

	void GameExit();

};

#endif