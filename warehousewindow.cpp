#include "warehousewindow.h"
#include "ui_warehousewindow.h"

warehouseWindow::warehouseWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::warehouseWindow)
{
    ui->setupUi(this);
}

warehouseWindow::~warehouseWindow()
{
    delete ui;
}
