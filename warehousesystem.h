#ifndef WAREHOUSESYSTEM_H
#define WAREHOUSESYSTEM_H
using namespace  std;
#include<iostream>
#include<sstream>
#include"warehousewindow.h"
#include<fstream>
#include<ostream>
#include"databasehandler.h"
#include<QRegExp>
#include<QMainWindow>
#include"warehousehandler.h"
#include<string>
#include<QDialog>
#include<QDir>
#include<QListWidgetItem>
#include<QDebug>
namespace Ui {
class warehouseSystem;
}

class warehouseSystem : public QMainWindow
{
    Q_OBJECT

public:
    explicit warehouseSystem(QWidget *parent = 0);
    ~warehouseSystem();
    void selectWareHouse(string id);
    void saveWarehouses();
    int cap=10;
    bool addWareHouse(std::string name,std::string id);
    void removeWareHouse(std::string name);
    void addGoodsToDataBase();
    void addGoodsWareHouse(std::string id);
    void removeGoods(std::string name, int nrOfGoods);

    void selectTruck(string id);
    void addTruck(std::string id);
    void removeTruck(std::string id);
    void addGoodsToTruck(std::string name, int nrOfGoods);
    void ChangeDestination();


private slots:
    void on_searchLine_textChanged(const QString &arg1);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);



    void on_addWarehouseBtn_clicked();

    void on_saveWarehousesBtn_clicked();

    void on_addGoodToWBtn_clicked();

    void on_removeBtnWarehouse_clicked();

    void on_changeWarehouseBtn_clicked();

    void on_addTruckBtn_clicked();

    void on_loadToTruckBtn_clicked();

    void on_removeGoodBtn_clicked();

    void on_removeTruckBtn_clicked();

    void on_changeDestBtn_clicked();

    void on_trucksList_itemClicked(QListWidgetItem *item);

    void on_addGoodsFromTruck_clicked();

private:
    Ui::warehouseSystem *ui;
    warehouseWindow *warehouseW;
    WareHouse *currentWarehouse;
    DatabaseHandler dHandler;
    Truck* activeTruck;
    QString warehouses;
    int nrOfWarehouses;
    int truckGoodsLoaded;
    QStringList myList;
    WareHouseHandler wHandler;
    void disableSelectWarehouse(bool state);
    void disableWarehouseMng(bool state);
    /*
    DataBaseHandler dataBaseHandler;
    WareHouse* activeWareHouse;
    */
};

#endif // WAREHOUSESYSTEM_H
