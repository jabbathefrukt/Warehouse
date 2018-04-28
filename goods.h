#ifndef GOODS_H
#define GOODS_H

#include "string"
using namespace std;

class Goods
{
private:
    string id;
    float weight;
    int expirationDate;
    string destination;
    string orderStatus;

public:
    Goods();

    /*
    string getId() const;
    float getWeight() const;
    int getExperationDate() const;
    string getDest()const;
    string getOrderStatus()const;
    void setId(string id);
    void setWeight(float weight);
    void setExperasionDate(int date);
    void setDest(string dest);
    void setOrderStatus(string status);
    */

};

#endif // GOODS_H
