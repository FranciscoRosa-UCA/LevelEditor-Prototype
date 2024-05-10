#ifndef PANELEDITORCLASS_H
#define PNAELEDITORCLASS_H

#include "actor.h"
#include "game.h"
#include "controlManager.h"

class PanelEditor : public Actor
{
private:
	Game* game;
public:
	PanelEditor(int, int, ALLEGRO_BITMAP*, Game*);

	void draw();


};

#endif // !PANELEDITORCLASS_H

