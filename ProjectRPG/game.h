#ifndef GAME_H
#define GAME_H

#include <allegro5/allegro5.h>

class ActorManager;
class StageManager;
class ControlManager;
class ColliderManager;

class Game
{
public:
	Game();
	virtual ~Game();
	ActorManager* actor_manager;
	StageManager* stage_manager;
	ControlManager* control_manager;
	ColliderManager* collider_manager;

	virtual void init(int, int);
	virtual void main();
	void set_name(const char*);
	const char* get_name();
	void shutdown(const char*);


	ALLEGRO_EVENT_QUEUE* event_queue;
	ALLEGRO_EVENT Event;

	ALLEGRO_KEYBOARD_STATE EventKEY;
	ALLEGRO_MOUSE_STATE mouseState;
	
	bool mousePressed;

	ALLEGRO_TIMER* secondTimer;

protected:
	const char* name;
	ALLEGRO_DISPLAY* ventana;

	ALLEGRO_TIMER* FPS;



	void update();
	int w, h;

private:
	void start();
	void create_actormanager();
	void create_stagemanager();
	void create_controlmanager();
	void create_collidermanager();

};

#endif