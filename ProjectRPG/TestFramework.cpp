#include "TestFramework.h"

void TestFrameWork::main()
{
	/*
	ALLEGRO_BITMAP* bmp;
	//ALLEGRO_BITMAP* tmp;
	bmp = al_load_bitmap("assets/players/nave.bmp");



	Map MAP0(0);
	MAP0.loadMap();
	for (MAP0.MapTiles_iterator = MAP0.MapTiles.begin(); MAP0.MapTiles_iterator != MAP0.MapTiles.end(); MAP0.MapTiles_iterator++) {
		actor_manager->add((*MAP0.MapTiles_iterator));
	}


	Player* P = new Player(500, 500, 0);  //se dibujara primero, por ser el ultimo actor en el manager
	actor_manager->add(P);

	Buttons* B1 = new Buttons(30, 30, 0, this, al_load_bitmap("assets/buttons/button_false.png"), al_load_bitmap("assets/buttons/button_true.png"));
	actor_manager->add(B1);


	for (int i = 0; i < 6; i++) {
		GrassTile* a = new GrassTile(i * 128, 172);
		actor_manager->add(a);
		MAP0.MapTiles.push_back(a);
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {
			DirtTile* a = new DirtTile(j * 128, (i * 128)+ 300);
			actor_manager->add(a);
			MAP0.MapTiles.push_back(a);
		}
	}
	

	ALLEGRO_KEYBOARD_STATE keyboardState;
	bool exitloop = false;


	
	while (!exitloop) {

		MAP0.deleteMap();

		al_get_keyboard_state(&keyboardState);
		if (al_key_down(&keyboardState, ALLEGRO_KEY_ESCAPE)) exitloop = true;
		if (Event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) exitloop = true;




		update();

		MAP0.saveMap();


		if (B1->Pressed() ) {
			cout << "toca2" << endl;
		}

	}

	//al_save_bitmap("assets/mapTiles/grass.png", tmp);

	al_destroy_bitmap(bmp);

	*/

}