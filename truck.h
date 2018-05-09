#ifndef TRUCK_H
#define TRUCK_H
#include "goodshandler.h"
#include<string>
using namespace std;

class Truck
{
private:
    string destination;
    string id;
    float maxWeight;
    float volume;
    bool avaliable;
    string currentLocation;
    GoodsHandler goodsHandler;


public:
    Truck(string id, float maxWeight, float volume);
    ~Truck();
    int getNrOfGoods()const;
    Goods* getGoodFromPos(int pos);
    void loadGood(Goods* goods);
    Goods* getGoods(string id);
    void changeDestination(string destination);
    string getDestination()const;
    float getVolume()const;
    float getMaxWeight()const;
    string getId()const;

};

#endif // TRUCK_H
