#ifndef SWORDCLASS_H
#define SWORDCLASS_H


#include "objectsClass.h"

class SwordClass : public Objects {
protected:

	int idSword;

	int damage;

	int durability;

	int attackSpeed;

	int attackArea;

	bool inMap;


public:
	SwordClass(int, int, int, int , int, int ,int, bool, string, string);

	void draw();

	void update();


};

#endif