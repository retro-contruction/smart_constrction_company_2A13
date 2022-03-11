#ifndef FACTURE_H
#define FACTURE_H

#include <QString>
#include "connection.h"
#include <QMessageBox>

class Facture
{
   float montant ;
   int id_facture;
public:
    Facture();
    Facture(float montant);
    void setMontant(float montant){this->montant=montant;};
    float getMontant(){return montant;};
    int getId_facture(){return id_facture;};
    bool ajouter();
    bool supprimer(int id);
    QSqlQueryModel* afficher();
};

#endif // FACTURE_H
