#include "TeleportGift.h"

TeleportGift::TeleportGift(unsigned cell, Type type, int coef) 
	: Item(), Teleport(cell), Gift(type,coef)
{
}

void TeleportGift::draw() const
{
	Teleport::draw();
	std::cout << " & ";
	Gift::draw();
}

bool TeleportGift::action(Player& hero) const
{
	Gift::action(hero);
	Teleport::action(hero);
	return true;
}

Artefact* TeleportGift::clone() const
{
	return new TeleportGift(*this);
}

bool TGCreator::check(const char* str) const
{
	return strcmp(str, "tgift") == 0;
}

Artefact* TGCreator::create(std::istream& is) const
{
	/*char buff[128];
	is >> buff;
	if (strcmp(buff, "blood") == 0)*/

	unsigned cell;
	int coef;
	is >> cell >> coef;
	return new TeleportGift(cell, Gift::Type::Blood, coef);
}

static TGCreator __;