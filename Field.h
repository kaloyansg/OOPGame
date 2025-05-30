#pragma once
#include "Artefact.h"
class Field
{
public:
	bool addArtefact(Artefact*, unsigned index);
	~Field();

	const Artefact* operator[](unsigned index) const;
	void remove(unsigned index);

private:
	Artefact* field[100]{nullptr};
};