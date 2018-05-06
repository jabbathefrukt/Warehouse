#include "Fragile.h"



Fragile::Fragile(string type)
{
	this->type = type;
}


Fragile::~Fragile()
{
}

string Fragile::getType()
{
	return this->type;
}
