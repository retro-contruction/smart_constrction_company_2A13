#include "secdialog.h"
#include "ui_secdialog.h"
#include "material.h"
#include "Form.h"
#include "ui_interfacelogin.h"
#include <QMessageBox>

SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);

}


SecDialog::~SecDialog()
{
    delete ui;
}

void SecDialog::on_pushButton_clicked()
{
   QString ref = ui->lineEdit_2->text();

   QString nom = ui->lineEdit->text();
   QString date_dachat = ui->lineEdit_3->text();
   int quantite = ui->lineEdit_4->text().toInt();
   int etat =0;

   material w(ref,nom,date_dachat,quantite,etat);

    bool ok = w.recherche(ref,nom,date_dachat,quantite,etat);
   if( ok == true)
   {
       bool test = w.ajout_material();

       if(test)
           {
               QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout effectue \n""Click cancel to exit"), QMessageBox::Cancel);
           }
       else
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Ajout non effectue \n""Click cancel to exit"), QMessageBox::Cancel);
   }

}
