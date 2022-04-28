#include "terrain.h"

#include <QString>
#include <QSqlQuery>
#include <QObject>
#include <QSqlQueryModel>
#include <QtDebug>
#include <QFile>
#include "mainwindow.h"
#include <QTextBrowser>
#include <QTextEdit>
#include <QPdfWriter>
#include <QPainter>
#include <QPixmap>
Terrain::Terrain()
{
  id="";
  ville="";
  dimension=0;
  etat=0;
}

Terrain::Terrain(QString id,int dimension,int etat,QString ville,QString plan,QString adresse){
    this->id=id;
    this->dimension=dimension;
    this->etat=etat;
    this->ville=ville;
    this->plan=plan;
    this->adresse=adresse;
}
void Terrain::set_id(QString id){this->id=id;  }
QString Terrain::get_id(){ return  this->id ;}
int Terrain::get_dimension(){return  this->dimension ;}
int Terrain::get_etat(){ return  this->etat;}
QString Terrain::get_ville(){ return this->ville ;}
bool Terrain::ajouterTerrain(){
    QSqlQuery query;
    QString dimensionn= QString::number(dimension);
    query.prepare("INSERT INTO TERRAINS (id,dimension,etat,ville,plan,adresse) VALUES (:id,:dimension,:etat,:ville,:plan,:adresse)");
    query.bindValue(":id",id);
    query.bindValue(":dimension",dimensionn);
    query.bindValue(":etat",etat);
    query.bindValue(":ville",ville);
    query.bindValue(":plan",plan);
    query.bindValue(":adresse",adresse);
    return query.exec();
}
QSqlQueryModel* Terrain::afficherTerrain(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from TERRAINS");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Dimension"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("etat"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ville"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("plan"));

    return model;

}
bool Terrain::supprimerTerrain(QString id){
    QSqlQuery query;

    query.prepare("DELETE  FROM TERRAINS WHERE id = :id");
    query.bindValue(":id",id);
    return query.exec();
}
bool Terrain::modifier(QString id,int dimension,int etat,QString ville,QString adresse){

    QSqlQuery query;
    QString dimensionn= QString::number(dimension);
   query.prepare("update TERRAINS set id=:id,dimension=:dimension,etat=:etat,ville=:ville,adresse=:adresse where id=:id");
   query.bindValue(":id",id);
   query.bindValue(":dimension",dimensionn);
   query.bindValue(":etat",etat);
   query.bindValue(":ville",ville);
   //query.bindValue(":plan",plan);
   query.bindValue(":adresse",adresse);
   return query.exec();



}
QSqlQueryModel* Terrain::rechercher(QString v)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from TERRAINS where ville LIKE '%"+v+"%' ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Dimension"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("etat"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ville"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("plan"));
        return model;

}

QSqlQueryModel * Terrain::tri_dim()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from terrains order by dimension ASC");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Dimension"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("etat"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("ville"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("adresse"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("plan"));
    return model;
}
QSqlQueryModel * Terrain::tri_dimdesc()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from terrains order by dimension DESC");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Dimension"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("etat"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("ville"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("adresse"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("plan"));
    return model;
}
void Terrain::exporterpdf(QTextBrowser *text)
    {
      // QString tt;
        QSqlQuery qry;
        std::list<QString> tt;
        qry.exec("select * from terrains");
        while(qry.next())
        {
            tt.push_back("id: "+qry.value(0).toString()+"\n"+
                         "Dimension: "+qry.value(1).toString()+"\n"+
                         "etat: "+qry.value(2).toString()+"\n"+
                         "ville: "+qry.value(3).toString()+"\n"+
                         "plan: "+qry.value(4).toString()+"\n"+
                         "adresse:"+qry.value(5).toString()+"\n");



        }

        for(std::list<QString>::iterator it =tt.begin();it!=tt.end();++it)
        {
            text->setText(text->toPlainText()+*it + "**********************************************************\n");
        }

        QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);
        text->print(&printer);
    }
int Terrain::nbetat0(){

    QSqlQuery qry;
    int nb=0;
    qry.exec("select etat from terrains where etat=0");
    while(qry.next()){
         nb=nb+1;
    }
    return nb;

}
int Terrain::nbetat1(){

    QSqlQuery qry;
    int nb=0;
    qry.exec("select etat from terrains where etat=1");
    while(qry.next()){
         nb=nb+1;
    }
    return nb;

}
