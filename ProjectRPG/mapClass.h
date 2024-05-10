#ifndef MAPCLASS_H
#define MAPCLASS_H

#include <list>
#include <fstream>
#include <string>

#include "menuClass.h"
#include "grassTileClass.h"
#include "dirtTileClass.h"
#include "basicBlock.h"

#include "controlManager.h"
#include "actorManager.h"
#include "colliderManager.h"

#include "player.h"

using namespace std;

class Map {
public:
	Map(Menu*);
	~Map();

	void createMap();

	void saveMap();

	void loadMap();


	void clearIterators();

	void DestroyAll();
	int SIZEMAPITER() { return MapTiles.size(); }

protected:
	// Creacion de mapas por defecto
	void Map0(); // Crear mapa 0

private:
	int id;
	Menu* MenuGame;
	list<Tiles*> MapTiles;
	list<Tiles*>::iterator MapTiles_iterator;

	list<Actor*> MapObjects;  //REMPLAZAR POR OBJECT CUANDO LO CREE
	list<Actor*>::iterator MapObjects_iterator; //REMPLAZAR POR OBJECT CUANDO LO CREE

	list<Player*> MapPlayers;
	list<Player*>::iterator MapPlayers_iterator;

	void deleteMap();

	string CODE(string);

	void assign_Actors_To_Iterators();
	void assign_Iterators_To_Actors();

	void load_Tiles(ifstream &, string);
	void save_Tiles(ofstream &);

	void load_Objects(ifstream &, string);
	void save_Objects(ofstream &);

	void load_Players(ifstream &, string);
	void save_Players(ofstream &);

};


#endif