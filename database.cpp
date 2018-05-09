#include "Database.h"



Database::Database(string name)
{
    this->name = name;
    this->capacity = 100;
    this->nrOfDestinations = 0;
    this->destinations[capacity];
    this->readFromFile("D:\\program\\warehouseSystem\\",this->name);
}

Database::Database(const Database & obj)
{
    this->name=obj.name;
    this->capacity=obj.capacity;
}

Database::~Database()
{
    this->saveToFile("D:\\program\\warehouseSystem\\",this->name);
}

void Database::printToFile()
{
}

void Database::updateInventory()
{

}

void Database::addGoods(string id, float weight, int expirationDate, string destination, string orderStatus)
{
    Goods*good = new Goods(id, weight, expirationDate, destination, orderStatus);
    goodsHandler.addGoods(good);
}

Goods * Database::searchAndReturnGoods(string id)
{
    return goodsHandler.selectGoods(id);
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

void Database::saveToFile(string fileName, string name)
{
    name += "Database";
    goodsHandler.saveToFile(fileName, name);
}

void Database::readFromFile(string fileName, string name)
{
    name += "Database";
    goodsHandler.readFromFile(fileName, name);
}
