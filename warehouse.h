#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include "string"
using namespace std;


class WareHouse
{
private:
    int capacityForGoods;
    string name;

    /*
    TruckHandler truckHanler;
    GoodsHandler goodsHandler;
    */

public:
    WareHouse();

    /*
    bool findGoods(string id);
    void loadTruck(Truck* truck, Goods);
    Goods* getGoods(string id);
    bool addTruck();
    bool removeTruck();
    void addGoods(string id);
    bool removeGoods();
    Truck* selecetTruck(string id);
    */
};

#endif // WAREHOUSE_H
