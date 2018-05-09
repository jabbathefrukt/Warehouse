#include "truck.h"

Truck::Truck(string id, float maxWeight, float volume)
{
    this->id = id;
    this->maxWeight = maxWeight;
    this->volume = volume;
    this->goodsHandler.readFromFile("D:\\program\\warehouseSystem\\",this->id);
}

Truck::~Truck()
{
    this->goodsHandler.saveToFile("D:\\program\\warehouseSystem\\",this->id);
}

void Truck::loadGood(Goods * goods)
{
    this->goodsHandler.addGoods(goods);
}

Goods* Truck::getGoodFromPos(int pos)
{
    return this->goodsHandler.getGoodFromPos(pos);
}
int Truck::getNrOfGoods()const
{
    return this->goodsHandler.getNrOfGoods();
}
Goods * Truck::getGoods(string id)
{
    Goods* temp;
    temp = goodsHandler.selectGoods(id);
    goodsHandler.removeGoods(id);
    return temp;
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
