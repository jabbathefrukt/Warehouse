#include "warehouse.h"

WareHouse::WareHouse(string id, string name)
{
    this->id = id;
    this->name = name;
    truckHanler.readFromFile(this->name);
    this->goodsHandler.readFromFile("D:\\program\\warehouseSystem\\",this->name);
    //truckHanler.saveToFile(this->name); // ta bort senare
}

WareHouse::~WareHouse()
{
    this->goodsHandler.saveToFile("D:\\program\\warehouseSystem\\",this->name);
    truckHanler.saveToFile(this->name);
    //this->goodsHandler.saveToFile("D:\\program\\warehouseSystem\\",this->name);
}

Truck* WareHouse::getTruckFromPos(int pos)
{
    return truckHanler.getTruckFromPos(pos);
}
bool WareHouse::findGoods(string id)
{
    //for(int i = 0; i <)
    return false;
}

int WareHouse::getNrOfGoods()const
{
    return this->goodsHandler.getNrOfGoods();
}
int WareHouse::getNrOfTrucks()const
{
    return this->truckHanler.getNrOfTrucks();
}
void WareHouse::loadTruck(Goods * goods)
{
    activeTruck->loadGood(goods);
}

Goods * WareHouse::getGoods(string id)
{
    return goodsHandler.selectGoods(id);
}

string WareHouse::getId() const
{
    return this->id;
}

Goods* WareHouse::getGoodFromWarehousePos(int pos)
{
    return this->goodsHandler.getGoodFromPos(pos);
}
Goods* WareHouse::getGoodFromTruckPos(int pos)
{
    return this->activeTruck->getGoodFromPos(pos);
}

bool WareHouse::addTruck(string id, float maxW, float volume)
{
    bool temp;
    temp = truckHanler.addTruck(id, maxW, volume);
    return temp;
}

bool WareHouse::removeTruck(string id)
{
    bool temp;
    temp = truckHanler.removeTruck(id);
    return temp;
}

void WareHouse::addGoods(Goods* ptr)
{
    this->goodsHandler.addGoods(ptr);
}

bool WareHouse::removeGoods()
{
    return true; //
}

Truck * WareHouse::selecetTruck(string id)
{
    return truckHanler.selectTruck(id);
}

string WareHouse::getName() const
{
    return this->name;
}
