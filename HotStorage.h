#ifndef HOTSTORAGE_H
#define HOTSTORAGE_H
#include "BigBox.h"
class HotStorage :
	public BigBox
{
private:
	int temperature;
public:
	HotStorage(int temperature);
	~HotStorage();

};
#endif