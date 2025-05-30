#pragma once
#include "Artefact.h"

class ArtFactory
{
public:
	static ArtFactory& getFactory();
	void registerCreator(const Creator*);
	Artefact* create(std::istream&);

private:
	ArtFactory();

private:
	static const size_t capacity = 5;
	const Creator* creators[capacity];
	size_t size;
};