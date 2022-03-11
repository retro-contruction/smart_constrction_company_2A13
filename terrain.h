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
    float dimension;

public:
    Terrain();
    Terrain(QString,float,int,QString,QString,QString);
    QString get_id();
    float get_dimension();
    int get_etat();
    QString get_ville();
    void set_id(QString);
    bool ajouterTerrain();
 QSqlQueryModel* afficherTerrain();
 bool supprimerTerrain(QString);
 bool modifier(QString,float,int,QString,QString);
};

#endif // TERRAIN_H
