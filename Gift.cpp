#include "Gift.h"

Gift::Gift(Type type, int coef) : type(type), coef(coef)
{
}

void Gift::draw() const
{
	if (type == Type::Blood)
		std::cout << "Gift - " << "Blood" << coef;
	else
		std::cout << "Gift - " << "Other" << coef;
}

bool Gift::action(Player& hero) const
{
	if (type == Type::Blood)
	{
		hero.getHealth() += coef;
		if (hero.getHealth() > 100)
		{
			coef = hero.getHealth() - 100;
			hero.getHealth() = 100;
		}
		else
		{
			coef = 0;
			return false;
		}
	}

	return true;
}

Artefact* Gift::clone() const
{
	return new Gift(*this);
}

bool GCreator::check(const char* str) const
{
	return strcmp(str, "gift") == 0;
}

Artefact* GCreator::create(std::istream& is) const
{
	/*char buff[128];
	is >> buff;
	if (strcmp(buff, "blood") == 0)*/

	int coef;
	is >> coef;
		
	return new Gift(Gift::Type::Blood, coef);
}

static GCreator __;