#include "truck.h"

Truck::Truck(string id, float maxWeight, float volume)
{
	this->id = id;
	this->maxWeight = maxWeight;
	this->volume = volume;
}

Truck::~Truck()
{
}

void Truck::loadGood(Goods * goods)
{
	this->goodsHandler.addGoods(goods);
}

Goods * Truck::getGoods(string id)
{
	return goodsHandler.selectGoods(id);
}

void Truck::changeDestination(string destination)
{
	this->destination = destination;
}

string Truck::getDestination() const
{
	return this->destination;
}

float Truck::getVolume() const
{
	return this->volume;
}

float Truck::getMaxWeight() const
{
	return this->maxWeight;
}

string Truck::getId() const
{
	return this->id;
}
