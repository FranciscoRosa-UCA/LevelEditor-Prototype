#include "colliderManager.h"
#include "ColliderClass.h"

#include <iostream>
using namespace std;

ColliderManager::ColliderManager(Game* g) {
	this->game = g;
}

ColliderManager::~ColliderManager() {
	list<Collider*>::iterator tmp_Collider;

	for (tmp_Collider = colliders_bag.begin(); tmp_Collider != colliders_bag.end(); )
	{
		cout << "b" << endl;
		(*tmp_Collider)->~Collider();
		delete (*tmp_Collider);
		tmp_Collider = colliders_bag.erase(tmp_Collider);
		cout << "c" << endl;

	}
}

void ColliderManager::add(Collider* C) {

	colliders_bag.push_back(C);

}

void ColliderManager::del(Collider* C) {
	list<Collider*>::iterator tmp_Collider;
	tmp_Collider = find(colliders_bag.begin(), colliders_bag.end(), C);
	if (tmp_Collider != colliders_bag.end()) {
		colliders_bag.erase(tmp_Collider);
	}
}

void ColliderManager::rewind()
{
	colliders_bag_iterator = colliders_bag.begin();
}

Collider* ColliderManager::next()
{
	Collider* tmp;
	if (colliders_bag_iterator == colliders_bag.end()) return NULL;
	tmp = *colliders_bag_iterator;
	colliders_bag_iterator++;
	return tmp;
}

