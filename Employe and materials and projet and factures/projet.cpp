#include "projet.h"
QSqlQueryModel* projet::ajout(QString ID_PROJET,QString RESPONSABLE,QString DATE_DEBUT,QString DATE_ESTIMATION,QString DATE_FIN){


   QSqlQueryModel* model = new QSqlQueryModel();



   model->setQuery("INSERT INTO PROJET (ID_PROJET,RESPONSABLE,DATE_DEBUT,DATE_ESTIMATION,DATE_FIN) VALUES ('"+ID_PROJET+"','"+RESPONSABLE+"','"+DATE_DEBUT+"','"+DATE_ESTIMATION+"','"+DATE_FIN+"')");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PROJET"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("RESPONSABLE"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_DEBUT"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_ESTIMATION"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_FIN"));

        return model;
}
QSqlQueryModel* projet::afficher(){


   QSqlQueryModel* model = new QSqlQueryModel();



   model->setQuery("select * from PROJET");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PROJET"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("RESPONSABLE"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_DEBUT"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_ESTIMATION"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_FIN"));

        return model;
}
QSqlQueryModel* projet::recherche(QString q){


   QSqlQueryModel* model = new QSqlQueryModel();



   model->setQuery("select * from PROJET WHERE ID_PROJET LIKE '%"+q+"%'");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PROJET"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("RESPONSABLE"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_DEBUT"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_ESTIMATION"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_FIN"));

        return model;
}
QSqlQueryModel* projet::trie(){


   QSqlQueryModel* model = new QSqlQueryModel();



   model->setQuery("select * from PROJET ORDER BY DATE_DEBUT DESC");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PROJET"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("RESPONSABLE"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_DEBUT"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_ESTIMATION"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_FIN"));

        return model;
}
void projet::exporterpdf( int idc)
 {
     QSqlQuery p;
     std::list<QString> tt;

     projet c;
     //commande 1
     p.exec("select * from projet");



     QString html ="<h1>PROJET PDF</h1>"
             "<style> table { font-family: arial, sans-serif; border-collapse: collapse; width: 100%; } td, th { border: 1px solid black; text-align: left; padding: 8px; } </style>"



     "<table align=justify  >"
             "<tr>"
               "<th>ID projet</th>"
               "<th>Responsable</th>"
             "<th>Date debut</th>"
             "<th>Date estimation</th>"
             "<th>Date fin</th>"

             "</tr>"  ;

     while(p.next()){
         html += "<tr>"
           "<td> ";
       html += p.value(0).toString()+" </td>";
       html += " <td>" + p.value(1).toString() + "</td>";
       html += " <td>" + p.value(2).toString() + "</td>";
       html += " <td>" + p.value(3).toString() + "</td>";
       html += " <td>" + p.value(4).toString() + "</td>";
       html += "</tr>";
     }




            //" </tr>"
           html += "</table>"
     "<p align=justify>"

     "</p>";

      QTextDocument document;
     document.setHtml(html);

     QPrinter printer(QPrinter::PrinterResolution);
     printer.setOutputFormat(QPrinter::PdfFormat);
     printer.setPaperSize(QPrinter::A4);
     printer.setOutputFileName("projet.pdf");
     printer.setPageMargins(QMarginsF(15, 15, 15, 15));

     document.print(&printer);
 }
