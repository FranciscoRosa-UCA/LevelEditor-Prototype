#ifndef ACTORMANAGER_H
#define ACTORMANAGER_H

#include "tilesClass.h"
#include "objectsClass.h"
#include "player.h"

#include <algorithm>
#include <list>

using namespace std;

class Actor;
class Game;

class ActorManager{
public:
	ActorManager(Game* g);
	~ActorManager();
	void add(Actor* a);
	void del(Actor* a);
	void destroy(Actor* a);
	void destroyAll();

	void addTile(Tiles* a);
	void addObject(Objects* a);
	void addPlayer(Player* a);


	void rewind();
	Actor* next();
	Actor* current();
	void update();
	int num_actors();

protected:
	Game* game;
	list<Actor*> actors;
	list<Actor*>::iterator actors_iter;

	list<Tiles*> tiles;
	list<Tiles*>::iterator tiles_iter;

	list<Objects*> objects;
	list<Objects*>::iterator objects_iter;

	list<Player*> players;
	list<Player*>::iterator players_iter;

};

#endif