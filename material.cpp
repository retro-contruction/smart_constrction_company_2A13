#include "material.h"
#include "mainwindow.h"
#include<QDebug>
#include <QMessageBox>
#include <iostream>
#include <string>
using namespace std;
material::material()
{

}
material::material(QString ref,QString nom,QString date_dachat,int quantite ,int etat)
{
    this->ref = ref;
    this->nom = nom;
    this->date_dachat = date_dachat;
    this->quantite = quantite;
    this->etat = etat;
}
bool material::ajout_material()
{

    QSqlQuery query;
    //QString res = QString::number(ref);
    query.prepare("INSERT INTO materials (nom,reference,date_dachat,QUANTITY,STATUS) ""VALUES (:nom,:ref,:date_dachat,:QUANTITY,:STATUS)");

    query.bindValue(":nom" , nom);
    query.bindValue(":ref" , ref);
    query.bindValue(":date_dachat" , date_dachat);
    query.bindValue(":QUANTITY" , quantite);
    query.bindValue(":STATUS" , 1);
    return query.exec();
}
void material::ajout_event(QString dates, QString event)
{

    QSqlQuery query;
    //QString res = QString::number(ref);
    query.prepare("INSERT INTO calender (dates,event) ""VALUES (:dates,:event)");

    query.bindValue(":dates" , dates);
    query.bindValue(":event" , event);
    query.exec();
}
bool material::supprimer(QString ref)
{
    QSqlQuery query;
   // QString res = QString::number(ref);
    query.prepare("Delete from materials where REFERENCE = :ref");
    query.bindValue(":ref" , ref);
    return query.exec();
}
void material::supprimer_event(QString event,QString dates)
{
    QSqlQuery query;
   // QString res = QString::number(ref);
    query.prepare("Delete from calender where (event = :event) AND (dates = :dates) ");
    query.bindValue(":event" , event);
    query.bindValue(":dates" , dates);
    query.exec();
}
QSqlQueryModel  * material::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from materials");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Reference"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date dachat"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Quantite"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Etat"));

    return model;
}
QSqlQueryModel  * material::afficher_search(QString search)
{
    cout << search.toStdString() << endl;
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from materials where NOM = '"+search+"'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Reference"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date dachat"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Quantite"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Etat"));

    return model;
}
QSqlQueryModel  * material::afficher_tri()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from materials ORDER BY NOM");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Reference"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date dachat"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Quantite"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Etat"));

    return model;
}
QSqlQueryModel  * material::afficher_tri_desc()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from materials ORDER BY NOM DESC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Reference"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date dachat"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Quantite"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Etat"));

    return model;
}


bool material::recherche(QString id,QString nom,QString date_dachat,int quantite,int etat)
{
   // QString input =typeid ("ijio").name();
   //cout << input.toStdString().compare("int");

   int x = date_dachat.split("/")[0].toInt();
    int y = date_dachat.split("/")[1].toInt();
    int z = date_dachat.split("/")[2].toInt();
   cout << x << endl;
   cout << y << endl;
    cout << z << endl;
    QSqlQuery query;
     query.exec("SELECT * FROM materials ");
     cout << id.toStdString() << endl;
     while (query.next()) {

             QString reff = query.value(1).toString();
           if(reff != id && id.length() < 20)
           {
               if(nom.length() < 20)
               {
                  if(x <= 31    && y <= 12  && 2999 > z && z > 1980)
                  {
                      if(quantite != NULL)
                      {
                          if(etat ==0 || etat == 1)
                          {
                          QMessageBox::information(nullptr, QObject::tr("wokssssssssss"),
                                      QObject::tr("no workssss yses\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
                          return true;
                          }
                          else
                          {
                              QMessageBox::critical(nullptr, QObject::tr("error"),
                                          QObject::tr("not valid status!!\n"
                                                      "Click Cancel to exit."), QMessageBox::Cancel);
                              return false;
                          }
                      }
                      else
                      {
                          QMessageBox::critical(nullptr, QObject::tr("error"),
                                      QObject::tr("NO value in quantity!!\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
                          return false;
                      }


                  }
                  else
                  {

                      QMessageBox::critical(nullptr, QObject::tr("error"),
                                  QObject::tr("Not a valid date!!\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
                      return false;
                  }
               }
               else
               {
                   QMessageBox::critical(nullptr, QObject::tr("error"),
                               QObject::tr("Name too long!!\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
                   return false;
               }
           }

     else
         {
             QMessageBox::critical(nullptr, QObject::tr("error"),
                         QObject::tr("Same id or length is too long!!\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
             return false;
         }
     return false;

        }
}
bool material::recherche_update(QString id,QString nom,QString date_dachat,int quantite,int etat)
{
   // QString input =typeid ("ijio").name();
   //cout << input.toStdString().compare("int");

   int x = date_dachat.split("/")[0].toInt();
    int y = date_dachat.split("/")[1].toInt();
    int z = date_dachat.split("/")[2].toInt();
   cout << x << endl;
   cout << y << endl;
    cout << z << endl;
    QSqlQuery query;
     query.exec("SELECT * FROM materials ");
     cout << id.toStdString() << endl;
     while (query.next()) {

             QString reff = query.value(1).toString();
           if(reff == id && id.length() < 20)
           {
               if(nom.length() < 20)
               {
                  if(x <= 31    && y <= 12  && 2999 > z && z > 1980)
                  {
                      if(quantite != NULL)
                      {
                          if(etat ==0 || etat == 1)
                          {
                          QMessageBox::information(nullptr, QObject::tr("wokssssssssss"),
                                      QObject::tr("no workssss yses\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
                          return true;
                          }
                          else
                          {
                              QMessageBox::critical(nullptr, QObject::tr("error"),
                                          QObject::tr("not valid status!!\n"
                                                      "Click Cancel to exit."), QMessageBox::Cancel);
                              return false;
                          }
                      }
                      else
                      {
                          QMessageBox::critical(nullptr, QObject::tr("error"),
                                      QObject::tr("NO value in quantity!!\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
                          return false;
                      }


                  }
                  else
                  {

                      QMessageBox::critical(nullptr, QObject::tr("error"),
                                  QObject::tr("Not a valid date!!\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
                      return false;
                  }
               }
               else
               {
                   QMessageBox::critical(nullptr, QObject::tr("error"),
                               QObject::tr("Name too long!!\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
                   return false;
               }
           }

     else
         {
             QMessageBox::critical(nullptr, QObject::tr("error"),
                         QObject::tr("Same id or length is too long!!\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
             return false;
         }
     return false;

        }
}

void material::modifier(QString id,QString name,QString date_dachat,QString quantite,QString etat)
{
    QSqlQuery query;

    query.prepare("update  materials set reference='"+id+"', nom='"+name+"',date_dachat='"+date_dachat+"',QUANTITY = '"+quantite+"' ,STATUS = '"+etat+"' where reference ='"+id+"'");
    if(query.exec())
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("Updated!!\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    }
    else
        QMessageBox::critical(nullptr, QObject::tr("error"),
                    QObject::tr("NOT UPDATED!!\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}


