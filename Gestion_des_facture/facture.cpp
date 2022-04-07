#include "facture.h"


Facture::Facture()
{

}

Facture::Facture(int montant , int id_facture)
{
    this->montant=montant;
    this->id_facture=id_facture;
}

bool Facture::ajouter()
{
    QSqlQuery query;

    //QString montantStr = QString::number(montant);

    query.prepare("insert into facture (id_facture,montant)" "values(:id_facture,:montant)");
    //creation des variables
    query.bindValue(":id_facture",id_facture);
    query.bindValue(":montant",montant);
    return query.exec();
}
bool Facture::supprimer(int id)
{
    QSqlQuery query;

    QString idStr = QString::number(id);

    query.prepare("Delete from facture where id_facture= :id_facture ");
    //creation des variables
    query.bindValue(":id_facture",idStr);
    return query.exec();
}


QSqlQueryModel * Facture::rechercher(QString query)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("SELECT * from facture where id_facture like '%" +query+"%' or montant like '%"+query+"%'");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("montant "));


    return model;
}
QSqlQueryModel* Facture::trie()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    //if(index == 0)
    //{
        model->setQuery("select *FROM Facture ORDER BY id_facture  ");
    //}

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("montant"));




    return model;
}







QSqlQueryModel* Facture::afficher()
{
    //
   QSqlQueryModel *model=new QSqlQueryModel();
   model->setQuery("select * from facture");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("montant"));
   return model;
}
bool Facture::modifier(int id_facture,int montant)
{
    QSqlQuery query;
    //QString id_string=QString::number(id_facture);
    query.prepare("update facture set id_facture=:id_facture , montant=:montant where id_facture=:id_facture");
    query.bindValue(":id_facture", id_facture);
    query.bindValue(":montant", montant);


    return query.exec();
}
void Facture::exporterpdf(QTextBrowser *text)
{
  // QString tt;
    QSqlQuery qry;
    std::list<QString> tt;
    qry.exec("select * from facture order by ide");
    while(qry.next())
    {
        tt.push_back("IDE: "+qry.value(0).toString()+"\n"+"id_facture: "+qry.value(1).toString()+"\n"+"montant:" );

    }

    for(std::list<QString>::iterator it =tt.begin();it!=tt.end();++it)
    {
        text->setText(text->toPlainText()+*it  + "\n ------------------------------------------ \n" );
    }

    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);
    text->print(&printer);
}
