#include "warehousesystem.h"
#include "ui_warehousesystem.h"

warehouseSystem::warehouseSystem(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::warehouseSystem)
{
    //this->wareHouseHandler.loadWareHousesFromFile();
    //this->wareHouseHandler.loadWarehouses();
    //this->databaseHandler.loadDatabases();
    this->nrOfWarehouses=0;
    this->warehouses="";
    this->truckGoodsLoaded=0;
    ui->setupUi(this);
    int id=100;
    for(int i=0;i<this->wHandler.getNrOfWareHouses();i++)
    {
        warehouses=QString::fromStdString(this->wHandler.selectWareHouse(std::to_string(id))->getName());
        this->myList.insert(0,warehouses);
        id++;
    }

    /*
    std::fstream inFile;
    std::string ware;
    inFile.open("D:/warehouses.txt");
    inFile>>nrOfWarehouses;
    for(int i=0;i<nrOfWarehouses;i++)
    {
        inFile>>ware;
        warehouses=QString::fromStdString(ware);
        myList.insert(0,warehouses);
    }
    inFile.close();
    */
    ui->listWidget->addItems(myList);
}

warehouseSystem::~warehouseSystem()
{
    delete ui;
}

void warehouseSystem::on_searchLine_textChanged(const QString &arg1)
{
    QRegExp regExp(arg1, Qt::CaseInsensitive,QRegExp::Wildcard);
    ui->listWidget->clear();
    ui->listWidget->addItems(myList.filter(regExp));
}

void warehouseSystem::selectWareHouse(string id)
{
    this->currentWarehouse=wHandler.selectWareHouse(id);
}

void warehouseSystem::saveWarehouses()
{
    //this->wareHouseHandler.saveWarehouses();
    /*
    std::ofstream outFile;
    std::string temp="";
    outFile.open("D:/warehouses.txt");
    outFile<<this->nrOfWarehouses<<std::endl;
    for(int i=0;i<nrOfWarehouses;i++)
    {
        temp=this->myList.takeAt(i);
        outFile<<temp<<endl;
    }
    outFile.close();
    */
}
void warehouseSystem::disableSelectWarehouse(bool state)
{
    this->ui->listWidget->setDisabled(state);
    this->ui->searchLbl->setDisabled(state);
    this->ui->searchLine->setDisabled(state);
    this->ui->addWarehouseBtn->setDisabled(state);
    this->ui->addWarehouseLine->setDisabled(state);
    this->ui->removeBtnWarehouse->setDisabled(state);
    this->ui->removeLineWarehouse->setDisabled(state);
    this->ui->warehouseRemoveNamelbl->setDisabled(state);
    this->ui->addWarehouseLbl->setDisabled(state);
}
void warehouseSystem::disableWarehouseMng(bool state)
{
    this->ui->addGoodsFromTruck->setDisabled(state);
    this->ui->warehouseGoodsLbl->setDisabled(state);
    this->ui->tableForTrucks->setDisabled(state);
    this->ui->truckGoodsLbl->setDisabled(state);
    this->ui->addGoodToWBtn->setDisabled(state);
    this->ui->addNameGoodLbl->setDisabled(state);
    this->ui->addNameGoodLine->setDisabled(state);
    this->ui->tableForWarehouse->setDisabled(state);
    this->ui->truckLbl->setDisabled(state);
    this->ui->trucksComboBox->setDisabled(state);
    this->ui->loadToTruckBtn->setDisabled(state);
    this->ui->quanityLbl->setDisabled(state);
    this->ui->quanityLine->setDisabled(state);
    this->ui->removeGoodBtn->setDisabled(state);
    this->ui->truckLineNm->setDisabled(state);
    this->ui->trucksList->setDisabled(state);
    this->ui->removeTruckBtn->setDisabled(state);
    this->ui->addTruckBtn->setDisabled(state);
    this->ui->changeDestBtn->setDisabled(state);
    this->ui->changeDestLine->setDisabled(state);
    this->ui->destLbl->setDisabled(state);
    this->ui->changeWarehouseBtn->setDisabled(state);
    this->ui->nameTruckFList->setDisabled(state);
    this->ui->truckMaxWeightLbl->setDisabled(state);
    this->ui->truckMaxWeightLine->setDisabled(state);
    this->ui->truckVolumeLbl->setDisabled(state);
    this->ui->truckVolumeLine->setDisabled(state);
    this->ui->trucksAddLbl->setDisabled(state);
    this->ui->addGoodsDestLine->setDisabled(state);
    this->ui->addGoodsDestLbl->setDisabled(state);
}

bool warehouseSystem::addWareHouse(std::string name,std::string id)
{
  return this->wHandler.addWareHouse(id,name);
}

void warehouseSystem::removeWareHouse(std::string id)
{
  this->wHandler.removeWareHouse(id);
}

void warehouseSystem::addGoodsWareHouse(std::string id)
{

  //this->currentWarehouse->addGoods();
}

void warehouseSystem::removeGoods(std::string name, int nrOfGoods)
{
  //this->currentWarehouse->removeGoods()
}

void warehouseSystem::selectTruck(string id)
{
  this->activeTruck=this->currentWarehouse->selecetTruck(id);
}
/*
void warehouseSystem::addTruck(std::string id)
{
  //this->currentWarehouse->addTruck(id);
}
void warehouseSystem::removeTruck(std::string id)
{
  //this->currentWarehouse->removeTruck(id);
}
void warehouseSystem::addGoodsToTruck(std::string id, std::string name, int nrOfGoods)
{
  //this->currentWarehouse->addGoodsToTruck(id,name,nrOfGoods);
}
void warehouseSystem::ChangeDestination(std::string destination)
{
  //this->currentTruck->changeDestination(destination);
}
void warehouseSystem::addGoodsToDataBase(std::string name)
{
  //this->dataBase->addGood(name);
}
*/

void warehouseSystem::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{

    /*
    warehouseW=new warehouseWindow(this);
    this->selectWareHouse(item->text().toStdString());
    warehouseW->setWindowTitle(item->text());
    warehouseW->show();
    */
    std::string name = item->text().toLocal8Bit().constData();
    this->ui->tableForTrucks->clearContents();
    //this->ui->tableForWarehouse->clear();
    this->ui->tableForWarehouse->clearContents();
    this->selectWareHouse(name);
    this->disableSelectWarehouse(true);
    this->disableWarehouseMng(false);
    this->setWindowTitle(item->text());
    this->ui->tableForWarehouse->setRowCount(100);
    this->ui->tableForTrucks->setRowCount(100);
    this->ui->trucksList->clear();
    this->ui->trucksComboBox->clear();
    //Sätter listan med trucksen, truckcombobox och listan med alla goods till det currentwarehouse har


    for(int i=0;i<this->currentWarehouse->getNrOfTrucks();i++)
    {
        this->ui->trucksList->addItem(QString::fromStdString(this->currentWarehouse->getTruckFromPos(i)->getId()+" Destination: "+this->currentWarehouse->getTruckFromPos(i)->getDestination()));
        //this->ui->trucksList->addItem(QString::fromStdString(this->currentWarehouse->getTruck(i)->getId());
        this->ui->trucksComboBox->addItem(QString::fromStdString(this->currentWarehouse->getTruckFromPos(i)->getId()));
        //this->ui->trucksComboBox->addItem(QString::fromStdString(this->currentWarehouse->getTruck(i)->getId());
    }


    for(int i=0;i<this->currentWarehouse->getNrOfGoods();i++)
    {
        Goods *ptr=this->currentWarehouse->getGoodFromWarehousePos(i);

        QTableWidgetItem *temp=new QTableWidgetItem(QString::fromStdString(ptr->getId()));
        this->ui->tableForWarehouse->setItem(i,0,temp);
        QTableWidgetItem *temp2=new QTableWidgetItem(QString::fromStdString(ptr->getDest()));
        this->ui->tableForWarehouse->setItem(i,1,temp2);

    }
    int row=0;
    for(int i=0;i<this->currentWarehouse->getNrOfTrucks();i++)
    {

        Truck *truckPtr=this->currentWarehouse->getTruckFromPos(i);
        for(int j=0;j<this->currentWarehouse->getTruckFromPos(i)->getNrOfGoods();j++)
        {
            Goods *ptr=this->currentWarehouse->getTruckFromPos(i)->getGoodFromPos(j);

            QTableWidgetItem *temp=new QTableWidgetItem(QString::fromStdString(truckPtr->getId()));
            this->ui->tableForTrucks->setItem(row,0,temp);
            QTableWidgetItem *temp2=new QTableWidgetItem(QString::fromStdString(ptr->getId()));
            this->ui->tableForTrucks->setItem(row,1,temp2);
            QTableWidgetItem *temp3=new QTableWidgetItem(QString::fromStdString(ptr->getDest()));
            this->ui->tableForTrucks->setItem(row,2,temp3);
            row++;
            this->truckGoodsLoaded++;
        }
    }
    //this->currentWarehouse->getNrOfGoods());
    //this->ui->tableForWarehouse->setItem(1,1,temp);
    //this->showMaximized();

}


void warehouseSystem::on_addWarehouseBtn_clicked()
{
    std::string name = this->ui->addWarehouseLine->text().toLocal8Bit().constData();
    if(this->ui->addWarehouseLine->text()!=QString(""))
            if(this->addWareHouse(name,std::to_string(this->wHandler.getNrOfWareHouses()+100))==false)
            {
                this->myList.insert(0,this->ui->addWarehouseLine->text());
                //this->ui->listWidget->addItem("damnskm,ab");
                this->ui->listWidget->addItem(this->ui->addWarehouseLine->text());
                //this->wareHouseHandler.add(QString::toStdString())
                this->nrOfWarehouses++;
            }
    else
            {
                QMessageBox::information(0,"error"," Existing warehouse");
            }
    this->ui->addWarehouseLine->setText(QString(""));
}

void warehouseSystem::on_saveWarehousesBtn_clicked()
{
    //this->saveWarehouses();

}

void warehouseSystem::on_addGoodToWBtn_clicked()
{
   std::string name = this->ui->addNameGoodLine->text().toLocal8Bit().constData();
   Goods *ptr=this->dHandler.getDatabase("Hej")->searchAndReturnGoods(name);
   if(this->ui->addNameGoodLine->text()!=QString("")&&ptr!=nullptr)
   {
       QString goodname=this->ui->addNameGoodLine->text();
       //QString nrOfGoodsToAdd=this->ui->quanityLine->text();
       std::string name = goodname.toLocal8Bit().constData();
       Goods *temp=new Goods(*ptr);
       //this->addGoodsWareHouse(name);

       QString truckID=this->ui->trucksComboBox->currentText();

       QTableWidgetItem *item=new QTableWidgetItem(goodname);
       QTableWidgetItem *destination=new QTableWidgetItem(this->ui->addGoodsDestLine->text());
       //QTableWidgetItem *goodsToAdd=new QTableWidgetItem(nrOfGoodsToAdd);
       this->ui->tableForWarehouse->setItem(this->currentWarehouse->getNrOfGoods(),0,item);
       //this->ui->tableForWarehouse->setItem(this->currentWarehouse->getNrOfGoods(),2,destination);
       //this->ui->tableForWarehouse->setItem(this->currentWarehouse->getNrOfGoods(),2,QString::fromStdString(this->currentWarehouse->getGoods(goodname)->getOrderStatus()));
       this->currentWarehouse->addGoods(temp);
        temp=nullptr;
       ptr=nullptr;
       this->ui->addNameGoodLine->clear();
       this->ui->quanityLine->clear();
   }

}

void warehouseSystem::on_loadToTruckBtn_clicked()
{
    if(this->ui->addNameGoodLine->text()!=QString("")&&this->ui->addGoodsDestLine->text()!=QString("")
            &&this->ui->trucksComboBox->currentText()!=QString(""))
    {

        QString goodname=this->ui->addNameGoodLine->text();
        string goodNamestr=goodname.toLocal8Bit().constData();
        std::string truckID =this->ui->trucksComboBox->currentText().toLocal8Bit().constData();
        QString destination=this->ui->addGoodsDestLine->text();

        this->selectTruck(truckID);
        int pos=-1;
        for(int i=0;i<this->currentWarehouse->getNrOfGoods();i++)
        {
            if(this->ui->tableForWarehouse->item(i,0)!=nullptr)
            {
                QString temp=this->ui->tableForWarehouse->item(i,0)->text();
                if(temp == goodname)
                {
                    pos=i;
                }
            }


        }
        //this->activeTruck->loadGood(this->currentWarehouse->getGoods(goodNamestr));
        Goods *ptr=this->currentWarehouse->getGoods(goodNamestr);

        if(ptr==nullptr)
        {


        }
        else
        {
            std::string destStr =destination.toLocal8Bit().constData();

            this->activeTruck->loadGood(ptr);
            if(this->activeTruck->getGoodFromPos(this->activeTruck->getNrOfGoods()-1)==nullptr)
            {
                //ptr->setDest(destStr);
            }
            this->activeTruck->getGoodFromPos(this->activeTruck->getNrOfGoods()-1)->setDest(destStr);
            this->ui->tableForWarehouse->removeRow(pos);
            QTableWidgetItem *truckIDN=new QTableWidgetItem(QString::fromStdString(truckID));
            QTableWidgetItem *good=new QTableWidgetItem(goodname);
            QTableWidgetItem *destinationFGood=new QTableWidgetItem(destination);
            this->ui->tableForTrucks->setItem(this->truckGoodsLoaded,0,truckIDN);
            this->ui->tableForTrucks->setItem(this->truckGoodsLoaded,1,good);
            this->ui->tableForTrucks->setItem(this->truckGoodsLoaded,2,destinationFGood);
            this->truckGoodsLoaded++;
        }
        ptr=nullptr;
        this->ui->addNameGoodLine->clear();
        this->ui->quanityLine->clear();
        this->ui->addGoodsDestLine->clear();
    }
}

void warehouseSystem::on_removeBtnWarehouse_clicked()
{
    if(this->ui->removeLineWarehouse->text()!=QString(""))
    {
        this->myList.removeOne(this->ui->removeLineWarehouse->text());
        QListWidgetItem *item=new QListWidgetItem(this->ui->removeLineWarehouse->text());
        delete this->ui->listWidget->takeItem(this->ui->listWidget->row(item));
        this->ui->removeLineWarehouse->setText(QString(""));
        std::string name = this->ui->removeLineWarehouse->text().toLocal8Bit().constData();
        this->removeWareHouse(name);
        this->nrOfWarehouses--;
    }
}

void warehouseSystem::on_changeWarehouseBtn_clicked()
{
    this->disableSelectWarehouse(false);
    this->disableWarehouseMng(true);
    this->truckGoodsLoaded=0;
    this->currentWarehouse=nullptr;
}

void warehouseSystem::on_addTruckBtn_clicked()
{
    std::string truckId = this->ui->truckLineNm->text().toLocal8Bit().constData();
    float maxWeight = this->ui->truckMaxWeightLine->text().toFloat();
    float volume = this->ui->truckVolumeLine->text().toFloat();
    if(this->currentWarehouse->addTruck(truckId,maxWeight,volume)==true)
    {
        this->ui->trucksList->addItem(this->ui->truckLineNm->text());
        this->ui->trucksComboBox->addItem(this->ui->truckLineNm->text());
    }
    else
    {
        QMessageBox::information(0,"error"," Existing truck");
    }
    this->ui->truckLineNm->clear();
    this->ui->truckMaxWeightLine->clear();
    this->ui->truckVolumeLine->clear();
}


void warehouseSystem::on_removeGoodBtn_clicked()
{
    std::string goodToRemove = this->ui->addNameGoodLine->text().toLocal8Bit().constData();
    QString goodname=this->ui->addNameGoodLine->text();
    int pos=-1;
    for(int i=0;i<10;i++)
    {
        if(this->ui->tableForWarehouse->item(i,0)!=nullptr)
        {
            QString temp=this->ui->tableForWarehouse->item(i,0)->text();
            if(temp == goodname)
            {
                pos=i;
            }
        }

    }
    if(pos!=-1)
    {
        this->ui->tableForWarehouse->removeRow(pos);
    }
    //this->currentWarehouse->removeGoods(goodToRemove);

}

void warehouseSystem::on_removeTruckBtn_clicked()
{
    //QString temp=this->ui->removeTruckBtn->text();

}

void warehouseSystem::on_changeDestBtn_clicked()
{
    std::string destination = this->ui->changeDestLine->text().toLocal8Bit().constData();
    this->activeTruck->changeDestination(destination);
    int pos=-1;
    for(int i=0;i<this->currentWarehouse->getNrOfTrucks()&&pos==-1;i++)
    {
        if(this->currentWarehouse->getTruckFromPos(i)!=nullptr)
        {
            QString temp=QString::fromStdString(this->currentWarehouse->getTruckFromPos(i)->getId());
            if(temp == QString::fromStdString(this->activeTruck->getId()))
            {
                pos=i;
            }
        }

    }
    if(pos!=-1)
    {
        QString temp=QString::fromStdString(this->activeTruck->getId())+" Destination: "+this->ui->changeDestLine->text();
        this->ui->trucksList->item(pos)->setText(temp);
    }
}

void warehouseSystem::on_trucksList_itemClicked(QListWidgetItem *item)
{
    std::string truckSelectedId = item->text().toLocal8Bit().constData();
    istringstream truckInfo(truckSelectedId);
    std::string id;
    std::getline(truckInfo,id,' ');
    this->selectTruck(id);
}

void warehouseSystem::on_addGoodsFromTruck_clicked()
{
    if(this->ui->addNameGoodLine->text()!=QString("")
            &&this->ui->trucksComboBox->currentText()!=QString(""))
    {

        QString goodname=this->ui->addNameGoodLine->text();
        QString truckIDQString=this->ui->trucksComboBox->currentText();
        string goodNamestr=goodname.toLocal8Bit().constData();
        std::string truckID =this->ui->trucksComboBox->currentText().toLocal8Bit().constData();

        this->selectTruck(truckID);
        int pos=-1;
        for(int i=0;i<this->truckGoodsLoaded&&pos==-1;i++)
        {
            if(this->ui->tableForTrucks->item(i,0)!=nullptr)
            {
                QString tempTruck=this->ui->tableForTrucks->item(i,0)->text();
                QString tempGood=this->ui->tableForTrucks->item(i,1)->text();
                if(tempTruck == truckIDQString&&tempGood==goodname)
                {
                    pos=i;
                }
            }


        }
        //this->activeTruck->loadGood(this->currentWarehouse->getGoods(goodNamestr));
        Goods *ptr=this->activeTruck->getGoods(goodNamestr);

        if(ptr==nullptr)
        {


        }
        else
        {
            //std::string destStr =destination.toLocal8Bit().constData();

            //ptr->setDest(destStr);
            this->currentWarehouse->addGoods(ptr);
            //this->currentWarehouse->getGoodFromPos(this->activeTruck->getNrOfGoods()-1)->setDest(destStr);
            this->ui->tableForTrucks->removeRow(pos);
            QTableWidgetItem *truckIDN=new QTableWidgetItem(QString::fromStdString(truckID));
            QTableWidgetItem *good=new QTableWidgetItem(goodname);
           // QTableWidgetItem *destinationFGood=new QTableWidgetItem(destination);
            this->ui->tableForWarehouse->setItem(this->currentWarehouse->getNrOfGoods()-1,0,good);

            this->truckGoodsLoaded--;
        }
        ptr=nullptr;
        this->ui->addNameGoodLine->clear();
        this->ui->quanityLine->clear();
        this->ui->addGoodsDestLine->clear();
    }
}
