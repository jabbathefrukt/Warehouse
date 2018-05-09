#ifndef DATABASEHANDLER
#define DATABASEHANDLER
#include "database.h"
#include "goodshandler.h"
#include<string>
#include<iostream>
#include<fstream>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<qdebug.h>
using namespace std;
class DatabaseHandler
{
private:
    int nrOfDataBases;
    Database**databases;
    int capacity;
public:
    DatabaseHandler();
    ~DatabaseHandler();

    void addDatabase(string name);
    void addNewGoods(string id, float weight, int expirationDate, string destination, string orderStatus, int i);
    bool deleteDatabase(string name);
    Database*getDatabase(string name);
    int getNrOfDb() const;
    void saveToFile(string fileName);
    void readFromFile(string fileName);

    void saveDatabaseToFile(string fileName, string name, int id);
    void readDatabaseFromFile(string fileName, string name, int id);
};
#endif
