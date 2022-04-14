#ifndef PROJET2T_H
#define PROJET2T_H
#include "QDate"
#include "QString"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>

class projet2t
{
    QString ID_PROJET;
    QString RESPONSABLE;
    QDate DATE_DEBUT;
    QDate DATE_ESTIMATION;
    QDate DATE_FIN;

    public:
    QSqlQueryModel* recherche(QString q);
    QSqlQueryModel* trie();
    QSqlQueryModel* afficher();
    void exporterpdf(int idc);
};

#endif // PROJET2T_H
