#include "Artefact.h"
#include "ArtFactory.h"

Creator::Creator()
{
	ArtFactory::getFactory().registerCreator(this);
}
