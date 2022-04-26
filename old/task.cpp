#include "task.h"
#include "employe.h"
QSqlQueryModel* task::afficher(){


    QSqlQueryModel* model = new QSqlQueryModel();



    model->setQuery("SELECT * FROM TASKS INNER JOIN EMPLOYES ON TASKS.TASK_ID = EMPLOYES.TASK_ID");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("TASK_ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESCRIPTION"));

         return model;
 }
QSqlQueryModel* task::afficher2(){


    QSqlQueryModel* model = new QSqlQueryModel();



    model->setQuery("SELECT TASK_ID FROM TASKS ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("TASK_ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESCRIPTION"));

         return model;
 }
QSqlQueryModel* task::afficher3(){


    QSqlQueryModel* model = new QSqlQueryModel();



    model->setQuery("SELECT * FROM TASKS ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("TASK_ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESCRIPTION"));

         return model;
 }
QSqlQueryModel* task::insert(QString tid,QString t){


    QSqlQueryModel* model = new QSqlQueryModel();



    model->setQuery("INSERT INTO TASKS (TASK_ID,DESCRIPTION) VALUES ('"+tid+"','"+t+"')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("TASK_ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESCRIPTION"));

         return model;
 }
QSqlQueryModel* task::update(QString t,QString e){


    QSqlQueryModel* model = new QSqlQueryModel();



    model->setQuery("UPDATE EMPLOYES SET TASK_ID = '"+t+"' WHERE ID = '"+e+"'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("TASK_ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESCRIPTION"));

         return model;
 }
