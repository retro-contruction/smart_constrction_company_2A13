#include "gestionemployes.h"
#include "ui_gestionemployes.h"
#include "employes.h"
#include "smtp.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
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

gestionemployes::gestionemployes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestionemployes)
{
    ui->setupUi(this);

    connect(ui->send, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->exit, SIGNAL(clicked()),this, SLOT(close()));
    connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));

     ui->id->setValidator(new QIntValidator(0, 99999999, this));
}



gestionemployes::~gestionemployes()
{
    delete ui;
}




void gestionemployes::on_ajouter_clicked()
{

    bool check=true;
    bool check2=true;

        QString id=ui->id->text();
        QString nom=ui->nom->text();
        QString prenom=ui->prenom->text();
        QString poste=ui->poste->currentText();
        QString email=ui->email->text();


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

void gestionemployes::on_tabWidget_currentChanged(int index)
{

    ui->test->setEnabled(true);
    ui->test->setModel(insemployes.afficher());
    ui->id_modif->setModel(insemployes.modifier_liste_employes());
    ui->supp_id->setModel(insemployes.modifier_liste_employes());


}

void gestionemployes::on_supprimer_clicked()
{
    Employes e1;
        e1.setid(ui->supp_id->currentText());
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



void gestionemployes::on_modifier_clicked()
{
    bool check=true;
    bool check2=true;

        QString id=ui->id_modif->currentText();
        QString nom=ui->nom_modif->text();
        QString prenom=ui->prenom_modif->text();
        QString poste=ui->poste_modif->currentText();
        QString email=ui->mail_modif->text();

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





void gestionemployes::on_rechercherbutton_clicked()
{
    QString rech =ui->rech->text();
    ui->test->setModel(insemployes.rechercher(rech));
}


void gestionemployes::on_pushButton_2_clicked()
{
    ui->test->setModel(insemployes.tri());
}


void gestionemployes::browse()
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





void gestionemployes::sendMail()
{
    smtp* Smtp = new smtp(ui->username->text(), ui->password->text(), ui->server->text(), ui->port->text().toInt());
      connect(Smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

      if( !files.isEmpty() )
          Smtp->sendMail(ui->username->text(), ui->rcpt->text() , ui->sub->text(),ui->message->toPlainText(), files );
      else
          Smtp->sendMail(ui->username->text(), ui->rcpt->text() , ui->sub->text(),ui->message->toPlainText());
  }


void gestionemployes::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    else
        QMessageBox::critical(nullptr, QObject::tr("non envoyé"),
                          QObject::tr("Erreur !\n"), QMessageBox::Cancel);
}




void gestionemployes::on_pushButton_3_clicked()
{
    Employes e;
    e.exporterpdf(ui->textBrowser);
}
