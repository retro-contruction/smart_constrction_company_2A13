#ifndef GESTIONEMPLOYES_H
#define GESTIONEMPLOYES_H

#include <QDialog>
#include "employes.h"
#include "mainwindow.h"
//#include "reset.h"
#include "arduino.h"

namespace Ui {
class gestionemployes;
}

class gestionemployes : public QDialog
{
    Q_OBJECT

public:
    explicit gestionemployes(QWidget *parent = nullptr);
    ~gestionemployes();

private slots:

     void mailSent(QString);
     void sendMail();
     void browse();
     void update_label();


     /*void on_send_clicked();

     void on_pushButton_clicked();*/

     void on_ajouter_clicked();

     void on_tabWidget_currentChanged(int index);

     void on_supprimer_clicked();

     void on_modifier_clicked();

     void on_rechercherbutton_clicked();

     void on_pushButton_2_clicked();

     void on_pushButton_3_clicked();

     //void on_label_20_linkActivated(const QString &link);

    /* void on_on_clicked();

     void on_off_clicked();*/

     //void on_rech_ter_clicked();

    // void on_arduino_linkActivated(const QString &link);

private:
     Ui::gestionemployes *ui;
     Employes insemployes;
     QStringList files;
     arduino A;
     QByteArray data;
};

#endif // GESTIONEMPLOYES_H
