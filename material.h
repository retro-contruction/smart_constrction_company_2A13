#ifndef MATERIAL_H
#define MATERIAL_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QSqlDatabase>
#include <QMessageBox>
#include<QDebug>

class material
{
    QString nom,date_dachat;
    QString ref;
    int quantite ;
    int etat ;


public:
    material();

    material(QString,QString ,QString ,int,int);

    bool ajout_material();
    bool supprimer(QString ref);
    bool recherche(QString ,QString ,QString ,int ,int t);
    void modifier(QString ,QString ,QString ,QString ,QString);
    bool recherche_update(QString ,QString ,QString ,int ,int );
    void ajout_event(QString, QString);
    void supprimer_event(QString ,QString);


    QSqlQueryModel  * afficher();
    QSqlQueryModel  * afficher_search(QString);
    QSqlQueryModel  * afficher_tri();
    QSqlQueryModel  * afficher_tri_desc();

};

#endif // MATERIAL_H
