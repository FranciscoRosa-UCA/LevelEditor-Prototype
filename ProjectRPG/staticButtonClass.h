#ifndef STATICBUTTONSCLASS_H
#define STATICBUTTONSCLASS_H

#include "game.h"
#include "actor.h"

class Buttons_Static : public Actor {
private:
	ALLEGRO_BITMAP* sprite_true;
	ALLEGRO_BITMAP* sprite_false;
	bool Press_Range;
	bool Press_Button;
	int id;
	int time_Wait = 0;
	bool time_Waiting = false;
	int sprite_w, sprite_h;

	int relX, relY;

	Game* game;


public:
	Buttons_Static(int, int, int, Game*, ALLEGRO_BITMAP*, ALLEGRO_BITMAP*);
	~Buttons_Static();
	void draw();
	void update();
	bool Pressed();
};

#endif