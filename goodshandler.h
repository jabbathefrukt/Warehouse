#ifndef GOODSHANDLER_H
#define GOODSHANDLER_H
#include "goods.h"

class GoodsHandler
{
private:
    int nrOfGoods;
    Goods** goods;
    int capacity;

public:
    GoodsHandler();

    Goods* selectGoods(string id);
    void addGoods(string id, float weight);
    bool removeGoods(string id);
    int getNrOfGoods()const;
};

#endif // GOODSHANDLER_H
