#ifndef GESTIONEMPLOYES_H
#define GESTIONEMPLOYES_H

#include <QDialog>
#include "employes.h"
#include "mainwindow.h"
#include "reset.h"

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



     void on_send_clicked();

     void on_pushButton_clicked();

     void on_ajouter_clicked();

     void on_tabWidget_currentChanged(int index);

     void on_supprimer_clicked();

     void on_modifier_clicked();

     void on_rechercherbutton_clicked();

     void on_pushButton_2_clicked();

     void on_pushButton_3_clicked();

private:
     Ui::gestionemployes *ui;
     Employes insemployes;
     QStringList files;
};

#endif // GESTIONEMPLOYES_H
