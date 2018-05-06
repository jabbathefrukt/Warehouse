#include "goodshandler.h"



GoodsHandler::GoodsHandler()
{
	this->capacity = 10;
	this->nrOfGoods = 0;
	goods = new Goods*[capacity];
}

void GoodsHandler::expand()
{
}

Goods * GoodsHandler::selectGoods(string id)
{
	for (int i = 0; i < nrOfGoods; i++) {
		if (goods[i]->getId == id) {
			return goods[i];
		}
	}
	return nullptr;
}


void GoodsHandler:: addGoods(string id, float weight)
{
	//expand;

	if (selectGoods(id) == nullptr) {
		goods[nrOfGoods++] = new Goods(id, weight);
	}
}
bool GoodsHandler:: removeGoods(string id)
{
	bool result = false;
	for (int i = 0; i < nrOfGoods; i++) {
		if (goods[i]->getId == id) {
			delete goods[i];
			goods[i] = goods[--nrOfGoods];
			goods[nrOfGoods] = nullptr;
			result = true;
		}
	}
	return result;
}
int GoodsHandler:: getNrOfGoods()const
{
	return this->nrOfGoods;
}
