#pragma once
#include "Artefact.h"
#include "Player.h"
class Monster : public Artefact
{
public:
	Monster(int power);

	virtual void draw() const override;
	virtual bool action(Player&) const override;
	virtual Artefact* clone() const override;

	int& getHealth();
	int getPower()const;

private:
	int power;
	mutable int health;
};

class MCreator : public Creator
{
public:
	virtual bool check(const char*) const override;
	virtual Artefact* create(std::istream&) const override;
};