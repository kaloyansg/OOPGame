#pragma once
#include "Item.h"
class Gift : public virtual Item
{
public:
	enum class Type
	{
		Blood,
		Power,
		Magic,
		Health,
		Other
	};

public:
	Gift(Type type, int coef);

	virtual void draw() const override;
	virtual bool action(Player&) const override;
	virtual Artefact* clone() const override;

private:
	Type type;
	mutable int coef;
};

class GCreator : public ICreator
{
public:
	virtual bool check(const char*) const override;
	virtual Artefact* create(std::istream&) const override;
};