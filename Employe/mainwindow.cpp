#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employes.h"
#include "smtp.h"
#include "fichier.h"
#include "employes.cpp"
#include <QMessageBox>
#include <QComboBox>
#include <QSpinBox>
#include<QIntValidator>
#include<QValidator>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPrinter>
#include <QPrintDialog>
#include <QProgressBar>
#include <QFile>
#include <QFileInfo>
#include <QDialog>
#include <QFileDialog>
#include <QTextBrowser>
#include <QTextEdit>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
       connect(ui->send, SIGNAL(clicked()),this, SLOT(sendMail()));
       connect(ui->exit, SIGNAL(clicked()),this, SLOT(close()));
       connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));
               //ui->status->setVisible(0);


/*
    QRegExp rx("[a-zA-Z]+");
    QValidator *validator = new QRegExpValidator(rx, this->ui->lineEdit_2);
    QLineEdit *edit = new QLineEdit(this->ui->lineEdit_2);
    edit->setValidator(validator);

    QRegExp rx1("[a-zA-Z]+");
    QValidator *validator1 = new QRegExpValidator(rx, this->ui->lineEdit_3);
    QLineEdit *edit1 = new QLineEdit(this->ui->lineEdit_3);
    edit1->setValidator(validator1);
*/

   ui->lineEdit->setValidator(new QIntValidator(0, 99999999, this));


}




MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pushButton_clicked()
{
bool check=true;
bool check2=true;

    QString id=ui->lineEdit->text();
    QString nom=ui->lineEdit_2->text();
    QString prenom=ui->lineEdit_3->text();
    QString poste=ui->comboBox_3->currentText();
    QString email=ui->lineEdit_5->text();


    Employes E(id,nom,prenom,poste,email);


    check=E.checkforint(nom);
    check2=E.checkforint(prenom);
    if(id!= NULL && nom!=NULL && prenom!=NULL && poste!= NULL && email!= NULL && check && check2 )
    {


    if(E.ajouter()) {
        QMessageBox::information(nullptr, QObject::tr("BRAVO!!!"),
                    QObject::tr("Ajout effectuer avec succés.\n" ), QMessageBox::Cancel);



        }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("ECHEC!!!"),
                    QObject::tr("employé existe déja.\n"), QMessageBox::Cancel);
    }
    }

    else
        QMessageBox::information(nullptr, QObject::tr("ECHEC!!!"),
                    QObject::tr("Tous les champs doivent etre remplis Et nom et prenom doivent avoir seulement des caracteres.\n"), QMessageBox::Cancel);

}





void MainWindow::on_tabWidget_currentChanged(int index)
{

ui->test->setEnabled(true);
ui->test->setModel(insemployes.afficher());
ui->comboBox->setModel(insemployes.modifier_liste_employes());
ui->comboBox_2->setModel(insemployes.modifier_liste_employes());


}




    void MainWindow::on_pushButton_2_clicked()
    {


        Employes e1;
            e1.setid(ui->comboBox->currentText());
            if(e1.supprimer(e1.getid()))
            {
                QMessageBox::information(nullptr, QObject::tr("Supprimer un employé"),
                            QObject::tr("Suppression avec succés.\n" ), QMessageBox::Cancel);

            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("Erreur!"),
                            QObject::tr("non supprimé.\n"
                                        ), QMessageBox::Cancel);

            }
}


void MainWindow::on_pushButton_3_clicked()
{
    bool check=true;
    bool check2=true;

        QString id=ui->comboBox_2->currentText();
        QString nom=ui->lineEdit_6->text();
        QString prenom=ui->lineEdit_7->text();
        QString poste=ui->comboBox_4->currentText();
        QString email=ui->lineEdit_8->text();

        Employes E(id,nom,prenom,poste,email);
       check=E.checkforint(nom);
       check2=E.checkforint(prenom);
       if(id!= NULL && nom!=NULL && prenom!=NULL && poste!= NULL && email!= NULL && check && check2 )
       {
        if(E.modifier(id))
        {
                  QMessageBox::information(nullptr, QObject::tr("Modifier un employé"),
                              QObject::tr("employé modifie.\n"), QMessageBox::Cancel);

        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Modifier un employé"),
                              QObject::tr("Erreur !\n"), QMessageBox::Cancel);
        }
       }
        else
        {
            QMessageBox::information(nullptr, QObject::tr("ECHEC!!!"),
                        QObject::tr("Tous les champs doivent etre remplis Et nom et prenom doivent avoir seulement des caracteres.\n"), QMessageBox::Cancel);

    }

}




void MainWindow::on_pushButton_4_clicked()
{

    QString rech =ui->lineEdit_4->text();
    ui->test->setModel(insemployes.rechercher(rech));

}



void MainWindow::on_pushButton_5_clicked()
{
ui->test->setModel(insemployes.tri());

}




void MainWindow::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}





void MainWindow::sendMail()
{
    smtp* Smtp = new smtp(ui->username->text(), ui->password->text(), ui->server->text(), ui->port->text().toInt());
      connect(Smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

      if( !files.isEmpty() )
          Smtp->sendMail(ui->username->text(), ui->rcpt->text() , ui->sub->text(),ui->message->toPlainText(), files );
      else
          Smtp->sendMail(ui->username->text(), ui->rcpt->text() , ui->sub->text(),ui->message->toPlainText());
  }


void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    else
        QMessageBox::critical(nullptr, QObject::tr("non envoyé"),
                          QObject::tr("Erreur !\n"), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_6_clicked()
{
Employes e;
e.exporterpdf(ui->textBrowser);

}
