#ifndef DATABASE_H
#define DATABASE_H
#include "GoodsHandler.h"
#include<string>
#include<iostream>
#include<fstream>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<qdebug.h>
using namespace std;
class Database
{
private:
	GoodsHandler goodsHandler;
	string name;

	int capacity;
	int nrOfDestinations;
	string destinations[];
public:
	Database(string name);
	~Database();

	void printToFile();
	void updateInventory();
	void addGoods(string id, float weight, int expirationDate, string destination, string orderStatus);
	Goods* searchAndReturnGoods(string id);
	void removeGoods(string id);
	void addDestination(string destination);

	string getName();


	void saveToFile(string fileName, string name);
	void readFromFile(string fileName, string name);
};

#endif