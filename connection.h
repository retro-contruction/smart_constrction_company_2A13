#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "QTextBrowser"
#include <QTextBrowser>
#include <QPrinter>
#include "QFileDialog"
#include <QTextDocument>

class Connection
{
public:
    Connection();
    bool createconnect();
};

#endif // CONNECTION_H
