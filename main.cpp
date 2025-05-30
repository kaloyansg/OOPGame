#include <iostream>
#include "Teleport.h"
#include "Gift.h"
#include "Monster.h"
#include "Player.h"
#include "TeleportGift.h"
#include "Field.h"
#include "Game.h"

int main()
{
	/*Teleport t(5);
	Gift g(Gift::Type::Blood, 20);
	TeleportGift tg(6, Gift::Type::Blood, 10);
	Monster m(50);
	Player p(60);

	std::cout << p << '\n';
	t.action(p);
	std::cout << p << '\n';
	m.action(p);
	std::cout << p << '\n';
	g.action(p);
	std::cout << p << '\n';
	tg.action(p);
	std::cout << p << '\n';
	m.draw();*/

	Game game(60);
	for (size_t i = 0; i < 20; i++)
	{
		game.add();
	}


	int movement;
	try
	{
		while (true)
		{
			std::cout << "\nMove: ";
			std::cin >> movement;
			game.movePlayer(movement);
			std::cout << game.getPlayer() << '\n';
		}
	}
	catch (const char* err)
	{
		std::cout << "----------------------------- " << err;
	}
}