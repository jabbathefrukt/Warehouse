#ifndef GOODSHANDLER_H
#define GOODSHANDLER_H
#include "goods.h"
#include<string>
#include<iostream>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<qdebug.h>
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
    ~GoodsHandler();
    Goods* selectGoods(string id);
    void addGoods(Goods*goods);
    void removeGoods(int pos);
    void addNewGoods(string id, float weight, int expirationDate, string destination, string orderStatus);
    bool removeGoods(string id);
    Goods* getGoodFromPos(int pos);
    int getNrOfGoods()const;
    void saveToFile(string fileName, string name);
    void readFromFile(string fileName, string name);
};

#endif // GOODSHANDLER_H
