#include "mapClass.h"
#include <iostream>
using namespace std;

Map::Map(Menu* MenuGame) {

	this->id = 0;
	this->MenuGame = MenuGame;

}

Map::~Map() {
}

void Map::createMap() {
	if (id == 0) Map0();

}

void Map::saveMap() {

	deleteMap();

	assign_Actors_To_Iterators(); 

	ofstream DataWrite;

	DataWrite.open(   ("saves/map" + to_string(this->id) + ".Kdata").c_str(), ios_base::app);
	
	save_Tiles(DataWrite);
	save_Objects(DataWrite);
	save_Players(DataWrite);

	cout << "passassas";

	clearIterators();

	DataWrite.close();

}

void Map::loadMap() {
	
	ifstream DataRead( ("saves/map" + to_string(this->id) + ".Kdata").c_str() );

	string TypeActor;
	string auxkey;

	for (int i = 0; i < 3; i++) { // El 3 es por cada Iter
		DataRead >> TypeActor >> auxkey;
		load_Tiles(DataRead, TypeActor);
		load_Objects(DataRead, TypeActor);
		load_Players(DataRead, TypeActor);
	}

	assign_Iterators_To_Actors();

	clearIterators();

	DataRead.close();
	
}


void Map::Map0() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			MapTiles.push_back(new GrassTile( i*128, j*128, MenuGame));

		}
	}


}

void Map::deleteMap() {
	ofstream DataWrite;

	DataWrite.open( ("saves/map" + to_string(this->id) + ".Kdata").c_str() , ios_base::out);
	DataWrite << "";
	DataWrite.close();

}


void Map::assign_Actors_To_Iterators() {

	Actor* tmp;
	MenuGame->actor_manager->rewind();

	while ((tmp = MenuGame->actor_manager->next()) != NULL)
	{

		if (tmp->get_typeActor() == "Tiles")
		{

			if (tmp->getID() == 0) MapTiles.push_back(new GrassTile(tmp->get_x(), tmp->get_y(), MenuGame));
			if (tmp->getID() == 1) MapTiles.push_back(new DirtTile(tmp->get_x(), tmp->get_y(), MenuGame));
			for (int i = 2; i <= 19; i++) {
				if (tmp->getID() == i) {
					MapTiles.push_back(
						new BasicBlock(tmp->get_x(), tmp->get_y(), i, MenuGame)
					);
				}
			}

			//else cout << "XD" << endl;
		}
		if (tmp->get_typeActor() == "Objects")
		{
			//if (tmp->getID() == 0) MapObjects.push_back(new             (tmp->get_x(), tmp->get_y()));

		}
		if (tmp->get_typeActor() == "Players")
		{
			if (tmp->getID() == 0) MapPlayers.push_back(new Player( tmp->get_x(), tmp->get_y(), tmp->getID(), MenuGame ) );


		}

		else {
			cout << tmp->get_typeActor() << endl;
		}

	}

}

void Map::assign_Iterators_To_Actors() {
	for (MapTiles_iterator = MapTiles.begin(); MapTiles_iterator != MapTiles.end(); MapTiles_iterator++) {
		if ((*MapTiles_iterator)->getID() == 0) MenuGame->actor_manager->add(new GrassTile((*MapTiles_iterator)->get_x(), (*MapTiles_iterator)->get_y(), MenuGame));
		if ((*MapTiles_iterator)->getID() == 1) MenuGame->actor_manager->add(new DirtTile((*MapTiles_iterator)->get_x(), (*MapTiles_iterator)->get_y(), MenuGame));
		for (int i = 2; i <= 19; i++) {
			if ((*MapTiles_iterator)->getID() == i) MenuGame->actor_manager->add(new BasicBlock((*MapTiles_iterator)->get_x(), (*MapTiles_iterator)->get_y(), i, MenuGame));
		}
	}

	/*
	for (MapObjects_iterator = MapObjects.begin(); MapObjects_iterator != MapObjects.end(); MapObjects_iterator++) {
		MenuGame->actor_manager->add((*MapObjects_iterator));
	}
	*/

	for (MapPlayers_iterator = MapPlayers.begin(); MapPlayers_iterator != MapPlayers.end(); MapPlayers_iterator++) {
		if ((*MapPlayers_iterator)->getID() == 0) MenuGame->actor_manager->add(new Player((*MapPlayers_iterator)->get_x(), (*MapPlayers_iterator)->get_y(), (*MapPlayers_iterator)->getID(), MenuGame));

	}

}


void Map::DestroyAll() {
	for (MapTiles_iterator = MapTiles.begin(); MapTiles_iterator != MapTiles.end(); MapTiles_iterator++ ) {
		MenuGame->actor_manager->destroy((*MapTiles_iterator));
	}

	
	for (MapObjects_iterator = MapObjects.begin(); MapObjects_iterator != MapObjects.end(); MapObjects_iterator++) {
		MenuGame->actor_manager->destroy((*MapObjects_iterator));
	}	
	

	for (MapPlayers_iterator = MapPlayers.begin(); MapPlayers_iterator != MapPlayers.end(); MapPlayers_iterator++) {
		MenuGame->actor_manager->destroy((*MapPlayers_iterator));
	}
	
}

void Map::clearIterators() {
	for (MapTiles_iterator = MapTiles.begin(); MapTiles_iterator != MapTiles.end(); ) {
		(*MapTiles_iterator)->~Tiles();
		delete (*MapTiles_iterator);
		MapTiles_iterator = MapTiles.erase(MapTiles_iterator);
	}

	//for (MapObjects_iterator = MapObjects.begin(); MapObjects_iterator != MapObjects.end(); ) {
		//MapObjects_iterator = MapObjects.erase(MapObjects_iterator);
	//}

	for (MapPlayers_iterator = MapPlayers.begin(); MapPlayers_iterator != MapPlayers.end(); ) {
		(*MapPlayers_iterator)->~Player();
		delete (*MapPlayers_iterator);
		MapPlayers_iterator = MapPlayers.erase(MapPlayers_iterator);
	}

}


void Map::load_Tiles(ifstream &DataRead, string TypeActor) {

	string k1,k2;

	if (TypeActor == "Tiles") {
		cout << TypeActor << endl << "{" << endl;

		DataRead >> k1;

		if ( k1 == "{") {

			Tiles* tmp;
			int id;
			int x;
			int y;

			while (DataRead >> id >> x >> y >> k2 && k2 == "},") {
				cout << k1 << id << ", " << x << ", " << y << k2 << endl;

				if (id == 0) {
					tmp = new GrassTile(x, y, MenuGame);
				}
				if (id == 1) {
					tmp = new DirtTile(x, y, MenuGame);
				}
				for (int i = 2; i <= 19; i++) {
					if (id == i) {
						tmp = new BasicBlock(x, y, id, MenuGame);
					}
				}
				
				MapTiles.push_back(tmp);

				DataRead >> k1;
			}

			if (k2 == "}") {
				if (id == 0) {
					tmp = new GrassTile(x, y, MenuGame);
				}
				if (id == 1) {
					tmp = new DirtTile(x, y, MenuGame);
				}
				for (int i = 2; i <= 19; i++) {
					if (id == i) {
						tmp = new BasicBlock(x, y, id, MenuGame);
					}
				}
				MapTiles.push_back(tmp);

			}

			cout << k1 << id << ", " << x << ", " << y << k2 << endl;

			DataRead >> k2; //lectura de "}" final de tipo

		}
		cout << "}" << endl;
		cout << "Count Tiles: " << MapTiles.size() << endl;
	}

}

void Map::save_Tiles(ofstream &DataWrite) {

	DataWrite <<
		"Tiles" << "\n" <<
		"{" << "\n";
	for (MapTiles_iterator = MapTiles.begin(); MapTiles_iterator != MapTiles.end();) {
		DataWrite <<
			"{ " <<
			(*MapTiles_iterator)->getID() << " " <<
			(*MapTiles_iterator)->get_x() << " " <<
			(*MapTiles_iterator)->get_y();
		MapTiles_iterator++;

		if (MapTiles_iterator != MapTiles.end()) {

			DataWrite << " }," << "\n";

		}
		else {
			DataWrite << " }" << "\n";
		}
	}
	DataWrite <<
		"}" << "\n";

}


void Map::load_Objects(ifstream& DataRead, string TypeActor) {

	string k1, k2;

	if (TypeActor == "Objects") {
		cout << TypeActor << endl << "{" << endl;

		DataRead >> k1;

		if (k1 == "{") {

			Actor* tmp;
			int id;
			int x;
			int y;

			while (DataRead >> id >> x >> y >> k2 && k2 == "},") {
				if (id == 0) {
				}
				if (id == 1) {
				}
				MapObjects.push_back(tmp);

				cout << k1 << id << x << y << k2 << endl;
				DataRead >> k1;
			}

			if (k2 == "}") {
				if (id == 0) {
				}
				if (id == 1) {
				}
				MapObjects.push_back(tmp);

			}

			cout << k1 << id << x << y << k2 << endl;

			DataRead >> k2; //lectura de "}" final de tipo

		}
		cout << "}" << endl;

	}

}

void Map::save_Objects(ofstream& DataWrite) {
	DataWrite <<
		"Objects" << "\n" <<
		"{" << "\n";
	for (MapObjects_iterator = MapObjects.begin(); MapObjects_iterator != MapObjects.end();) {
		DataWrite <<
			"{ " <<
			(*MapObjects_iterator)->getID() << " " <<
			(*MapObjects_iterator)->get_x() << " " <<
			(*MapObjects_iterator)->get_y();
		MapObjects_iterator++;

		if (MapObjects_iterator != MapObjects.end()) {

			DataWrite << " }," << "\n";

		}
		else {
			DataWrite << " }" << "\n";
		}
	}
	DataWrite <<
		"}" << "\n";
}


void Map::load_Players(ifstream& DataRead, string TypeActor) {

	string k1, k2;

	if (TypeActor == "Players") {
		cout << TypeActor << endl << "{" << endl;

		DataRead >> k1;

		if (k1 == "{") {

			Player* tmp;
			int id;
			int x;
			int y;

			while (DataRead >> id >> x >> y >> k2 && k2 == "},") {
				if (id == 0) {
					tmp = new Player(x, y, id, MenuGame);
				}
				if (id == 1) {
				}
				MapPlayers.push_back(tmp);

				cout << k1 << id << x << y << k2 << endl;
				DataRead >> k1;
			}

			if (k2 == "}") {
				if (id == 0) {
					tmp = new Player(x, y, id, MenuGame);


				}
				if (id == 1) {
				}
				MapPlayers.push_back(tmp);

			}

			cout << k1 << id << x << y << k2 << endl;

			DataRead >> k2; //lectura de "}" final de tipo

		}

		cout << "}" << endl;

	}


}

void Map::save_Players(ofstream& DataWrite) {
	DataWrite <<
		"Players" << "\n" <<
		"{" << "\n";
	for (MapPlayers_iterator = MapPlayers.begin(); MapPlayers_iterator != MapPlayers.end();) {
		DataWrite <<
			"{ " <<
			(*MapPlayers_iterator)->getID() << " " <<
			(*MapPlayers_iterator)->get_x() << " " <<
			(*MapPlayers_iterator)->get_y();
		MapPlayers_iterator++;

		if (MapPlayers_iterator != MapPlayers.end()) {

			DataWrite << " }," << "\n";

		}
		else {
			DataWrite << " }" << "\n";
		}
	}
	DataWrite <<
		"}" << "\n";

}

string Map::CODE(string D) { //ENCRIPTAR
	return D;
}