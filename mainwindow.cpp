 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>
#include "terrain.h"
#include "excel.h"
#include <QFileDialog>
#include <QFile>
#include <QValidator>
#include <QIntValidator>
#include <QTextStream>
#include <QtPrintSupport/QPrinter>
#include <QPainter>
#include <QPixmap>
#include <QQuickItem>
#include <QCoreApplication>
#include <QtNetwork/QtNetwork>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableTerrain->setModel(T.afficherTerrain());



        QRegExp rx("[a-zA-Z]+");
       // QValidator *validator = new
        QRegExpValidator(rx, this->ui->lineEdit_ville);


       ui->lineEdit_dimens->setValidator(new QIntValidator(0, 9999, this));
       QPixmap pi("C:/Users/Meddeb sofien/Desktop/projet2A c++/ggg.PNG");
       ui->label_2->setPixmap(pi.scaled(231,211,Qt::KeepAspectRatio));
       ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
               ui->quickWidget->show();
               auto obj = ui->quickWidget->rootObject();
               connect(this, SIGNAL(setCenter(QVariant, QVariant)), obj, SLOT(setCenter(QVariant, QVariant)));
               connect(this, SIGNAL(addMarker(QVariant, QVariant)), obj, SLOT(addMarker(QVariant, QVariant)));

               emit setCenter(37.27561, 9.86718);
               emit addMarker(37.27561, 9.86718);

               // read_from_arduino();


               int ret=A.connect_arduino(); // lancer la connexion à arduino
                   switch(ret){
                   case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
                       break;
                   case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
                      break;
                   case(-1):qDebug() << "arduino is not available";
                   }
                    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_clicked()
{
    QString plan;
    QString file_name= QFileDialog::getOpenFileName(this,"open a file","c://");
   // QFile file("c://");
    ui->lineEditplan->insert(file_name);
    QPixmap pix(file_name);
    ui->label_pic->setPixmap(pix.scaled(150,150,Qt::KeepAspectRatio));
}


void MainWindow::on_AjouterTerrain_clicked()
{
    QString  id,ville,adresse;
    QString plan;
    int etat;
    int dimension;

   id=ui->lineEdit_id->text();
   ville=ui->lineEdit_ville->text();
   dimension=ui->lineEdit_dimens->text().toFloat();
   adresse=ui->lineEditAdresse->text();
   etat=ui->comboBoxEtat->currentText().toInt();
   plan=ui->lineEditplan->text();
   if(id=="" || ville=="" || adresse=="" /*|| dimension==NULL*/ )
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
    QFile plan;
    int dimension,etat;
    id=ui->lineEdit_id_2->text();
    dimension=ui->lineEdit_dimens_2->text().toInt();
    etat=ui->comboBoxEtat_2->currentText().toInt();
    ville=ui->lineEdit_ville_2->text();
    adresse=ui->lineEditAdr2->text();

    if(id=="" || ville=="" || adresse=="" /*|| dimension==NULL*/ )
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



void MainWindow::on_pushButton_2_clicked()
{
    QString ville ;
    ville=ui->lineEditChercheVille->text();
    ui->tableView11->setModel(T.rechercher(ville));
}

void MainWindow::on_trier_clicked()
{
    ui->tableTerrain->setModel(T.tri_dim());
    //ui->tableTerrain->columnAt(3);

}

void MainWindow::on_buttStatistique_clicked()
{
    stat = new statistique(this);
    stat->show();



}

void MainWindow::on_trier_2_clicked()
{
    ui->tableTerrain->setModel(T.tri_dimdesc());

}

void MainWindow::on_pushButton_map_clicked()
{
    maps= new map(this);
    maps->show();
}

void MainWindow::on_pushButton_pdf_clicked()
{
   Terrain t;
   t.exporterpdf(ui->textBrowser);
}



void MainWindow::on_pushButton_excel_clicked()
{

    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                           tr("Excel Files (*.xls)"));
           if (fileName.isEmpty())
               return;

           ExportExcelObject obj(fileName, "mydata", ui->tableTerrain);

           //colums to export
           obj.addField(0, "id", "char(20)");
           obj.addField(1, "dimension", "int");
           obj.addField(2, "etat", "int");
           obj.addField(3, "ville", "char(20)");
          // obj.addField(4, "plan", "char(100)");
           obj.addField(5, "adresse", "char(20)");




           int retVal = obj.export2Excel();
           if( retVal > 0)
           {
               QMessageBox::information(this, tr("Done"),
                                        QString(tr("%1 records exported!")).arg(retVal)
                                        );

            }
}

void MainWindow::on_locate_clicked()
{
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
            ui->quickWidget->show();
            auto obj = ui->quickWidget->rootObject();
            connect(this, SIGNAL(setCenter(QVariant, QVariant)), obj, SLOT(setCenter(QVariant, QVariant)));
            connect(this, SIGNAL(addMarker(QVariant, QVariant)), obj, SLOT(addMarker(QVariant, QVariant)));

        emit setCenter(ui->lineEdit_9->text().toFloat(), ui->lineEdit_12->text().toFloat());
        emit addMarker(ui->lineEdit_9->text().toFloat(), ui->lineEdit_12->text().toFloat());
}
void MainWindow::update_label()
{
    data = A.read_from_arduino();
    qDebug() << "mm";
    if(data != "0")
    {
        ui->label_11->setText("Mouvement  detecté");
    }
    else
    {
        ui->label_11->setText("Mouvement non detecté");
    }
}

/*void MainWindow::on_pushButton_3_clicked()
{
    A.write_to_arduino("0");
}*/
