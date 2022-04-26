#include "reset.h"
#include "ui_reset.h"
#include "employes.h"
#include "gestionemployes.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "smtpreset.h"


Reset::Reset(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reset)
{
    ui->setupUi(this);
}

Reset::~Reset()
{
    delete ui;
}



bool Reset::add(QString mail)
{

QSqlQuery query;
;

query.prepare("UPDATE login set RESETCODE ='"+resetcode+"' where mail like '"+mail+"'  ");
query.bindValue(":resetcode", resetcode);

 return query.exec();

}




bool Reset::update(QString resetcode)
{


QSqlQuery query;
;

query.prepare("UPDATE login set mdp ='"+mdp+"' where resetcode like '"+resetcode+"'  ");
query.bindValue(":mdp", mdp);

 return query.exec();

}



Reset::Reset(QString nvpass )
{

  this->mdp=nvpass;
}


void Reset::on_pushButton_clicked()
{

    QString code=ui->randcode->text();
    QString nvpass=ui->nvmdp->text();

    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from login where resetcode like '"+code+"' ");
    if(model->rowCount()==1)
    {


        Reset R(nvpass);


        if(R.update(code)) {
            QMessageBox::information(nullptr, QObject::tr("C'est fait !!!"),
                        QObject::tr("Password Reseted \n" ), QMessageBox::Cancel);
          }



    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("ECHEC!!!"),
                    QObject::tr("Reset Code Not Correct.\n"), QMessageBox::Cancel);
    }




}
