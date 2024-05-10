#include "player.h"
#include "controlManager.h"
#include "colliderManager.h"
#include <allegro5/allegro_primitives.h>

#include <iostream>
using namespace std;

Player::Player(int x, int y, int id, Game* g) {
	this->id = id;
	this->x = x;
	this->y = y;
	Past_state[0] = x;
	Past_state[1] = y;
	this->game = g;
	this->sprite_base = NULL;
	this->typeActor = "Players";
	sprite_base = al_load_bitmap("assets/players/personaje.png");


	this->ThisCollider = new Collider(Past_state[0] +10, Past_state[1] +10, get_w()-10, get_h()-10);
	//game->collider_manager->add(ThisCollider);


	//ReadPlayer(this->id, &this->x, &this->y, "players.txt");
}

Player::~Player() {
	cout << "DestroyedPlayer" << endl;
	al_destroy_bitmap(sprite_base);
	delete ThisCollider;
}

void Player::update() {
	
	if(ControllableKeyboard) do_action();

	logic();


}

void Player::logic() {


	Collider* tmp;
	game->collider_manager->rewind();
	while ((tmp = game->collider_manager->next()) != NULL) {
		if (ThisCollider->CollingTo(tmp) ) {
			x = Past_state[0];
			y = Past_state[1];
			ThisCollider->set_x(Past_state[0] + 10);
			ThisCollider->set_y(Past_state[1] + 10);
			//cout << "XD" << endl;
			//cout << ThisCollider << endl;
			//cout << tmp << endl;

		}

	}

	Past_state[0] = x;
	Past_state[1] = y;

}


void Player::do_action()
{


	ALLEGRO_KEYBOARD_STATE Kstate = game->control_manager->KeyboardControl->KeyboardState;

	if (al_key_down(&Kstate, ALLEGRO_KEY_W)) {
		y -= 5;
		direction = 3;
		moving = true;

	}
	if (al_key_down(&Kstate, ALLEGRO_KEY_S)) {
		y += 5;
		direction = 0;
		moving = true;

	}
	if (al_key_down(&Kstate, ALLEGRO_KEY_A)) {
		x -= 5;
		direction = 1;
		moving = true;

	}
	if (al_key_down(&Kstate, ALLEGRO_KEY_D)) {
		x += 5;
		direction = 2;
		moving = true;

	}
	if (moving)
		animation++;

	moving = false;

	if (animation > 29) animation = 0;

	ThisCollider->set_x(x + 10);
	ThisCollider->set_y(y + 10);

	game->control_manager->set_Camera(this);

}



void Player::draw() {

	al_draw_bitmap_region(sprite_base, (animation/10) * 48, direction * 48, 48, 48, x, y, 0);

	//ThisCollider->showCollider();


	//al_draw_scaled_bitmap(sprite, 0, 0, 900, 520, 100, 100, 900/2, 520/2, 0);

}

int Player::get_w() {
	return 40;
}

int Player::get_h() {
	return 40;
}

void Player::set_image(ALLEGRO_BITMAP* sprite)
{
	this->sprite_base = sprite;
}

void Player::SaveState() {
	//WritePlayer(this->id, this->x, this->y, "players.txt");
}
