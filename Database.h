#ifndef DATABASE_H
#define DATABASE_H
#include "GoodsHandler.h"
#include<string>
#include<iostream>
using namespace std;
class Database
{
private:
	GoodsHandler goodsHandler;
public:
	Database();
	~Database();

	void printToFile();
	void updateInventory();
	void addGoods(string id, float weight, string type);
	void removeGoods(string id, float weight, string type);
	void addDestination();
};

#endif