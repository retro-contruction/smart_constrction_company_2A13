#ifndef EMPLOYES_H
#define EMPLOYES_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Employes
{
private:



    QString id,nom,prenom,poste;


public:

    Employes();
    Employes(QString,QString,QString,QString);




   QString getid();
   QString getnom();
   QString getprenom();
   QString getposte();




    void setid(QString);
    void setnom(QString);
    void setprenom(QString);
    void setposte(QString);



    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier(QString);

    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel *tri();

    QSqlQueryModel * modifier_liste_employes();

     //QSqlQuery recuperer(QString);
};














#endif // EMPLOYES_H
