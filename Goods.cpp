#include "goods.h"



Goods::Goods()
{
	this->id = "";
	this->weight = 0;
}

Goods::Goods(string id, float weight)
{
	this->id = id;
	this->weight = weight;
}

string Goods::getId() const
{
	return this->id;
}
float Goods::getWeight() const
{
	return this->weight;
}
int Goods::getExperationDate() const
{
	return this->expirationDate;
}
string Goods::getDest()const
{
	return this->destination;
}
string Goods::getOrderStatus()const
{
	return this->orderStatus;
}
void Goods::setId(string id)
{
	this->id = id;
}
void Goods::setWeight(float weight)
{
	this->weight = weight;
}
void Goods::setExperasionDate(int date)
{
	this->expirationDate = date;
}
void Goods::setDest(string dest)
{
	this->destination = dest;
}
void Goods::setOrderStatus(string status)
{
	this->orderStatus = status;
}
