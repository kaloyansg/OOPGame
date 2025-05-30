#pragma once
#include <iostream>
#include "Field.h"

class Player
{
public:
	Player(int power, Field*);

	void setPosition(int index);
	int& getHealth();
	int getPower()const;
	int getPositon() const;

	void move(int);

	friend std::ostream& operator<<(std::ostream&, const Player&);

private:
	int power;
	int health;
	unsigned position;
	Field* field;
};

