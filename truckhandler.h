#ifndef TRUCKHANDLER_H
#define TRUCKHANDLER_H
#include "truck.h"
#include<fstream>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<qdebug.h>
class TruckHandler
{
private:
    int nrOfTrucks;
    int capacity;
    Truck** trucks;
public:
    TruckHandler(int capacity = 10);
    ~TruckHandler();

    Truck* selectTruck(string id);
    Truck* getTruckFromPos(int pos);
    Goods* getGoodFromPos(int pos);
    bool addTruck(string id, float maxW, float volume);
    bool removeTruck(string id);
    int getNrOfTrucks()const;

    void readFromFile(string name);
    void saveToFile(string name);
};

#endif // TRUCKHANDLER_H
