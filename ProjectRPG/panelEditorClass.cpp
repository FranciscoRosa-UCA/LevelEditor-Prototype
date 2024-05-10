#include "panelEditorClass.h"

PanelEditor::PanelEditor(int x, int y, ALLEGRO_BITMAP* sprite, Game* game) {
	this->x = x;
	this->y = y;
	this->game = game;
	this->sprite_base = sprite;
	this->typeActor = "BasePanel";
}

void PanelEditor::draw(){
	al_draw_bitmap(sprite_base, x + game->control_manager->CameraControl->cameraPosition[0], y + game->control_manager->CameraControl->cameraPosition[1], NULL);
}