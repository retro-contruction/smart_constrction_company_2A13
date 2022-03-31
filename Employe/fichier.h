#ifndef FICHIER_H
#define FICHIER_H
#include <QTextBrowser>
#include <QTextEdit>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>

class fichier
{
public:
    fichier();
    void exporterpdf(QTextBrowser *text);
};

#endif // FICHIER_H
