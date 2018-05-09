#include "goods.h"



Goods::Goods()
{
    this->id = "";
    this->weight = 0;
}

Goods::Goods(string id, float weight, int expirationDate = 0, string destination = "", string orderStatus = "")
{
    this->id = id;
    this->weight = weight;
    this->expirationDate = expirationDate;
    this->destination = destination;
    this->orderStatus = orderStatus;
}
Goods::Goods(const Goods & obj)
{
  this->destination=obj.destination;
  this->expirationDate=obj.expirationDate;
  this->id=obj.id;
  this->orderStatus=obj.orderStatus;
  this->weight=obj.weight;
}
void Goods::operator=(const Goods & obj)
{
    if(this!=&obj)
    {
        this->id=obj.id;
        this->destination=obj.destination;
        this->expirationDate=obj.expirationDate;
        this->orderStatus=obj.orderStatus;
        this->weight=obj.weight;
    }
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
