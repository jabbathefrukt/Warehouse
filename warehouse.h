#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include "string"
//#include "goodshandler.h"
#include "truckhandler.h"
using namespace std;


class WareHouse
{
private:
    int capacityForGoods;
    string id;
    string name;
    TruckHandler truckHanler;
    //GoodsHandler goodsHandler;
    Truck* activeTruck;
public:
    WareHouse(string id, string name);
    bool findGoods(string id);
    //void loadTruck(Truck* truck, Goods* goods);
    //Goods* getGoods(string id);
    string getId()const;
   // bool addTruck();
    bool addTruck(string id, float maxW, float volume);
    //bool removeTruck();
    bool removeTruck(string id);
    void addGoods(string id);
    bool removeGoods();
    Truck* selecetTruck(string id);
};

#endif // WAREHOUSE_H
