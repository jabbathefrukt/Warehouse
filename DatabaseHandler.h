#ifndef DATABASEHANDLER
#define DATABASEHANDLER
#include "database.h"
#include "goodshandler.h"
#include<string>
#include<iostream>
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
	void addNewGoods(string id,float weight);
	bool deleteDatabase(string name);
	Database*getDatabase(string name);
	int getNrOfDb() const;
	void saveToFile(string fileName);
	void readFromFile(string fileName);
};
#endif

