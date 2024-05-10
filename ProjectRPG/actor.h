#ifndef ACTOR_H
#define ACTOR_H

#include <allegro5/allegro5.h>
#include "game.h"
#include "colliderManager.h"
#include "ColliderClass.h"
#include <iostream>
using namespace std;

class Actor{
public:
	Actor();
	virtual ~Actor();
	virtual void draw();
	virtual void update();
	void set_x(int pos_x) { x = pos_x; }
	void set_y(int pos_y) { y = pos_y; }
	int get_x() { return x; }
	int get_y() { return y; }

	virtual int get_w();
	virtual int get_h();

	int getID() { return this->idClass; }
	string get_typeActor(){ return typeActor; }
	string get_actorName(){ return actorName; }
	
	bool ControllableKeyboard = false;
	bool taked = false;

protected:
	int x, y;
	int idClass;
	
	Collider* ThisCollider = NULL;

	Game* game = NULL;
	string typeActor;
	string actorName;
	ALLEGRO_BITMAP* sprite_base = NULL;

};

#endif ACTOR_H