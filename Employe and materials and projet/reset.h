#ifndef RESET_H
#define RESET_H

#include <QDialog>
#include "employes.h"
#include "gestionemployes.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"


namespace Ui {
class Reset;
}

class Reset : public QDialog
{
    Q_OBJECT

public:
    explicit Reset(QWidget *parent = nullptr);
    ~Reset();
private:



    QString mail,mdp,resetcode;


public:

    Reset(QString);
    Reset(QString,QString);




   QString getmail();
   QString getmdp();


    void setmail(QString);
    void setmdp(QString);


    bool add(QString);
    bool update(QString mail);
    bool rech(QString);


private slots:
    //void on_randcode_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_clicked();

private:
    Ui::Reset *ui;
};

#endif // RESET_H
