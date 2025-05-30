#pragma once
//#include "Player.h"
#include <iostream>
#pragma warning (disable : 4996)

class Player;

class Artefact
{
public:
	virtual ~Artefact() = default;
	virtual void draw() const = 0;
	virtual bool action(Player&) const = 0;
	virtual Artefact* clone() const = 0;
};

class Creator
{
public:
	Creator();
	virtual ~Creator() = default;

	virtual bool check(const char*) const = 0;
	virtual Artefact* create(std::istream&) const = 0;
};