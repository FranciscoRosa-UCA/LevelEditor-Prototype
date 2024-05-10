#ifndef CONTROLMANAGER_H
#define CONTROLMANAGER_H

#include <vector>

#include "keyboardClass.h"
#include "cameraClass.h"

#include "Actor.h"

class ControlManager
{
private:
	//Camera Free Coords
	int x = 0, y = 0;

public:
	Keyboard* KeyboardControl;
	Camera* CameraControl;

	ControlManager();
	~ControlManager();

	void update();
	void set_keyboard(Actor*);
	void set_Camera(Actor*);

	void set_CameraArrowFree();

	void reset_Camera();

protected:

};
#endif









/*
#ifndef CONTROLMANAGER_H
#define CONTROLMANAGER_H

#include "game.h"

class ControlManager
{
private:

	bool ControlsAvailable;

public:
	ControlManager(Game*);
	void set_Controls();
	void set_KeyBoardPlayer(); //Unico para Player
	void set_Controls_ON_OF(bool);

protected:
	Game* game;



};

#endif
*/