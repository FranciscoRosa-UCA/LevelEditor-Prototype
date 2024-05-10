#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

#include "actormanager.h"
#include "stagemanager.h"
#include "controlManager.h"
#include "colliderManager.h"

#include "game.h"
#include <iostream>

Game::Game()
{
	actor_manager = NULL;
	stage_manager = NULL;
	control_manager = NULL;
	collider_manager = NULL;

	mousePressed = false;


	al_init();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();
	al_install_mouse();
	al_install_keyboard();
	al_init_image_addon();

}

Game::~Game()
{

}

void Game::init(int w, int h)
{

	this->w = w;
	this->h = h;

	if (!al_init())
	{
		shutdown("No se pudo inicializar modo grafico");
		return;
	}


	ventana = al_create_display(w, h);
	FPS = al_create_timer(1.0 / 30);
	event_queue = al_create_event_queue();
	al_set_window_title(ventana, name);



	FPS = al_create_timer(1.0 / 60);
	secondTimer = al_create_timer(1.0);

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_timer_event_source(FPS));
	al_register_event_source(event_queue, al_get_timer_event_source(secondTimer));

	al_register_event_source(event_queue, al_get_display_event_source(ventana));

	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_start_timer(FPS);
	al_start_timer(secondTimer);

	//al_set_color_depth(col);

	create_actormanager();
	create_stagemanager();
	create_controlmanager();
	create_collidermanager();
	start();
}

void Game::shutdown(const char* message)
{
	delete actor_manager;
	delete stage_manager;
	delete control_manager;
	delete collider_manager;

	al_destroy_display(ventana);
	al_destroy_event_queue(event_queue);
	al_destroy_timer(FPS);
	al_destroy_timer(secondTimer);


	std::cout << name << std::endl;
	std::cout << message << std::endl;

}

void Game::create_actormanager()
{
	actor_manager = new ActorManager(this);
}

void Game::create_stagemanager()
{
	stage_manager = new StageManager(this, w, h);
}

void Game::create_controlmanager() 
{
	control_manager = new ControlManager;

}

void Game::create_collidermanager() {
	collider_manager = new ColliderManager(this);
}

void Game::start()
{
	main();
	shutdown("Gracias por jugar");
}

void Game::main()
{

}

void Game::set_name(const char* n)
{
	this->name = n;
	al_set_window_title(ventana, name);

}

const char* Game::get_name()
{
	return this->name;
}

void Game::update()
{
	//al_draw_text();

	al_wait_for_event(event_queue, &Event); // no avanza el ciclo hasta escuchar un evento FPS o SecondTimer
	if (Event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
		if (Event.mouse.button & 1) {
			mousePressed = true;
		}

	}
	if (Event.type == ALLEGRO_EVENT_TIMER) {
		if (Event.timer.source == FPS) {

			actor_manager->update();

			control_manager->update();

			stage_manager->update();

			mousePressed = false;

		}
		if (Event.timer.source == secondTimer) {

			//cout << "Actoresactuales " << actor_manager->num_actors() << endl;

		}

	}


}

