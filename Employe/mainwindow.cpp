#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestionemployes.h"
#include "reset.h"
#include "ui_reset.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "smtp.h"





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




int randomValue = rand() % 90000 + 10000;
QString resetcode = QString::number(randomValue);


Reset::Reset( QString mail,QString resetcode )
{
  this->mail=mail;
  this->resetcode=resetcode;
}






void MainWindow::on_pushButton_clicked()
{
    QString mail=ui->mail->text();
    QString password=ui->password->text();

    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from login where mail like '"+mail+"' and mdp like '"+password+"' ");
    if(model->rowCount()==1)
    {
            gestionemployes e1;
            this->hide();
            e1.setModal(true);
            e1.exec();



    }
    else QMessageBox::critical(nullptr, QObject::tr("acces refuse"),
                                QObject::tr("Vérifiez vos coordonnées."), QMessageBox::Cancel);


}





void MainWindow::on_pushButton_2_clicked()
{

    QString mail=ui->mail->text();
    QString password=ui->password->text();

  if(mail!= NULL)
  {

      QSqlQueryModel * model= new QSqlQueryModel();
      model->setQuery("select * from login where mail like '"+mail+"' ");
      if(model->rowCount()==1)
      {






              smtp* Smtp = new smtp("alarassaa147@gmail.com", "xwgasmdtzmkoiltb" , "smtp.gmail.com" , 465 );
                connect(Smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


                    Smtp->sendMail("alarassaa147@gmail.com" ,ui->mail->text(), "Reset Password",resetcode);

                    QMessageBox::warning(nullptr, QObject::tr("Mail"),
                                                    QObject::tr("C fait."), QMessageBox::Ok);




                    Reset R (mail,resetcode);


                    if(R.add(mail)) {
                        QMessageBox::information(nullptr, QObject::tr("BRAVO!!!"),
                                    QObject::tr("Ajout effectuer avec succés.\n" ), QMessageBox::Cancel);
                      }
                    else
                    {
                        QMessageBox::information(nullptr, QObject::tr("ECHEC!!!"),
                                    QObject::tr("Non Ajouter.\n"), QMessageBox::Cancel);
                    }

          Reset r;
          r.setModal(true);
          r.exec();




      }
      else
      {
          QMessageBox::critical(nullptr, QObject::tr("acces refuse"),
                                          QObject::tr("ce mail n'existe pas"), QMessageBox::Cancel);

      }




  }
  else
      QMessageBox::critical(nullptr, QObject::tr("acces refuse"),
                                      QObject::tr("Donner Votre E-mail"), QMessageBox::Cancel);
  }

