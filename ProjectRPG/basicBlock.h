#ifndef BASICBLOCK_H
#define BASICBLOCK_H

#include "actor.h"
#include "tilesClass.h"

class BasicBlock : public Tiles {
public:
	
	BasicBlock(int, int, int, Game*);

	void draw();
	void update();

	int get_w();
	int get_h();
};

#endif