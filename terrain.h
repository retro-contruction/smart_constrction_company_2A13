#ifndef TERRAIN_H
#define TERRAIN_H
#include <QString>
#include <QObject>
#include <QWidget>

#include <QSqlQueryModel>
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
};

#endif // TERRAIN_H
