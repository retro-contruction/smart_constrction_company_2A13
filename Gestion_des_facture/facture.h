#ifndef FACTURE_H
#define FACTURE_H
#include <QTextBrowser>
#include <QPrinter>
#include "QFileDialog"
#include <QString>
#include "connection.h"
#include <QMessageBox>
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>
#include <QVector>
#include<QMainWindow>
#include <QLayout>
#include <QTextDocument>

class Facture
{
   int montant ;
   int id_facture;
public:
    Facture();
    Facture(int montant,int id_facture);
    void setMontant(float montant){this->montant=montant;};
    float getMontant(){return montant;};
    int getId_facture(){return id_facture;};
    bool ajouter();
    bool supprimer(int id);
     QSqlQueryModel *rechercher(QString query);
     QSqlQueryModel* trie();
    bool modifier(int id_facture,int montant);
    QSqlQueryModel* afficher();
    void exporterpdf(QTextBrowser *text);
  int ExportExcelObject();
};

#endif // FACTURE_H
