#include "facture.h"

Facture::Facture()
{

}

Facture::Facture(float montant)
{
    this->montant=montant;
}

bool Facture::ajouter()
{
    QSqlQuery query;

    QString montantStr = QString::number(montant);

    query.prepare("insert into facture (montant)" "values(:montant)");
    //creation des variables
    query.bindValue(":montant",montantStr);
    return query.exec();
}
bool Facture::supprimer(int id)
{
    QSqlQuery query;

    QString idStr = QString::number(id);

    query.prepare("Delete from facture where id_facture= :id_facture ");
    //creation des variables
    query.bindValue(":id_facture",idStr);
    return query.exec();
}


QSqlQueryModel* Facture::afficher()
{
    //
   QSqlQueryModel *model=new QSqlQueryModel();
   model->setQuery("select * from facture");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("montant"));
   return model;
}
