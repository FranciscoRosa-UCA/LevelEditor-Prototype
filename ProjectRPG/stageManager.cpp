#include "actor.h"
#include "actormanager.h"
#include "stagemanager.h"
#include "controlManager.h"

#include <iostream>
using namespace std;

StageManager::StageManager(Game* g, int w, int h)
{
	game = g;
	width = w;
	height = h;

}

StageManager::~StageManager()
{
	
}



void StageManager::update()
{
	draw();
}

void StageManager::draw()
{
	Actor* tmp;
	game->actor_manager->rewind();

	float CamX1 = game->control_manager->CameraControl->cameraPosition[0];
	float CamY1 = game->control_manager->CameraControl->cameraPosition[1];
	float CamX2 = game->control_manager->CameraControl->cameraPosition[2];
	float CamY2 = game->control_manager->CameraControl->cameraPosition[3];

	al_clear_to_color(al_map_rgb(0, 0, 0));

	while ( (tmp = game->actor_manager->next() ) != NULL)
	{
		
		if( tmp->get_typeActor() != "Buttons_Static" && !(
			tmp->get_x() < CamX1- tmp->get_w() || tmp->get_y() < CamY1 - tmp->get_h() ||
			tmp->get_x() > CamX2 + tmp->get_w() || tmp->get_y() > CamY2 + tmp->get_h()
			) )
		tmp->draw();
		else {
			tmp->draw();

		}

	}



	al_flip_display();

}