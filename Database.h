#ifndef DATABASE_H
#define DATABASE_H
#include "GoodsHandler.h"
#include<string>
#include<iostream>
using namespace std;
template<typename T>
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
	void addGoods(string id, float weight);
	void removeGoods(string id);
	void addDestination(string destination);

	string getName();
};

#endif