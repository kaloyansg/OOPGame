#include "ArtFactory.h"

ArtFactory& ArtFactory::getFactory()
{
	static ArtFactory factory;
	return factory;
}

void ArtFactory::registerCreator(const Creator* cr)
{
	if (size < capacity)
	{
		creators[size] = cr;
		++size;
	}
}

Artefact* ArtFactory::create(std::istream& is)
{
	char buff[128];
	is >> buff;
	is.ignore();

	for (size_t i = 0; i < size; ++i)
	{
		if (creators[i]->check(buff))
		{
			return creators[i]->create(is);
		}
	}

	return nullptr;
}

ArtFactory::ArtFactory() : size(0)
{
	for (size_t i = 0; i < capacity; ++i)
	{
		creators[i] = nullptr;
	}
}
