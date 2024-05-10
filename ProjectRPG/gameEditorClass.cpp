#include "gameEditorClass.h"
#include "mapClass.h"

GameEditor::GameEditor(Menu* MenuGame) {
	this->MenuGame = MenuGame;
	HandActive = false;
	Taking = false;
	Moving = false;
	Deleting = false;


	BasePanel1 = new PanelEditor(0, 0, Base1, MenuGame);

	DelAct = new Buttons_Static(35, 30, 0, MenuGame, delf, delv);
	//MoveInMap;
	//showGrid;
	MoveAct = new Buttons_Static(165, 30, 1, MenuGame, takef, takev);

	BP_0 = new Buttons_Static(35, 120, 2, MenuGame, Bgrassf, Bgrassv);
	BP_1 = new Buttons_Static(165, 120, 3, MenuGame, Bdirtf, Bdirtv);
	BPBb_1 = new Buttons_Static(35, 235, 4, MenuGame, Bbb1_f, Bbb1_v);
	BPBb_2 = new Buttons_Static(105, 235, 5, MenuGame, Bbb2_f, Bbb2_v);

}

GameEditor::~GameEditor() {
	al_destroy_bitmap(Base1);

}

void GameEditor::takeActor(Actor* ThisActor)
{
	al_get_mouse_state(&MenuGame->mouseState);

	int Mx = MenuGame->control_manager->CameraControl->cameraPosition[0] + al_get_mouse_state_axis(&MenuGame->mouseState, 0);
	int My = MenuGame->control_manager->CameraControl->cameraPosition[1] + al_get_mouse_state_axis(&MenuGame->mouseState, 1);

	if (ThisActor->taked == false && HandActive == false ) {

		if (Mx >= ThisActor->get_x() && Mx <= ThisActor->get_x() + ThisActor->get_w() && 
			My >= ThisActor->get_y() && My <= ThisActor->get_y() + ThisActor->get_h()) {

			bool TouchPanel = false;
			if (activePanel && Mx < MenuGame->control_manager->CameraControl->cameraPosition[0] + 300) {
				TouchPanel = true;
			}

			if ((MenuGame->mousePressed) && !TouchPanel) {
				
				cout << "TOMADO" << endl;
				if(Mx >= 0 ) ThisActor->set_x(Mx - Mx % ThisActor->get_w());
				else ThisActor->set_x(Mx - Mx % ThisActor->get_w() - ThisActor->get_w());

				if(My >= 0) ThisActor->set_y(My - My % ThisActor->get_w());
				else ThisActor->set_y(My - My % ThisActor->get_w() - ThisActor->get_w());

				//ThisActor->ThisCollider->posX = Mx;
				//ThisActor->ThisCollider->posY = My;
				ThisActor->taked = true;
				HandActive = true;

				Press_Button = true;
				time_Waiting = true;
			}
			else Press_Button = false;


		}

		if (time_Waiting && time_Wait < 100) time_Wait++; // tiempo de espera antes de reaccionar a otra llamada
		else {
			time_Wait = 0;
			time_Waiting = false;
		}
	
	}
	else {
		if (ThisActor->taked == true) {

				bool isColling = false;

				if (Mx >= 0) ThisActor->set_x(Mx - Mx % ThisActor->get_w());
				else ThisActor->set_x(Mx - Mx % ThisActor->get_w() - ThisActor->get_w() );

				if (My >= 0) ThisActor->set_y(My - My % ThisActor->get_w());
				else ThisActor->set_y(My - My % ThisActor->get_w() - ThisActor->get_w() );

				//ThisActor->ThisCollider->posX = Mx - Mx % 128;
				//ThisActor->ThisCollider->posY = My - My % 128;

				Actor* tmp; 
				MenuGame->actor_manager->rewind();
				while ((tmp = MenuGame->actor_manager->next()) != NULL)
				{
					if (ThisActor != tmp && 
						ThisActor->get_typeActor()  == tmp->get_typeActor() &&
						ThisActor->get_x() == tmp->get_x() && 
						ThisActor->get_y() == tmp->get_y()) 
					{
						isColling = true;
					}
				}

				bool TouchPanel = false;
				if (activePanel && Mx < MenuGame->control_manager->CameraControl->cameraPosition[0] + 300) {
					TouchPanel = true;
				}

				if ( (MenuGame->mousePressed) && !isColling && !TouchPanel) {
					cout << "SOLTADO" << endl;
					ThisActor->taked = false;
					HandActive = false;

					Press_Button = true;
					time_Waiting = true;
				}
				else Press_Button = false;


				if (time_Waiting && time_Wait < 100) time_Wait++; // tiempo de espera antes de reaccionar a otra llamada
				else {
					time_Wait = 0;
					time_Waiting = false;
				}


		}
	}
}

void GameEditor::destroyActor(Actor* ThisActor) {
	al_get_mouse_state(&MenuGame->mouseState);

	int Mx = MenuGame->control_manager->CameraControl->cameraPosition[0] + al_get_mouse_state_axis(&MenuGame->mouseState, 0);
	int My = MenuGame->control_manager->CameraControl->cameraPosition[1] + al_get_mouse_state_axis(&MenuGame->mouseState, 1);

	if (ThisActor->taked == false && HandActive == false) {

		if (Mx >= ThisActor->get_x() && Mx <= ThisActor->get_x() + ThisActor->get_w() &&
			My >= ThisActor->get_y() && My <= ThisActor->get_y() + ThisActor->get_h()) {

			bool TouchPanel = false;
			if (activePanel && Mx < MenuGame->control_manager->CameraControl->cameraPosition[0] + 300) {
				TouchPanel = true;
			}

			if ((MenuGame->mousePressed) && !TouchPanel) {

				MenuGame->actor_manager->destroy(ThisActor);


				Press_Button = true;
				time_Waiting = true;
			}
			else Press_Button = false;


		}

		if (time_Waiting && time_Wait < 100) time_Wait++; // tiempo de espera antes de reaccionar a otra llamada
		else {
			time_Wait = 0;
			time_Waiting = false;
		}

	}


}

void GameEditor::show_Tools1() {


	if (!HandActive) {
		al_get_mouse_state(&MenuGame->mouseState);

		int Mx = MenuGame->control_manager->CameraControl->cameraPosition[0] + al_get_mouse_state_axis(&MenuGame->mouseState, 0);
		int My = MenuGame->control_manager->CameraControl->cameraPosition[1] + al_get_mouse_state_axis(&MenuGame->mouseState, 1);
		
		Actor* tmp = NULL;

		bool PressOp = false;

		if (DelAct->Pressed()) {

			Moving = false;
			Taking = false;

			Deleting = true;


		}
		if (MoveAct->Pressed()) {

			Deleting = false;
			Taking = false;

			Moving = true;

		}


		if (BP_0->Pressed()) {
			tmp = new GrassTile(0, 0, MenuGame);
			PressOp = true;
		}

		if (BP_1->Pressed()) {
			tmp = new DirtTile(0, 0, MenuGame);
			PressOp = true;

		}


		if (PressOp) {

			Deleting = false;
			Moving = false;


			if (Mx >= 0) tmp->set_x(Mx - Mx % tmp->get_w());
			else tmp->set_x(Mx - Mx % tmp->get_w() - tmp->get_w());

			if (My >= 0) tmp->set_y(My - My % tmp->get_w());
			else tmp->set_y(My - My % tmp->get_h() - tmp->get_h());

			MenuGame->actor_manager->add(tmp);

			tmp->taked = true;
			HandActive = true;
			Taking = true;
		}


		


	}

	Actor* tmp = NULL;

	MenuGame->actor_manager->rewind();
	while ((tmp = MenuGame->actor_manager->next()) != NULL)
	{
		if (!(tmp->get_typeActor() == "Buttons_Static" || tmp->get_typeActor() == "BasePanel")) {
			if (Moving) {
				takeActor(tmp);
			}
			if (Taking) {
				if (tmp->taked) {
					takeActor(tmp);
					if (!tmp->taked) {
						Taking = false;
					}
				}

			}
			if (Deleting) {
				destroyActor(tmp);
			}
		}
	}



}

void GameEditor::add_Tools1() {
	MenuGame->actor_manager->add(BasePanel1);
	MenuGame->actor_manager->add(BP_0);
	MenuGame->actor_manager->add(BP_1);
	//MenuGame->actor_manager->add(BPBb_1);
	//MenuGame->actor_manager->add(BPBb_2);
	MenuGame->actor_manager->add(DelAct);
	MenuGame->actor_manager->add(MoveAct);
	activePanel = true;
}

void GameEditor::destroy_Tools1() {
	MenuGame->actor_manager->del(BasePanel1);
	MenuGame->actor_manager->del(BP_0);
	MenuGame->actor_manager->del(BP_1);
	//MenuGame->actor_manager->del(BPBb_1);
	//MenuGame->actor_manager->del(BPBb_2);
	MenuGame->actor_manager->del(DelAct);
	MenuGame->actor_manager->del(MoveAct);
	activePanel = false;

}