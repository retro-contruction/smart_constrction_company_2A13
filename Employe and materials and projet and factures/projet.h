#ifndef projet_H
#define projet_H
#include "QDate"
#include "QString"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>

class projet
{
    QString ID_PROJET;
    QString RESPONSABLE;
    QDate DATE_DEBUT;
    QDate DATE_ESTIMATION;
    QDate DATE_FIN;

    public:
    QSqlQueryModel* ajout(QString id,QString res,QString deb,QString est,QString fin);
    QSqlQueryModel* recherche(QString q);
    QSqlQueryModel* trie();
    QSqlQueryModel* afficher();
    void exporterpdf(int idc);
};

#endif // projet_H
