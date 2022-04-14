#include "mainwindow.h"
#include "connection.h"
#include "QDebug"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool t=c.createconnect();
    qDebug()<<t;
    MainWindow w;
    w.show();
    return a.exec();
}
