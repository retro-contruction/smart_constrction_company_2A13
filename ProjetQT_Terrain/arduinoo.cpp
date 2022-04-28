#include "arduinoo.h"
#include "ui_arduinoo.h"

arduinoo::arduinoo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::arduinoo)
{
    ui->setupUi(this);
}

arduinoo::~arduinoo()
{
    delete ui;
}
