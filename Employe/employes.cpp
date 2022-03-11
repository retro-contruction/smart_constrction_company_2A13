#include "employes.h"
#include <QMessageBox>
#include <QtDebug>



Employes::Employes()
{
   id="";
   nom="";
   prenom="";
   poste="";

}

Employes::Employes(QString id,QString nom ,QString prenom ,QString poste)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->poste=poste;

}


QString Employes::getid(){ return id;}
QString Employes::getnom(){ return nom;}
QString Employes::getprenom(){ return prenom;}
QString Employes::getposte(){ return poste;}



void Employes::setid(QString id){this->id=id;}
void Employes::setnom(QString nom){this->nom=nom;}
void Employes::setprenom(QString prenom){ this->prenom=prenom;}
void Employes::setposte(QString poste){ this->poste=poste;}


bool Employes::ajouter()
{

QSqlQuery query;
;

query.prepare("INSERT INTO employes (id,nom,prenom,poste) "
              "VALUES (:id,:nom,:prenom,:poste)");
query.bindValue(":id", id);
query.bindValue(":nom", nom);
query.bindValue(":prenom",prenom);
query.bindValue(":poste",poste);
 return query.exec();

}

QSqlQueryModel * Employes::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from employes ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("poste"));

        return model;
}

bool Employes::supprimer(QString id)
{
    QSqlQuery query;
    query.prepare("Delete from employes where id=:id");
    query.bindValue(0,id);
    return query.exec();
}

bool Employes::modifier(QString  id)
{
    QSqlQuery query;



    query.prepare("UPDATE employes set  id='"+id+"',nom='"+nom+"',prenom='"+prenom+"',poste='"+poste+"'where id like '"+id+"' ");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":poste",poste);
     return query.exec();
}


QSqlQueryModel * Employes::modifier_liste_employes()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select id from employes ");

        return model;
}





bool Employes::checkforint(QString x)
{
bool check=true;
if(x.isEmpty())
{
    check=false;
    return check;
    }
else
{
    for(int i=0;i<x.size();i++)
    {

        if(x[i].isDigit())
        {
         check=false;
         break;
        }
    }
}

return check;

}

























/*
QSqlQueryModel *Employes::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from employes where fonction LIKE '"+rech+"%' or dateemb LIKE '"+rech+"%'");
    return model;
}

QSqlQueryModel * Employes::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from employes ORDER BY salaire DESC");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("matemp"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("salaire"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("dateemb "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("prenom "));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("fonction "));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("congeemp"));

        return model;
}










*/
