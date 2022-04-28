#include "client.h"
#include "ui_client.h"
#include <QString>
#include <QSqlQuery>
#include <QObject>
#include <QSqlQueryModel>
#include <QtDebug>
client::client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);
}

client::~client()
{
    delete ui;
}
client::client()
{
     id=0;
     nom="";
     prenom="";
     numtel=0;
     adresse ="";
}
client::client(int id , QString nom, QString prenom, int numtel,QString adresse){
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->numtel=numtel;
    this->adresse=adresse;
}
int client::getId(){ return this->id ;}
QString client::getNom(){ return this->nom ;}
QString client::getPrenom(){ return this->prenom ;}
int client::getNumtel(){return this->numtel ;}
QString client::getAdresse(){return adresse ;}
void client::setId(int i){ id=i;}
bool client::ajouterClient(){
    QSqlQuery query;
    query.prepare("INSERT INTO CLIENT (id,nom,prenom,numtel,adresse) VALUES (:id,:nom,:prenom,:numtel,:adresse)");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":numtel",numtel);
    query.bindValue(":adresse",adresse);

    return query.exec();


}
QSqlQueryModel* client::afficherClient(){

    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from CLIENT");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Num Tel"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));

    return model;
}
bool client::supprimerClient(int id){
    QSqlQuery query;

    query.prepare("DELETE  FROM CLIENT WHERE id = :id");
    query.bindValue(":id",id);
    return query.exec();

}
bool client::modifierClient(int ,QString,QString,int,QString){

    QSqlQuery query;

   query.prepare("update CLIENT set id=:id,nom=:nom,prenom=:prenom,numtel=:numtel,adresse=:adresse where id=:id");
   query.bindValue(":id",id);
   query.bindValue(":nom",nom);
   query.bindValue(":prenom",prenom);
   query.bindValue(":numtel",numtel);
   query.bindValue(":adresse",adresse);
   return query.exec();

}
