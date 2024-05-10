#ifndef PLAYER_H
#define PLAYER_H

#include "Actor.h"
#include "game.h"
#include "ColliderClass.h"

class Player : public Actor
{
private:
	int id;
	int Past_state[2];
	bool moving = false;
	Game* game;
	
public:

	int animation, direction;

	Player(int, int, int, Game*);
	~Player();
	void update();
	void draw();
	int get_w();
	int get_h();

	void set_image(ALLEGRO_BITMAP*);
	void do_action();
	void logic();

	void SaveState();
/*
	int get_x() { return x; }
	int get_y() { return y; }
	int* set_x() { return &this->x; }
	int* set_y() { return &this->y; }
*/
};


#endif