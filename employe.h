#ifndef EMPLOYE_H
#define EMPLOYE_H
#include "QDate"
#include "QString"
#include "QSqlQuery"
#include "QSqlQueryModel"

class employe
{
    QString ID;
    QString NOM;
    QString PRENOM;
    QString FONCTION;
    float SALAIRE;
    int ID_PROJET;

    public:
    QSqlQueryModel* afficher();
    QSqlQueryModel* update(QString p,QString e);
    QSqlQueryModel* affectation(QString e,int p);
};

#endif // EMPLOYE_H
