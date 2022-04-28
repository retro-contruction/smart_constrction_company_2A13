#include "map.h"
//#include "ui_map.h"
/*
map::map(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::map)
{
    ui->setupUi(this);
   // ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
   // ui->quickWidget->show();

}
*/
map::~map()
{
    delete ui;
}
