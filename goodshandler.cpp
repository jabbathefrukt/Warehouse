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
		if (goods[i]->getId() == id) {
			return goods[i];
		}
	}
	return nullptr;
}


void GoodsHandler:: addGoods(Goods*goods)
{
	//expand;
		this->goods[nrOfGoods++] = goods;
}
bool GoodsHandler:: removeGoods(string id)
{
	bool result = false;
	for (int i = 0; i < nrOfGoods; i++) {
		if (goods[i]->getId() == id) {
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

void GoodsHandler::saveToFile(string filename)
{
	QString tempName = QString::fromStdString(fileName);
	QFile saveFile(tempName);
	if (!saveFile.open(QFile::WriteOnly | QFile::Text))
	{
		QMessageBox::information(0, "error", saveFile.errorString());
		return;
	}
	QTextStream out(&saveFile);
	out << this->nrOfDataBases << endl;
	for (int i = 0; i < this->nrOfDataBases; i++)
	{
		QString temp;
		// temp = QString::fromStdString(wareHouses[i]->getName());
		out << QString::fromStdString(databases[i]->getName()) << endl;
	}
	saveFile.flush();
}

void GoodsHandler::readFromFile(string filename)
{
	QString tempName = QString::fromStdString(fileName);
	QFile file(tempName);
	if (!file.open(QIODevice::ReadOnly))
	{
		QMessageBox::information(0, "error", file.errorString());
	}
	QTextStream in(&file);
	QString mText = in.readLine();
	int temp = mText.toInt();
	this->nrOfDataBases = temp;
	databases = new Database*[this->nrOfDataBases];
	for (int i = 0; i < this->nrOfDataBases; i++)
	{
		mText = in.readLine();
		string name;
		name = mText.toStdString();
		databases[i] = new Database(name);
	}
	in.flush();
}
