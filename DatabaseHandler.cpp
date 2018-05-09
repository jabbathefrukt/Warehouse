#include "DatabaseHandler.h"



DatabaseHandler::DatabaseHandler()
{
}


DatabaseHandler::~DatabaseHandler()
{
}

void DatabaseHandler::addDatabase(string name)
{
	databases[nrOfDataBases++] = new Database(name);
}

void DatabaseHandler::addNewGoods(string id, float weight, int expirationDate, string destination, string orderStatus, int i)
{
	this->databases[i]->addGoods(id, weight, expirationDate, destination, orderStatus);
}

bool DatabaseHandler::deleteDatabase(string name)
{
	bool result = false;
	for (int i = 0; i < nrOfDataBases; i++) {
		if (databases[i]->getName() == name) {
			delete databases[i];
			databases[i] = databases[--nrOfDataBases];
			databases[nrOfDataBases] = nullptr;
			result = true;
		}
	}
	return result;
}

Database * DatabaseHandler::getDatabase(string name)
{
	for (int i = 0; i < nrOfDataBases; i++) {
		if (databases[i]->getName() == name) {
			return databases[i];
		}
	}
	return nullptr;
}

int DatabaseHandler::getNrOfDb() const
{
	return this->nrOfDataBases;
}

void DatabaseHandler::saveToFile(string fileName)
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

void DatabaseHandler::readFromFile(string fileName)
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

void DatabaseHandler::saveDatabaseToFile(string fileName, string name, int id)
{
	databases[id]->saveToFile(fileName, name);
}

void DatabaseHandler::readDatabaseFromFile(string fileName, string name, int id)
{
	databases[id]->readFromFile(fileName, name);
}
