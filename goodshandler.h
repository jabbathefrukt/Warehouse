#ifndef GOODSHANDLER_H
#define GOODSHANDLER_H
#include "goods.h"
#include<string>
#include<iostream>
using namespace std;
class GoodsHandler
{
private:
	int nrOfGoods;
	Goods** goods;
	int capacity;

	void expand();
public:
	GoodsHandler();

	Goods* selectGoods(string id);
	void addGoods(Goods*goods);
	void addNewGoods(string id, float weight, int expirationDate = 0, string destination = 0, string orderStatus = 0);
	bool removeGoods(string id);
	int getNrOfGoods()const;
	void saveToFile(string fileName, string name);
	void readFromFile(string fileName, string name);
};

#endif // GOODSHANDLER_H