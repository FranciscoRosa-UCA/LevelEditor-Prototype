#ifndef TESTFRAMEWORK_H
#define TESTFRAMEWORK_H

#include "game.h"
#include "player.h"
#include "buttonClass.h"

#include "actorManager.h"
#include "mapClass.h"


#include "NetworkClient.h"
#include "NetworkServer.h"


class TestFrameWork : public Game
{
public:
	void main();
};

#endif