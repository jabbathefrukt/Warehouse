#ifndef TRUCKHANDLER_H
#define TRUCKHANDLER_H
#include "truck.h"

class TruckHandler
{
private:
    int nrOfTrucks;
    int capacity;
    Truck** trucks;
public:
    TruckHandler();

    /*
    Truck* selectTruck(string id);
    bool addTruck(string id, float maxW, float volume);
    bool removeTruck(string id);
    int getNrOfTrucks()const;
    void loadTrucks(Goods* goods, string id);

    */
};

#endif // TRUCKHANDLER_H
