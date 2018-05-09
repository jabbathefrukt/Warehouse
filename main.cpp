#include "warehousesystem.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    warehouseSystem w;
    w.show();

    return a.exec();
}
