#pragma once
#include "Item.h"

class Teleport : public virtual Item
{
public:
	Teleport(unsigned cell);

	virtual void draw() const override;
	virtual bool action(Player&) const override;
	virtual Artefact* clone() const override;

private:
	static unsigned idRec;
	unsigned id;
	unsigned cell;
};

class TCreator : public ICreator
{
public:
	virtual bool check(const char*)const override;
	virtual Artefact* create(std::istream&)const override;
};