#include "truckhandler.h"

TruckHandler::TruckHandler(int capacity)
{
	this->capacity = capacity;
	//this->nrOfTrucks = 0; // vet inte om det kommer gå emot min readfrom file
}

TruckHandler::~TruckHandler()
{
	for (int i = 0; i < this->nrOfTrucks; i++)
	{
		delete trucks[i];
	}
	delete[] trucks;
}

Truck * TruckHandler::selectTruck(string id)
{
	int index = -1;
	for (int i = 0; i < nrOfTrucks && index == -1; i++)
	{
		if (trucks[i]->getId() == id)
		{
			index = i;
		}
	}
	Truck* tempTruck = nullptr;
	if (index != -1)
	{
		return trucks[index];
	}
	else
	{
		return tempTruck;
	}
}

bool TruckHandler::addTruck(string id, float maxW, float volume)
{
	bool temp = false;
	if (nrOfTrucks != capacity)
	{
		bool idExist = false;
		for (int i = 0; i < nrOfTrucks && idExist == false; i++)
		{
			if (trucks[i]->getId() == id)
			{
				idExist = true;
			}
		}
		if (idExist == false)
		{
			trucks[nrOfTrucks] = new Truck(id, maxW, volume);
			temp = true;
		}
	}
	return temp;
}

bool TruckHandler::removeTruck(string id)
{
	bool removed = false;
	int index = -1;
	for (int i = 0; i < nrOfTrucks && index == -1; i++)
	{
		if (trucks[i]->getId() == id)
		{
			index = i;
		}
	}
	if (index != -1)
	{
		delete trucks[index];
		trucks[index] = trucks[nrOfTrucks - 1];
		trucks[nrOfTrucks - 1] = nullptr; // kanske ta bort
		nrOfTrucks--;
		removed = true;
	}
	return removed;
}

int TruckHandler::getNrOfTrucks() const
{
	return this->nrOfTrucks;
}

void TruckHandler::readFromFile(string name)
{
    /*
	string tempName = name;
	tempName += "Trucks.txt";
	std::ifstream openFile(tempName);
	//cout << tempName << endl;
	openFile >> this->nrOfTrucks;
	trucks = new Truck*[this->nrOfTrucks];
	
	if (openFile.is_open())
	{
		for (int i = 0; i <this->nrOfTrucks; i++)
		{
			string id;
			float weight;
			float volume;

			openFile >> id;
			openFile >> weight;//kanske läs in direkt från filen;
			openFile >> volume;
			trucks[i] = new Truck(id, weight, volume);
		}
	}
	openFile.close();

    */

    /*
    string tempName = "D:\\qt projects\\untitled\\";
    += name;
    tempName += "Trucks.txt";
    QFile file("D:\\qt projects\\untitled\\Trucks.txt");
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
     */
}

void TruckHandler::saveToFile(string name)
{
	std::ofstream myfile;
	string tempName = name;
	tempName += "Trucks.txt";
	cout << tempName << endl;
	myfile.open(tempName);

	if (myfile.is_open())
	{
		myfile << this->nrOfTrucks << '\n';

		for (int i = 0; i < this->nrOfTrucks; i++)
		{
			myfile << trucks[i]->getId() << " " << trucks[i]->getMaxWeight() << " " << trucks[i]->getVolume() << '\n';
		}
		myfile.close();
	}
}
