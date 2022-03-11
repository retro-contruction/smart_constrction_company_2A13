#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employes.h"
#include "employes.cpp"
#include <QMessageBox>
#include <QComboBox>
#include <QSpinBox>
#include<QIntValidator>
#include<QValidator>
#include <QSqlQuery>
#include <QSqlQueryModel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
/*
    QRegExp rx("[a-zA-Z]+");
    QValidator *validator = new QRegExpValidator(rx, this->ui->lineEdit_2);
    QLineEdit *edit = new QLineEdit(this->ui->lineEdit_2);
    edit->setValidator(validator);

    QRegExp rx1("[a-zA-Z]+");
    QValidator *validator1 = new QRegExpValidator(rx, this->ui->lineEdit_3);
    QLineEdit *edit1 = new QLineEdit(this->ui->lineEdit_3);
    edit1->setValidator(validator1);
*/

   ui->lineEdit->setValidator(new QIntValidator(0, 99999999, this));


}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pushButton_clicked()
{


    QString id=ui->lineEdit->text();
    QString nom=ui->lineEdit_2->text();
    QString prenom=ui->lineEdit_3->text();
    QString poste=ui->comboBox_3->currentText();



    Employes E(id,nom,prenom,poste);
    if(id!= NULL && nom!=NULL && prenom!=NULL && poste!= NULL )
    {


    if(E.ajouter()) {
        QMessageBox::information(nullptr, QObject::tr("BRAVO!!!"),
                    QObject::tr("Ajout effectuer avec succés.\n" ), QMessageBox::Cancel);



        }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("ECHEC!!!"),
                    QObject::tr("employé existe déja.\n"), QMessageBox::Cancel);
    }
    }

    else
        QMessageBox::information(nullptr, QObject::tr("ECHEC!!!"),
                    QObject::tr("Tous less champs doivent etre remplis.\n"), QMessageBox::Cancel);

}





void MainWindow::on_tabWidget_currentChanged(int index)
{

ui->test->setEnabled(true);
ui->test->setModel(insemployes.afficher());
ui->comboBox->setModel(insemployes.modifier_liste_employes());
ui->comboBox_2->setModel(insemployes.modifier_liste_employes());


}




    void MainWindow::on_pushButton_2_clicked()
    {


        Employes e1;
            e1.setid(ui->comboBox->currentText());
            if(e1.supprimer(e1.getid()))
            {
                QMessageBox::information(nullptr, QObject::tr("Supprimer un employé"),
                            QObject::tr("Suppression avec succés.\n" ), QMessageBox::Cancel);

            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("Erreur!"),
                            QObject::tr("non supprimé.\n"
                                        ), QMessageBox::Cancel);

            }
}


void MainWindow::on_pushButton_3_clicked()
{

        QString id=ui->comboBox_2->currentText();
        QString nom=ui->lineEdit_6->text();
        QString prenom=ui->lineEdit_7->text();
        QString poste=ui->comboBox_4->currentText();

       Employes E(id,nom,prenom,poste);
        if(E.modifier(id))
        {
                  QMessageBox::information(nullptr, QObject::tr("Modifier un employé"),
                              QObject::tr("employé modifie.\n"), QMessageBox::Cancel);

        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Modifier un employé"),
                              QObject::tr("Erreur !\n"), QMessageBox::Cancel);
        }

}
