#include "Teleport.h"
#include <cstdlib>

unsigned Teleport::idRec = 0;

Teleport::Teleport(unsigned cell) :cell(cell)
{
	id = idRec;
	idRec++;
}

void Teleport::draw() const
{
	std::cout << "Teleport - " << id << " " << cell;
}

bool Teleport::action(Player& hero) const
{
	int index = rand() % 100;
	while (index == hero.getPositon())
	{
		index = rand() % 100;
	}
	hero.setPosition(index);
	return true;
}

Artefact* Teleport::clone() const
{
	return new Teleport(*this);
}

bool TCreator::check(const char* str) const
{
	return strcmp(str,"teleport") == 0;
}

Artefact* TCreator::create(std::istream& is) const
{
	unsigned cell;
	is >> cell;
	return new Teleport(cell);
}

static TCreator __;