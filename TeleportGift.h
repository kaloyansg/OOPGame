#pragma once
#include "Teleport.h"
#include "Gift.h"
class TeleportGift : public Teleport, public Gift
{
public:
	TeleportGift(unsigned cell, Type type, int coef);

	virtual void draw() const override;
	virtual bool action(Player&) const override;
	virtual Artefact* clone() const override;

};

class TGCreator : public ICreator
{
public:
	virtual bool check(const char*) const override;
	virtual Artefact* create(std::istream&) const override;
};