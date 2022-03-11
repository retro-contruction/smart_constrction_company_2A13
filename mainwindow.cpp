#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>
#include "terrain.h"
#include <QFileDialog>
#include <QFile>
#include <QValidator>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableTerrain->setModel(T.afficherTerrain());


        QRegExp rx("[a-zA-Z]+");
        QValidator *validator = new
        QRegExpValidator(rx, this->ui->lineEdit_ville);


       ui->lineEdit_dimens->setValidator(new QIntValidator(0, 9999, this));
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_clicked()
{
    QString plan;
    QString file_name= QFileDialog::getOpenFileName(this,"open a file","c://");
    ui->lineEditplan->insert(file_name);
}


void MainWindow::on_AjouterTerrain_clicked()
{
    QString  id,ville,plan,adresse;
    int etat;
    float dimension;
   id=ui->lineEdit_id->text();
   ville=ui->lineEdit_ville->text();
   dimension=ui->lineEdit_dimens->text().toFloat();
   adresse=ui->lineEditAdresse->text();
   etat=ui->comboBoxEtat->currentText().toInt();
   plan=ui->lineEditplan->text();
   if(id=="" || ville=="" || adresse=="" || dimension==NULL )
   {
       QMessageBox::warning(nullptr, QObject::tr("vide"),
                   QObject::tr("veuillez saisir tous les champs.\n"), QMessageBox::Cancel);

   }
   else
   {
   Terrain t(id,dimension,etat,ville,plan,adresse);
   t.ajouterTerrain();
   QMessageBox::information(this,"succes","Add with succes");
   ui->tableTerrain->setModel(T.afficherTerrain());
   }
}

void MainWindow::on_id_Supprimer_clicked()
{
    QString id=ui->lineEdit_id_supp->text();
   bool test = T.supprimerTerrain(id);

   if(test)  {QMessageBox::information(this,"succes","Delete with succes");

     ui->tableTerrain->setModel(T.afficherTerrain());
   }

    else{
        QMessageBox::warning(nullptr, QObject::tr("vide"),
                    QObject::tr("id n'existe pas .\n"), QMessageBox::Cancel);

}
}
void MainWindow::on_pushButtonModifier_clicked()
{
    QString id,ville,adresse;
    int dimension,etat;
    id=ui->lineEdit_id_2->text();
    dimension=ui->lineEdit_dimens_2->text().toInt();
    etat=ui->comboBoxEtat_2->currentText().toInt();
    ville=ui->lineEdit_ville_2->text();
    adresse=ui->lineEditAdr2->text();
    if(id=="" || ville=="" || adresse=="" || dimension==NULL )
    {
        QMessageBox::warning(nullptr, QObject::tr("vide"),
                    QObject::tr("veuillez saisir tous les champs.\n"), QMessageBox::Cancel);

    }
    else{

    Terrain t;
   t.modifier(id,dimension,etat,ville,adresse);
   QMessageBox::information(this,"","Update with succes");
   ui->tableTerrain->setModel(T.afficherTerrain());
    }

}


