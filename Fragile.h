#ifndef FRAGILE_H
#define FRAGILE_H
#include "BigBox.h"
#include<string>
class Fragile :
	public BigBox
{
private:
	string type;
public:
	Fragile(string type);
	~Fragile();

	string getType();
};
#endif