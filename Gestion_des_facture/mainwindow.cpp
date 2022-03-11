#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include "facture.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);ui->tableView->setModel(Etmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    float montant = ui->lineEdit_4->text().toInt();
    Facture nouvelle(montant);
    bool confirmationAjout = nouvelle.ajouter();

    if(confirmationAjout)
        {
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("AJOUT EFFECTUE\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("Ajout non effectue.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_6_clicked()//pour le boutton supprimer
{
    int id = ui->lineEdit_3->text().toInt();
    bool confirmationsupprimer = Etmp.supprimer(id);

    if(confirmationsupprimer)
        {
        ui->tableView->setModel(Etmp.afficher());
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("supprimer EFFECTUE\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("supprimer non effectue.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
}
