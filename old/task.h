#ifndef TASK_H
#define TASK_H
#include "QDate"
#include "QString"
#include "QSqlQuery"
#include "QSqlQueryModel"
class task
{
    int TASK_ID;
    QString DESCRIPTION;

    public:
    QSqlQueryModel* afficher();
    QSqlQueryModel* afficher2();
    QSqlQueryModel* afficher3();
    QSqlQueryModel* insert(QString tid,QString t);
    QSqlQueryModel*update(QString t,QString e);
};

#endif // TASK_H
