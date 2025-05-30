#pragma once
#include "Field.h"
#include "Artefact.h"
#include "Player.h"
#include "ArtFactory.h"

class Game
{
public:
	Game(int playerPower);
	void add();
	int movePlayer(int movement);

	const Player& getPlayer()const;

private:
	Player player;
	Field field;
};