#include "warehousehandler.h"

WareHouseHandler::WareHouseHandler(int capacity)
{
	this->capacity = capacity;
	this->nrOfWareHouses = 0;

	loadWareHousesFromFile();
	//saveWareHousesToFile(); fungerar här men inte i destruktorn
}

WareHouseHandler::~WareHouseHandler()
{
	//saveWareHousesToFile();
	for (int i = 0; i < this->nrOfWareHouses; i++)
	{
		delete wareHouses[i];
	}
	delete[] wareHouses;

	//fungerar men endast om programmet avslutas vanligt och inte med att klicka ner programmet
}

WareHouse * WareHouseHandler::selectWareHouse(string id)
{
	int index = -1;
    for (int i = 0; i < this->nrOfWareHouses && index == -1; i++)
	{
		if (wareHouses[i]->getId() == id)
		{
			index = i;
		}
	}
	WareHouse* wareHouseTemp = nullptr;
	if (index != -1)
	{
		return wareHouses[index];
	}
	else
	{
		return wareHouseTemp;
	}
}

void WareHouseHandler::addWareHouse(string id, string name)
{
	if (this->nrOfWareHouses != capacity)
	{
		bool idExist = false;
		for (int i = 0; i < this->nrOfWareHouses && idExist == false; i++)
		{
			if (wareHouses[i]->getId() == id)
			{
				idExist = true;
			}
		}
		if (idExist == false)
		{
			wareHouses[this->nrOfWareHouses] = new WareHouse(id, name);
		}
	}
}

bool WareHouseHandler::removeWareHouse(string id)
{
	bool removed = false;
	int index = -1;
	for (int i = 0; i < this->nrOfWareHouses && index == -1; i++)
	{
		if (wareHouses[i]->getId() == id)
		{
			index = i;
		}
	}
	if (index != -1)
	{
		delete wareHouses[index];
		wareHouses[index] = wareHouses[nrOfWareHouses - 1];
		wareHouses[nrOfWareHouses - 1] = nullptr; // kanske ta bort
		this->nrOfWareHouses--;
		removed = true;
	}
	return removed;
}

int WareHouseHandler::getNrOfWareHouses() const
{
	return this->nrOfWareHouses;
}

void WareHouseHandler::loadWareHousesFromFile()
{
    QFile file("D:\\qt projects\\untitled\\WareHouses.txt");
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"error",file.errorString());
    }
    QTextStream in(&file);
    QString mText = in.readLine();
    int temp = mText.toInt();
    this->nrOfWareHouses = temp;
    wareHouses = new WareHouse*[this->nrOfWareHouses];
    for(int i = 0; i < this->nrOfWareHouses; i++)
    {
        mText = in.readLine();
        string temp1;
        temp1 = mText.toStdString();

        mText = in.readLine();
        string temp2;
        temp2 = mText.toStdString();
        wareHouses[i] = new WareHouse(temp2, temp1);
    }
     in.flush();
}

void WareHouseHandler::saveWareHousesToFile()
{
    QFile saveFile("D:\\qt projects\\untitled\\WareHouses.txt");
    if(!saveFile.open(QFile::WriteOnly| QFile::Text))
    {
       QMessageBox::information(0,"error",saveFile.errorString());
       return;
    }
    QTextStream out(&saveFile);
    out << this->nrOfWareHouses << endl;
    for(int i = 0; i < this->nrOfWareHouses; i++)
    {
       QString temp;
      // temp = QString::fromStdString(wareHouses[i]->getName());
       out << QString::fromStdString(wareHouses[i]->getName()) << endl;
       out << QString::fromStdString(wareHouses[i]->getId()) << endl;
    }
    saveFile.flush();
}
