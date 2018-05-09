#include "goodshandler.h"



GoodsHandler::GoodsHandler()
{
    this->capacity = 10;
    this->nrOfGoods = 0;
    goods = new Goods*[capacity];
}

GoodsHandler::~GoodsHandler()
{
    for(int i = 0; i < nrOfGoods; i++){
        delete goods[i];
    }
    delete[] this->goods;
}
void GoodsHandler::expand()
{
}

Goods * GoodsHandler::selectGoods(string id)
{
    for (int i = 0; i < nrOfGoods; i++)
    {
        if (goods[i]->getId() == id)
        {
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
Goods* GoodsHandler::getGoodFromPos(int pos)
{
    if(pos>this->nrOfGoods||pos<0)
    {
        return nullptr;
    }
    return this->goods[pos];
}
void GoodsHandler::removeGoods(int pos)
{
    this->goods[pos]=nullptr;
    this->goods[pos]=this->goods[--nrOfGoods];
}
void GoodsHandler::addNewGoods(string id, float weight, int expirationDate=0, string destination="", string orderStatus="")
{
    this->goods[nrOfGoods++] = new Goods(id, weight, expirationDate, destination, orderStatus);
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

void GoodsHandler::saveToFile(string fileName, string name)
{
    //QString tempName = QString::fromStdString(fileName);
    //QFile saveFile(tempName);
    //if (!saveFile.open(QFile::WriteOnly | QFile::Text))
    //{
    //	QMessageBox::information(0, "error", saveFile.errorString());
    //	return;
    //}
    //QTextStream out(&saveFile);
    //out << this->nrOfDataBases << endl;
    //for (int i = 0; i < this->nrOfDataBases; i++)
    //{
    //	QString temp;
    //	// temp = QString::fromStdString(wareHouses[i]->getName());
    //	out << QString::fromStdString(databases[i]->getName()) << endl;
    //}
    //saveFile.flush();

    QString tempName = QString::fromStdString(fileName);
    tempName += QString::fromStdString(name);
    tempName += "Goods.txt";

    QString temp10 = tempName;
    QFile saveFile(temp10);
    if (!saveFile.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::information(0, "error", saveFile.errorString());
        return;
    }
    QTextStream out(&saveFile);
    out << this->nrOfGoods << endl;
    for (int i = 0; i < this->nrOfGoods; i++)
    {
        out << endl;
        QString temp;

        out << QString::fromStdString(goods[i]->getId()) << endl;
        out << QString::number(goods[i]->getWeight()) << endl;
        out << QString::number(goods[i]->getExperationDate()) << endl;
        out << QString::fromStdString(goods[i]->getDest()) << endl;
        out << QString::fromStdString(goods[i]->getOrderStatus()) << endl;

    }
    saveFile.flush();
}

void GoodsHandler::readFromFile(string fileName, string name)
{
    /*QString tempName = QString::fromStdString(fileName);
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
    in.flush();*/

    QString tempName = QString::fromStdString(fileName);
    tempName += QString::fromStdString(name);
    tempName += "Goods.txt";
    QString temp10 = tempName;
    QFile file(temp10);
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0, "error", file.errorString());
    }
    QTextStream in(&file);
    QString mText = in.readLine();
    int temp = mText.toInt();
    this->nrOfGoods = temp;
    goods = new Goods*[this->nrOfGoods];
    for (int i = 0; i < this->nrOfGoods; i++)
    {
        mText = in.readLine();
        mText = in.readLine();

        string id;
        id = mText.toStdString();

        mText = in.readLine();
        float weight = mText.toFloat();

        mText = in.readLine();
        int expirationDate = mText.toInt();

        mText = in.readLine();
        string destination;
        destination = mText.toStdString();

        mText = in.readLine();
        string orderStatus;
        orderStatus = mText.toStdString();

        goods[i] = new Goods(id, weight, expirationDate, destination, orderStatus);
    }
}
