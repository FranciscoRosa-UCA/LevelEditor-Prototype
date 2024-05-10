#ifndef BUTTONSCLASS_H
#define BUTTONSCLASS_H

#include "game.h"
#include "actor.h"

class Buttons : public Actor {
	ALLEGRO_BITMAP* sprite_true;
	ALLEGRO_BITMAP* sprite_false;
	bool Press_Range;
	bool Press_Button;
	int id;
	int time_Wait = 0;
	bool time_Waiting = false;
	int sprite_w, sprite_h;
	Game* game;


public:
	Buttons(int, int, int, Game *, ALLEGRO_BITMAP*, ALLEGRO_BITMAP*);
	~Buttons();
	void draw();
	void update();
	bool Pressed();
};

#endif