#include "truck.h"

Truck::Truck(string id, float maxWeight, float volume)
{
	this->id = id;
	this->maxWeight = maxWeight;
	this->volume = volume;
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
