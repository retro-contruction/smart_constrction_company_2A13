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
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_a->setModel(Etmp.afficher()); // affichage
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ajouter_a_clicked()
{
    //QString caractereSpeciaux = "&é~\"#'{([-|è`_\ç^à@)]=}aze€rtyuiop¨$£¤qsdfghjklmù%*µ<>wxcvbn,?;.:/!§+";
    bool montant_m=true;
    bool id_m=true;
    QString montant_s=ui->lineEdit_montant_a->text();
    QString id_s=ui->lineEdit_id_a->text();

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
            int  montant = ui->lineEdit_montant_a->text().toInt();
            int id_facture=ui->lineEdit_id_a->text().toInt();
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
            ui->tableView_a->setModel( f.afficher());
        }

}

void MainWindow::on_pushButton_modifier_a_clicked()
{
    int id_facture=ui->lineEdit_id_modif_a->text().toInt();//toInt converssion chaine->entier
    int  montant_facture =ui->lineEdit_montant_modif_a->text().toInt();



   Facture f(montant_facture,id_facture);
    bool test=f.modifier(id_facture,montant_facture);

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Modification effectue.\n"
                                             "Click Cancel to exit. "),QMessageBox::Cancel);
        ui->tableView_a->setModel(f.afficher());

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                 QObject::tr("Modification non effectue.\n"
                                             "Click Cancel to exit. "),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_supprimer_a_clicked()
{
    int id = ui->lineEdit_id_supp_a->text().toInt();
    bool confirmationsupprimer = Etmp.supprimer(id);

    if(confirmationsupprimer)
        {
        ui->tableView_a->setModel(Etmp.afficher());
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("supprimer EFFECTUE\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("supprimer non effectue.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_rechercher_a_clicked()
{
    QString query=ui->LineEdit_rechercher_a->text();
    if(query.length()>0)
        ui->tableView_a->setModel(Etmp.rechercher(query));
    else
        ui->tableView_a->setModel(Etmp.afficher());
}

void MainWindow::on_pushButton_tri_a_clicked()
{
    ui->tableView_a->setModel(Etmp.trie());
}

void MainWindow::on_pushButton_excel_a_clicked()
{

    QTableView *table;
       table = ui->tableView_a;

       QString filters("CSV files (*.csv);;All files (*.*)");
       QString defaultFilter("CSV files (*.csv)");
       QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                          filters, &defaultFilter);
       QFile file(fileName);

       QAbstractItemModel *model =  table->model();
       if (file.open(QFile::WriteOnly | QFile::Truncate)) {
           QTextStream data(&file);
           QStringList strList;
           for (int i = 0; i < model->columnCount(); i++) {
               if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                   strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
               else
                   strList.append("");
           }
           data << strList.join(";") << "\n";
           for (int i = 0; i < model->rowCount(); i++) {
               strList.clear();
               for (int j = 0; j < model->columnCount(); j++) {

                   if (model->data(model->index(i, j)).toString().length() > 0)
                       strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                   else
                       strList.append("");
               }
               data << strList.join(";") + "\n";
           }
           file.close();
           QMessageBox::information(this,"Exporter To Excel","Exporter En Excel Avec Succées ");
       }
}

void MainWindow::on_pushButton_pdf_a_clicked()
{
    QPrinter print;
            print.setPrinterName("imprimer");
            QPrintDialog dialog(&print, this);
            if(dialog.exec()==QDialog::Rejected) return;
            ui->tableView_a->render(&print);
}

void MainWindow::on_pushButton_afficher_a_clicked()
{
    ui->tableView_a->setModel(Etmp.afficher()); //afficher normale
}

void MainWindow::on_push_afficher_archive_a_clicked()
{
    ui->tableView_a->setModel(Etmp.AfficherArchive());
}

void MainWindow::on_push_archiver_a_clicked()
{
    int id = ui->tableView_a->model()->data(ui->tableView_a->model()->index(ui->tableView_a->currentIndex().row(),0)).toInt();
    int montant = ui->tableView_a->model()->data(ui->tableView_a->model()->index(ui->tableView_a->currentIndex().row(),1)).toInt();
    bool ok1 = f.archiver(id,montant);
    bool ok = f.supprimer(id);
    Etmp.notifications(id);
    if(ok && ok1)
    {
        QMessageBox::information(nullptr, QObject::tr("success"),
                    QObject::tr("facture archive.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("fail"),
                    QObject::tr("facture non archive.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_push_Desar_a_clicked()
{
    int id = ui->tableView_a->model()->data(ui->tableView_a->model()->index(ui->tableView_a->currentIndex().row(),0)).toInt();
    int montant = ui->tableView_a->model()->data(ui->tableView_a->model()->index(ui->tableView_a->currentIndex().row(),1)).toInt();
   Facture ftmp(montant,id);
   bool ok1 = ftmp.ajouter();
   bool ok = f.desArchiver(id);

    if(ok && ok1)
    {
        QMessageBox::information(nullptr, QObject::tr("success"),
                    QObject::tr("facture désarchivée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("fail"),
                    QObject::tr(" echec désarchive .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
