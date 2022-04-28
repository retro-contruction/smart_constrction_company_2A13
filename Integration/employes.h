#ifndef EMPLOYES_H
#define EMPLOYES_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTextBrowser>
#include <QTextEdit>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>





class Employes
{
private:



    QString id,nom,prenom,poste,email;


public:

    Employes();
    Employes(QString,QString,QString,QString,QString);




   QString getid();
   QString getnom();
   QString getprenom();
   QString getposte();
   QString getemail();



    void setid(QString);
    void setnom(QString);
    void setprenom(QString);
    void setposte(QString);
    void setemail(QString);

    bool checkforint(QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier(QString);
    void exporterpdf(QTextBrowser *text);

    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel *tri();
    QSqlQueryModel* update(QString p,QString e);
    void mailSent(QString);
    QSqlQueryModel * modifier_liste_employes();


};














#endif // EMPLOYES_H
