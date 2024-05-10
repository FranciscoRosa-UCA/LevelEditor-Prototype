#ifndef STAGEMANAGER_H
#define STAGEMANAGER_H
//#define SCREEN_W = 1080
//#define SCREEN_H = 720

#include <allegro5/allegro5.h>

#include "game.h"


class StageManager
{
public:
	StageManager(Game* g, int w, int h);
	~StageManager();

	void update();
	void draw();

protected:
	Game* game;
	ALLEGRO_BITMAP* buffer;
	int width, height;

};

#endif