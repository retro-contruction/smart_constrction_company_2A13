#include "connection.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

Connection::Connection()
{

}



bool Connection::createconnect()
{
    bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("admin");//inserer nom de l'utilisateur
db.setPassword("admin");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;


    return  test;
}
