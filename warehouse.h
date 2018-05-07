#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include "string"
#include "goodshandler.h"
#include "truckhandler.h"
#include<fstream>
using namespace std;


class WareHouse
{
private:
    int capacityForGoods;
    string id;
    string name;
    TruckHandler truckHanler;
    GoodsHandler goodsHandler;
    Truck* activeTruck;
public:
    WareHouse(string id, string name);
	~WareHouse();
    bool findGoods(string id);
	void loadTruck(Goods* goods);
    Goods* getGoods(string id);
    string getId()const;
    bool addTruck(string id, float maxW, float volume);
    bool removeTruck(string id);
    void addGoods(string id);
    bool removeGoods();
    Truck* selecetTruck(string id);
	string getName()const;
};

#endif // WAREHOUSE_H
