#include "warehouse.h"

WareHouse::WareHouse(string id, string name)
{
	this->id = id;
	this->name = name;
	truckHanler.readFromFile(this->name);
	truckHanler.saveToFile(this->name); // ta bort senare
}

WareHouse::~WareHouse()
{
	//truckHanler.saveToFile(this->name);
}

bool WareHouse::findGoods(string id)
{
	//for(int i = 0; i <)
	return false;
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

void WareHouse::addGoods(string id)
{
	//
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

