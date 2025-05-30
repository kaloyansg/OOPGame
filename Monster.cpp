#include "Monster.h"

Monster::Monster(int power) : health(100), power(power)
{
}

void Monster::draw() const
{
    std::cout << "Monster - " << health << "hp, " << power;
}

bool Monster::action(Player& hero) const
{
    health -= hero.getPower();
    hero.getHealth() -= power;

    if (hero.getHealth() < 0)
        hero.getHealth() = 0;
    
    if (health < 0)
    {
        health = 0;
        return false;
    }
    return true;
}

Artefact* Monster::clone() const
{
    return new Monster(*this);
}

int& Monster::getHealth()
{
    return health;
}

int Monster::getPower() const
{
    return power;
}

bool MCreator::check(const char* str) const
{
    return strcmp(str, "monster") == 0;
}

Artefact* MCreator::create(std::istream& is) const
{
    int power;
    is >> power;
    return new Monster(power);
}

static MCreator __;