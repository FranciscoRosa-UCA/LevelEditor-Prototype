#include "menuClass.h"
#include "mapClass.h"
#include "gameEditorClass.h"

#include "swordClass.h"


void Menu::main() {

	Buttons_Static* B1 = new Buttons_Static(30, 30, 0, this, al_load_bitmap("assets/buttons/play_false.png"), al_load_bitmap("assets/buttons/play_true.png"));
	Buttons_Static* B2 = new Buttons_Static(100, 200, 1, this, al_load_bitmap("assets/buttons/base_false.png"), al_load_bitmap("assets/buttons/base_true.png"));
	Buttons_Static* B3 = new Buttons_Static(170, 30, 2, this, al_load_bitmap("assets/buttons/editor_false.png"), al_load_bitmap("assets/buttons/editor_true.png"));

	actor_manager->add(B1);
	actor_manager->add(B2);
	actor_manager->add(B3);

	while (!exitloop) {
		al_get_keyboard_state(&keyboardState);
		if (al_key_down(&keyboardState, ALLEGRO_KEY_ESCAPE)) exitloop = true;
		if (Event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) exitloop = true;

		update();

		if (B1->Pressed()) {
			actor_manager->del(B1);
			actor_manager->del(B2);
			actor_manager->del(B3);
			GameIn();
			actor_manager->add(B1);
			actor_manager->add(B2);
			actor_manager->add(B3);
		}
		if (B2->Pressed()) {
			cout << "Buttons: " << actor_manager->num_actors() << endl;

		}
		if (B3->Pressed()) {
			actor_manager->del(B1);
			actor_manager->del(B2);
			actor_manager->del(B3);
			EditorIn();
			actor_manager->add(B1);
			actor_manager->add(B2);
			actor_manager->add(B3);
		}
	}

}

void Menu::GameIn() {

	Map MAP(this);

	MAP.loadMap();


	// **********************BOTONES**********************
	//Salir
	Buttons_Static* B1 = new Buttons_Static(0, 0, 0, this, al_load_bitmap("assets/buttons/exit_false.png"), al_load_bitmap("assets/buttons/exit_true.png"));
	actor_manager->add(B1);	

	//Guardar
	Buttons_Static* B2 = new Buttons_Static(240, 30, 1, this, al_load_bitmap("assets/buttons/save_false.png"), al_load_bitmap("assets/buttons/save_true.png"));
	actor_manager->add(B2);

	//Mostrar Coordenadas
	Buttons_Static* B3 = new Buttons_Static(410, 30, 2, this, al_load_bitmap("assets/buttons/base_false.png"), al_load_bitmap("assets/buttons/base_true.png"));
	actor_manager->add(B3);

	//ESPADA PRUEBA
	//SwordClass* espada1 = new SwordClass(0, 0, 0, 50, 100, 1, 10, false, "SUPER SWORD", "master_sword");
	//actor_manager->add(espada1);

	//COLLIDER PRUEBA
	/*
	Collider* tmpC = new Collider(100, 100, 200, 200);
	collider_manager->add(tmpC);
	*/
/*
	BasicBlock* b1 = new BasicBlock(-100, -100, 1, this);
	actor_manager->add(b1);


	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			actor_manager->add(new BasicBlock((i*16*3), (j*16*3)-500, (rand()%17)+2, this));

		}
	}
*/

	Actor* tmp;
	Actor* Player1 = NULL; //Guardar el Player en una variable
	actor_manager->rewind();
	while ((tmp = actor_manager->next()) != NULL)
	{
		if (tmp->getID() == 0 and tmp->get_typeActor() == "Players") {
			Player1 = tmp;
		}
	}
	if (Player1 != NULL) {
		control_manager->set_keyboard(Player1);
	}
	else {
		Player1 = new Player(1, 1, 1, this);
		actor_manager->add(Player1);
		control_manager->set_keyboard(Player1);

	}

	while (!exitloop) {



		al_get_keyboard_state(&keyboardState);
		if (al_key_down(&keyboardState, ALLEGRO_KEY_ESCAPE)) exitloop = true;
		if (Event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) exitloop = true;


		update();


		if (B1->Pressed()) {
			cout << "SalirGameIn" << endl;
			

			actor_manager->destroyAll();

			MAP.DestroyAll();
			control_manager->reset_Camera();
			
			return;
		}
		if (B2->Pressed()) {
			MAP.saveMap();

		}
		if (B3->Pressed()) {
			cout << "\n\nCOORDENADAS\n";
			cout << " Camara: "
				<< control_manager->CameraControl->cameraPosition[0] << ", "
				<< control_manager->CameraControl->cameraPosition[1] << ", "
				<< control_manager->CameraControl->cameraPosition[2] << ", "
				<< control_manager->CameraControl->cameraPosition[3] << endl;

			Actor* tmp; //Guardar el Player en una variable
			actor_manager->rewind();
			while ((tmp = actor_manager->next()) != NULL)
			{
				cout << "x: " << tmp->get_x() << " y: " << tmp->get_y() << endl;
			}
			cout << "Player: " << Player1->get_x() << ", " << Player1->get_y() << endl;

		}

	}


}

void Menu::EditorIn() {
	

	Map MAP(this);
	GameEditor EDITOR(this);

	MAP.loadMap();


	// **********************BOTONES**********************
	//Salir
	Buttons_Static* B1 = new Buttons_Static(426, 20, 0, this, al_load_bitmap("assets/buttons/exit_false.png"), al_load_bitmap("assets/buttons/exit_true.png"));
	actor_manager->add(B1);

	//Guardar
	Buttons_Static* B2 = new Buttons_Static(551, 20, 1, this, al_load_bitmap("assets/buttons/save_false.png"), al_load_bitmap("assets/buttons/save_true.png"));
	actor_manager->add(B2);

	//Mostrar TOOLS1
	Buttons_Static* B3 = new Buttons_Static(676, 20, 2, this, al_load_bitmap("assets/editor/panel_false.png"), al_load_bitmap("assets/editor/panel_true.png"));
	actor_manager->add(B3);
	bool PressB3 = false;


/*
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			Actor* xd = new BasicBlock((i * 16 * 3), (j * 16 * 3) - 500, (rand() % 17) + 1, this);
			actor_manager->add(xd);
		}
	}
*/

	while (!exitloop) {

		control_manager->set_CameraArrowFree();

		al_get_keyboard_state(&keyboardState);
		if (al_key_down(&keyboardState, ALLEGRO_KEY_ESCAPE)) exitloop = true;
		if (Event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) exitloop = true;

		update();

		//cout << "Actores: " << actor_manager->num_actors() << endl;

		if (B1->Pressed()) {  //BOTON SALIR DE EDITOR
			actor_manager->destroyAll(); //Destruye todo y regresa a menu
			EDITOR.destroy_Tools1();

			control_manager->reset_Camera();

			return;
		}
		if (B2->Pressed()) {  //BOTON GUARDAR MAPA
			MAP.saveMap();

		}

		if (!PressB3) { // BOTON MOSTRAR O OCULTAR PANEL DE TILES EDITOR
			if (B3->Pressed()) {
				EDITOR.add_Tools1();
				PressB3 = true;
			}
			EDITOR.show_Tools1();

		}
		else {
			EDITOR.show_Tools1();
			if (B3->Pressed()) {
				EDITOR.destroy_Tools1();
				PressB3 = false;
			}
		}


	}



}