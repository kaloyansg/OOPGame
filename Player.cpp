#include "Player.h"

Player::Player(int power, Field* field) 
	: position(0), health(100), power(power), field(field)
{
}

void Player::setPosition(int index)
{
	if (index >= 0 && index <= 99)
	{
		position = index;
		if(field->operator[](position))
		if (!field->operator[](position)->action(*this))
		{
			field->remove(position);
		}
	}
}

int& Player::getHealth()
{
	return health;
}

int Player::getPower() const
{
	return power;
}

int Player::getPositon() const
{
	return position;
}

void Player::move(int pos)
{
	if (position == 99 && pos > 0)
		throw "You WON!";

	if (pos > 0 && position < 99)
	{
		position++;
		if (field->operator[](position))
		if (!field->operator[](position)->action(*this))
		{
			field->remove(position);
		}
	}
	else if (pos <= 0 && position > 0)
	{
		position--;
		if (field->operator[](position))
		if (!field->operator[](position)->action(*this))
		{
			field->remove(position);
		}
	}
}

std::ostream& operator<<(std::ostream& os, const Player& hero)
{
	std::cout << "Hero - " << hero.health << "hp, " << hero.power << " [" << hero.position <<"]";
	return os;
}
