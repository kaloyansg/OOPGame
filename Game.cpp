#include "Game.h"

Game::Game(int playerPower) : player(playerPower, &field)
{}

void Game::add()
{
	unsigned index;
	std::cout << "Index: ";
	std::cin >> index;
	std::cout << "Artefact (teleport/gift/tgift/monster):\n";
	field.addArtefact(ArtFactory::getFactory().create(std::cin),index);
}

int Game::movePlayer(int movement)
{
	player.move(movement);
	if (player.getHealth() <= 0)
		throw "DEAD!";
	return player.getPositon();
}

const Player& Game::getPlayer() const
{
	return player;
	// TODO: insert return statement here
}
