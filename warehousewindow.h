#ifndef WAREHOUSEWINDOW_H
#define WAREHOUSEWINDOW_H
#include <QMainWindow>
namespace Ui {
class warehouseWindow;
}

class warehouseWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit warehouseWindow(QWidget *parent = 0);
    ~warehouseWindow();

    Ui::warehouseWindow *ui;
};

#endif // WAREHOUSEWINDOW_H
