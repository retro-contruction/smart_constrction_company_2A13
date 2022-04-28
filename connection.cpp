#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet_arwa");
db.setUserName("arwa");//inserer nom de l'utilisateur
db.setPassword("arwa");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
