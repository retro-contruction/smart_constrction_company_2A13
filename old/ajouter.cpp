#include "ajouter.h"
#include "ui_ajouter.h"

ajouter::ajouter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajouter)
{
    ui->setupUi(this);
}

ajouter::~ajouter()
{
    delete ui;
}
