#include "Database.h"



Database::Database(string name)
{
	this->name = name;
	this->capacity = 100;
	this->nrOfDestinations = 0;
	this->destinations[capacity];
}


Database::~Database()
{
}

void Database::printToFile()
{
}

void Database::updateInventory()
{
	
}

void Database::addGoods(string id, float weight)
{
	Goods*good = new Goods(id, weight);
	goodsHandler.addGoods(good);
}

void Database::removeGoods(string id)
{
	goodsHandler.removeGoods(id);
}

void Database::addDestination(string destination)
{
	destinations[nrOfDestinations++] = destination;
}

string Database::getName()
{
	return this->name;
}
