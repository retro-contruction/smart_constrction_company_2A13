#include "houssem.h"
#include "ui_houssem.h"

houssem::houssem(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::houssem)
{
    ui->setupUi(this);
}

houssem::~houssem()
{
    delete ui;
}
