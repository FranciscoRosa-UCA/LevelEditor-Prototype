#ifndef GAMEEDITORCLASS_H
#define GAMEEDITORCLASS_H

#include "menuClass.h"
#include "actorManager.h"
#include "controlManager.h"
#include "panelEditorClass.h"


class GameEditor
{
private:

	// *********************IMAGENES*********************
	ALLEGRO_BITMAP* Base1 = al_load_bitmap("assets/editor/base.png"); 

	ALLEGRO_BITMAP* delf = al_load_bitmap("assets/editor/delete_false.png");
	ALLEGRO_BITMAP* delv = al_load_bitmap("assets/editor/delete_true.png");

	ALLEGRO_BITMAP* takef = al_load_bitmap("assets/editor/take_false.png");
	ALLEGRO_BITMAP* takev = al_load_bitmap("assets/editor/take_true.png");

	ALLEGRO_BITMAP* Bgrassf = al_load_bitmap("assets/editor/grass_false.png");
	ALLEGRO_BITMAP* Bgrassv = al_load_bitmap("assets/editor/grass_true.png"); 
	ALLEGRO_BITMAP* Bdirtf = al_load_bitmap("assets/editor/dirt_false.png"); 
	ALLEGRO_BITMAP* Bdirtv = al_load_bitmap("assets/editor/dirt_true.png"); 

	ALLEGRO_BITMAP* Bbb1_f = al_load_bitmap("assets/editor/bb1_f.png"); 
	ALLEGRO_BITMAP* Bbb1_v = al_load_bitmap("assets/editor/bb1_v.png");

	ALLEGRO_BITMAP* Bbb2_f = al_load_bitmap("assets/editor/bb2_f.png");
	ALLEGRO_BITMAP* Bbb2_v = al_load_bitmap("assets/editor/bb2_v.png");


	//***************************************************************

	//*********************BUTTONS*********************

	PanelEditor* BasePanel1;  //PANEL PARA BOTONES 1

	Buttons_Static* DelAct;
	//Buttons_Static* MoveInMap;
	//Buttons_Static* showGrid;
	Buttons_Static* MoveAct;

	Buttons_Static* BP_0;  // BUTTON CREATE GRASS
	Buttons_Static* BP_1; // BUTTON CREATE DIRT
	Buttons_Static* BPBb_1; // BUTTON CREATE Bb1
	Buttons_Static* BPBb_2; // BUTTON CREATE Bb2

	//***************************************************************
	bool activePanel = false;

	Menu* MenuGame;
	bool HandActive;
	bool Taking;
	bool Moving;
	bool Deleting;

	bool Press_Button;
	int time_Wait = 0;
	bool time_Waiting = false;


public:
	GameEditor(Menu*);
	~GameEditor();

	void takeActor(Actor*);
	void destroyActor(Actor*);

	void show_Tools1();
	void add_Tools1();
	void destroy_Tools1();


	void show_Tools2();	
	void add_Tools2();
	void destroy_Tools2();


};

#endif
