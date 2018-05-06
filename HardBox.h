#ifndef HARDBOX_H
#define HARDBOX_H
#include "BigBox.h"
#include<string>
class HardBox :
	public BigBox
{
private:
	string material;
	string density;
public:
	HardBox();
	~HardBox();
};
#endif