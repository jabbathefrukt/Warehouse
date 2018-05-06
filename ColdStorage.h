#ifndef COLDSTORAGE_H
#define COLDSTORAGE_H
#include "BigBox.h"
class ColdStorage :
	public BigBox
{
private:
	int temperature;
public:
	ColdStorage(int temperature);
	~ColdStorage();
};
#endif