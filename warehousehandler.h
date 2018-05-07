#ifndef WAREHOUSEHANDLER_H
#define WAREHOUSEHANDLER_H
#include "warehouse.h"
#include<fstream>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<qdebug.h>
using namespace std;
class WareHouseHandler
{
private:
    int nrOfWareHouses;
    int capacity;
    WareHouse** wareHouses;
    
public:
    WareHouseHandler(int capacity);
	~WareHouseHandler();
    WareHouse* selectWareHouse(string id);
    void addWareHouse(string id, string name);
    bool removeWareHouse(string id);
    int getNrOfWareHouses()const;
    void loadWareHousesFromFile();
    void saveWareHousesToFile();
};

#endif // WAREHOUSEHANDLER_H
