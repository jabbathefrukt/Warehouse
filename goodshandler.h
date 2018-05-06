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
	void addGoods(string id, float weight);
	bool removeGoods(string id);
	int getNrOfGoods()const;
};

#endif // GOODSHANDLER_H