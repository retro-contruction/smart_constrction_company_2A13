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



    query.prepare("insert into facture (id_facture,montant)" "values(:id_facture,:montant)");
    //creation des variables
    query.bindValue(":id_facture",id_facture);
    query.bindValue(":montant",montant);
    return query.exec();
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
bool Facture::supprimer(int id)
{
    QSqlQuery query;

    QString idStr = QString::number(id);

    query.prepare("Delete from facture where id_facture= :id_facture ");
    //creation des variables
    query.bindValue(":id_facture",idStr);
    return query.exec();
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

QSqlQueryModel * Facture::rechercher(QString query)
{
    QSqlQueryModel * model=new QSqlQueryModel(); // aamalet model

    model->setQuery("SELECT * from facture where id_facture like '%" +query+"%' or montant like '%"+query+"%'"); // passage de db vers model
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("montant "));

    return model;
}
QSqlQueryModel* Facture::trie()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("select *FROM Facture ORDER BY id_facture  ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("montant"));

    return model;
}

void Facture::exporterpdf(QTextBrowser *text)
{

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
bool Facture::archiver(int ida , int montanta)
{
    QSqlQuery query;
        query.prepare("INSERT INTO Facture_archives(id_facture, montant) "
                            "VALUES (:id_facture, :montant)");
        query.bindValue(":id_facture", ida);
        query.bindValue(":montant", montanta);

return query.exec();
}

QSqlQueryModel * Facture::AfficherArchive()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from facture_archives");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_facture"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("montant"));

return model;
}



bool Facture::desArchiver(int iddes)
{
    QSqlQuery query;
    query.prepare("Delete from FACTURE_archives where id_facture = :id ");
    query.bindValue(":id", iddes);
return    query.exec();
}

void Facture::notifications(int idn)
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
            QString res=QString::number(idn);
            notifyIcon->show();
            notifyIcon->showMessage("UPDATE","la facture dont l'id est "+res+" est archivée",QSystemTrayIcon::Information,15000);
}

