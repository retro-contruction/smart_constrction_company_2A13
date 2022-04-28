#include "employes.h"
#include <QMessageBox>
#include <QtDebug>
#include <QTextBrowser>
#include <QTextEdit>
#include <QPdfWriter>
#include <QPainter>


Employes::Employes()
{
   id="";
   nom="";
   prenom="";
   poste="";
   email="";

}

Employes::Employes(QString id,QString nom ,QString prenom ,QString poste,QString email)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->poste=poste;
  this->email=email;

}


QString Employes::getid(){ return id;}
QString Employes::getnom(){ return nom;}
QString Employes::getprenom(){ return prenom;}
QString Employes::getposte(){ return poste;}
QString Employes::getemail(){ return email;}



void Employes::setid(QString id){this->id=id;}
void Employes::setnom(QString nom){this->nom=nom;}
void Employes::setprenom(QString prenom){ this->prenom=prenom;}
void Employes::setposte(QString poste){ this->poste=poste;}
void Employes::setemail(QString email){ this->email=email;}


bool Employes::ajouter()
{

QSqlQuery query;
;

query.prepare("INSERT INTO employes (id,nom,prenom,poste,email) "
              "VALUES (:id,:nom,:prenom,:poste,:email)");
query.bindValue(":id", id);
query.bindValue(":nom", nom);
query.bindValue(":prenom",prenom);
query.bindValue(":poste",poste);
query.bindValue(":email",email);
 return query.exec();

}

QSqlQueryModel * Employes::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from employes ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("poste"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("email"));

        return model;
}

bool Employes::supprimer(QString id)
{
    QSqlQuery query;
    query.prepare("Delete from employes where id=:id");
    query.bindValue(0,id);
    return query.exec();
}

bool Employes::modifier(QString  id)
{
    QSqlQuery query;



    query.prepare("UPDATE employes set  id='"+id+"',nom='"+nom+"',prenom='"+prenom+"',poste='"+poste+"', email='"+email+"' where id like '"+id+"' ");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":poste",poste);
    query.bindValue(":email",email);
     return query.exec();
}


QSqlQueryModel * Employes::modifier_liste_employes()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select id from employes ");

        return model;
}





bool Employes::checkforint(QString x)
{
bool check=true;
if(x.isEmpty())
{
    check=false;
    return check;
    }
else
{
    for(int i=0;i<x.size();i++)
    {

        if(x[i].isDigit())
        {
         check=false;
         break;
        }
    }
}

return check;

}





QSqlQueryModel *Employes::rechercher(QString id)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from employes where id like '"+id+"' ");
    return model;
}



QSqlQueryModel * Employes::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from employes ORDER BY prenom ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("poste"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("email"));
        return model;
}




void Employes::exporterpdf(QTextBrowser *text)
    {
      // QString tt;
        QSqlQuery qry;
        std::list<QString> tt;
        qry.exec("select * from employes");
        while(qry.next())
        {
            tt.push_back("id: "+qry.value(0).toString()+"\n"+"nom: "+qry.value(1).toString()+"\n"+"prenom: "+qry.value(2).toString()+"\n"+"poste: "+qry.value(3).toString()+"\n"+"adresse: "+qry.value(4).toString()+"\n");

        }

        for(std::list<QString>::iterator it =tt.begin();it!=tt.end();++it)
        {
            text->setText(text->toPlainText()+*it + "----------------------------------------------------------\n");
        }

        QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);
        text->print(&printer);
    }

QSqlQueryModel* Employes::update(QString p,QString e){


   QSqlQueryModel* model = new QSqlQueryModel();



   model->setQuery("UPDATE EMPLOYES SET ID_PROJET = '"+p+"' WHERE ID LIKE '"+e+"'");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("FONCTION"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("SALAIRE"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_PROJET"));

        return model;
}






