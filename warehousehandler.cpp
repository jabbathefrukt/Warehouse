#include "warehousehandler.h"

WareHouseHandler::WareHouseHandler(int capacity)
{
	this->capacity = capacity;
	this->nrOfWareHouses = 0;
}

WareHouse * WareHouseHandler::selectWareHouse(string id)
{
	int index = -1;
	for (int i = 0; i < this-> nrOfWareHouses && index == -1; i++)
	{
		if (wareHouses[i]->getId() == id)
		{
			index = i;
		}
	}
	WareHouse* wareHouseTemp = nullptr;
	if (index != -1)
	{
		return wareHouses[index];
	}
	else
	{
		return wareHouseTemp;
	}
}

void WareHouseHandler::addWareHouse(string id, string name)
{
	if (this->nrOfWareHouses != capacity)
	{
		bool idExist = false;
		for (int i = 0; i < this->nrOfWareHouses && idExist == false; i++)
		{
			if (wareHouses[i]->getId() == id)
			{
				idExist = true;
			}
		}
		if (idExist == false)
		{
			wareHouses[this->nrOfWareHouses] = new WareHouse(id, name);
		}
	}
}

bool WareHouseHandler::removeWareHouse(string id)
{
	bool removed = false;
	int index = -1;
	for (int i = 0; i < this->nrOfWareHouses && index == -1; i++)
	{
		if (wareHouses[i]->getId() == id)
		{
			index = i;
		}
	}
	if (index != -1)
	{
		delete wareHouses[index];
		wareHouses[index] = wareHouses[nrOfWareHouses - 1];
		wareHouses[nrOfWareHouses - 1] = nullptr; // kanske ta bort
		this->nrOfWareHouses--;
		removed = true;
	}
	return removed;
}

int WareHouseHandler::getNrOfWareHouses() const
{
	return this->nrOfWareHouses;
}
