#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include "facture.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QVector>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include <QTextDocument>
#include "excel.h"

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
    //QString caractereSpeciaux = "&é~\"#'{([-|è`_\ç^à@)]=}aze€rtyuiop¨$£¤qsdfghjklmù%*µ<>wxcvbn,?;.:/!§+";
    bool montant_m=true;
    bool id_m=true;
    QString montant_s=ui->lineEdit_4->text();
    QString id_s=ui->lineEdit_2->text();

        for(int i = 0; i < montant_s.length(); i++)
        {
     if ( montant_s[i]!="0" && montant_s[i]!="1" && montant_s[i]!="2" && montant_s[i]!="3" && montant_s[i]!="4" && montant_s[i]!="5"&& montant_s[i]!="6" && montant_s[i]!="7" && montant_s[i]!="8" && montant_s[i]!="9")
   { montant_m= false;
     break;
     }



}
 for(int i = 0; i < id_s.length(); i++)
 {
     if ( id_s[i]!="0" && id_s[i]!="1" && id_s[i]!="2" && id_s[i]!="3" && id_s[i]!="4" &&id_s[i]!="5"&& id_s[i]!="6" && id_s[i]!="7" && id_s[i]!="8" && id_s[i]!="9")
   { id_m= false;
         break;}


}
        if(!montant_m)
        {
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("LE MONTANT DOIT CONTENIR UNIQUEMENT DES CHIFFRES .\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else if (!id_m)
        {
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("LE ID DOIT CONTENIR UNIQUEMENT DES CHIFFRES.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            int  montant = ui->lineEdit_4->text().toInt();
            int id_facture=ui->lineEdit_2->text().toInt();
                Facture   f(montant,id_facture);
            bool confirmationAjout = f.ajouter();

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
            ui->tableView->setModel( f.afficher());
        }



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




void MainWindow::on_pushButton_5_clicked()
{

    int id_facture=ui->lineEdit_id_facture->text().toInt();//toInt converssion chaine->entier
    int  montant_facture =ui->lineEdit_montant->text().toInt();



   Facture f(montant_facture,id_facture);
    bool test=f.modifier(id_facture,montant_facture);

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Modification effectue.\n"
                                             "Click Cancel to exit. "),QMessageBox::Cancel);
        ui->tableView->setModel(f.afficher());

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                 QObject::tr("Modification non effectue.\n"
                                             "Click Cancel to exit. "),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_8_clicked() //recherche
{
        QString query=ui->rechercher->text();
        if(query.length()>0)
            ui->tableView->setModel(Etmp.rechercher(query));
        else
            ui->tableView->setModel(Etmp.afficher());
}


void MainWindow::on_pushButton_7_clicked() // trie
{
   // QString query=ui->trie->text();
    //if(query.length()>0)
        ui->tableView->setModel(Etmp.trie());
    //else
      //  ui->tableView->setModel(Etmp.afficher());

}


void MainWindow::on_pushButton_2_clicked()//pdf
{
    QPrinter print;
            print.setPrinterName("imprimer");
            QPrintDialog dialog(&print, this);
            if(dialog.exec()==QDialog::Rejected) return;
            ui->tableView->render(&print);
}





void MainWindow::on_pushButton_3_clicked()

    //export excel
{



           QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                                   tr("Excel Files (*.xls)"));
                   if (fileName.isEmpty())
                       return;

                   ExportExcelObject obj(fileName, "mydata", ui->tableView);

                   obj.addField(0, "id_facture", "char(20)");
                   obj.addField(1, "montant", "char(20)");





                   int retVal = obj.export2Excel();

                   if( retVal > 0)
                   {
                       QMessageBox::information(this, tr("Done"),
                                                QString(tr("%1 records exported!")).arg(retVal)
                                                );
                   }
}
