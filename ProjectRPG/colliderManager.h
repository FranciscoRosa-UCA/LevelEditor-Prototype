#ifndef COLLIDERMANAGER_H
#define COLLIDERMANAGER_H

#include "game.h"
#include <list>
using namespace std;

class Collider;

class ColliderManager {

public:

	ColliderManager(Game*);
	~ColliderManager();
	void add(Collider* C);
	void del(Collider* C);

	void rewind();
	Collider* next();



protected:
	Game* game;
	list<Collider*> colliders_bag;
	list<Collider*>::iterator colliders_bag_iterator;

};


#endif