#include "actor.h"
#include "actormanager.h"

ActorManager::ActorManager(Game* g)
{
	game = g;
}
ActorManager::~ActorManager()
{
	list<Actor*>::iterator tmp_actors_iter;

	for (tmp_actors_iter = actors.begin(); tmp_actors_iter != actors.end(); )
	{
		cout << "a1" << endl;
		(*tmp_actors_iter)->~Actor();
		delete (*tmp_actors_iter);
		tmp_actors_iter = actors.erase(tmp_actors_iter);
		cout << "a2" << endl;

	}

}

void ActorManager::add(Actor* a)
{
	actors.push_back(a);


}

void ActorManager::addTile(Tiles* a)
{
	tiles.push_back(a);
	add(a);

}

void ActorManager::addObject(Objects* a)
{
	objects.push_back(a);
	add(a);

}
void ActorManager::addPlayer(Player* a)
{
	players.push_back(a);
	add(a);

}

void ActorManager::del(Actor* a)
{
	list<Actor*>::iterator tmp_actors_iter;
	tmp_actors_iter = find(actors.begin(), actors.end(), a);
	if (tmp_actors_iter != actors.end()) {
		actors.erase(tmp_actors_iter);
	}
}

void ActorManager::destroy(Actor* a)
{
	list<Actor*>::iterator tmp_actors_iter;
	tmp_actors_iter = find(actors.begin(), actors.end(), a);
	if (tmp_actors_iter != actors.end()) {

		(*tmp_actors_iter)->~Actor();
		delete (*tmp_actors_iter);
		tmp_actors_iter = actors.erase(tmp_actors_iter);

	}
}

void ActorManager::destroyAll() {

	list<Actor*>::iterator tmp_actors_iter;
	for (tmp_actors_iter = actors.begin(); tmp_actors_iter != actors.end(); )
	{
			(*tmp_actors_iter)->~Actor();
			delete (*tmp_actors_iter);
			tmp_actors_iter = actors.erase(tmp_actors_iter);

	}

}

void ActorManager::rewind()
{
	actors_iter = actors.begin();
}

Actor* ActorManager::next()
{
	Actor* tmp_a;
	if ( actors_iter == actors.end() ) return NULL;
	tmp_a = *actors_iter;
	actors_iter++;
	return tmp_a;
}

Actor* ActorManager::current()
{
	if (actors_iter == actors.end()) return NULL;
	else
		return *actors_iter;
}

int ActorManager::num_actors()
{
	return actors.size();
}

void ActorManager::update()
{
	list<Actor*>::iterator tmp_iter;
	for (tmp_iter = actors.begin(); tmp_iter != actors.end(); tmp_iter++)
		(*tmp_iter)->update();
		
}
