#include "Field.h"

bool Field::addArtefact(Artefact* art, unsigned index)
{
	if (field[index])
	{
		delete art;
		art = nullptr;
		return false;
	}
	field[index] = art; //->clone();
	return true;
}

Field::~Field()
{
	for (size_t i = 0; i < 100; ++i)
	{
		delete field[i];
		field[i] = nullptr;
	}
}

const Artefact* Field::operator[](unsigned index) const
{
	if (index > 99)
		return nullptr;
	return field[index];
}

void Field::remove(unsigned index)
{
	if (index > 99)
		return;
	delete field[index];
	field[index] = nullptr;
}
