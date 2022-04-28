#ifndef TERRAIN_H
#define TERRAIN_H

#include <QString>
#include <QObject>
#include <QWidget>

#include <QSqlQueryModel>
#include <QTextBrowser>
#include <QTextEdit>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
class Terrain
{
    QString id,ville,plan,adresse;
    int etat;
    int dimension;


public:
    Terrain();
    Terrain(QString,int,int,QString,QString,QString);
    QString get_id();
    int get_dimension();
    int get_etat();
    QString get_ville();
    void set_id(QString);
    bool ajouterTerrain();
 QSqlQueryModel* afficherTerrain();
 bool supprimerTerrain(QString);
 bool modifier(QString,int,int,QString,QString);
 QSqlQueryModel*rechercher(QString);
 QSqlQueryModel * tri_dim();
  QSqlQueryModel * tri_dimdesc();
  void exporterpdf(QTextBrowser *text);

  int nbetat0();
  int nbetat1();
};

#endif // TERRAIN_H
