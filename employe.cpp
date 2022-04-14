#include "employe.h"

QSqlQueryModel* employe::afficher(){


   QSqlQueryModel* model = new QSqlQueryModel();



   model->setQuery("select * from EMPLOYES");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("FONCTION"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("SALAIRE"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_PROJET"));

        return model;
}
QSqlQueryModel* employe::update(QString p,QString e){


   QSqlQueryModel* model = new QSqlQueryModel();



   model->setQuery("UPDATE EMPLOYES SET ID_PROJET = '"+p+"' WHERE ID LIKE '"+e+"'");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("FONCTION"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("SALAIRE"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_PROJET"));

        return model;
}
