#include "fichier.h"
#include "employes.h"
#include <QTextBrowser>
#include <QTextEdit>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>



    void Employes::exporterpdf(QTextBrowser *text)
        {
          // QString tt;
            QSqlQuery qry;
            std::list<QString> tt;
            qry.exec("select * from LIVRAISONS");
            while(qry.next())
            {
                tt.push_back("ID Livraison: "+qry.value(0).toString()+"\n"+"Etat Livraison: "+qry.value(1).toString()+"\n"+"Num Livreur: "+qry.value(2).toString()+"\n"+"Adresse Livraison: "+qry.value(3).toString()+"\n"+"Date Livraison: "+qry.value(4).toString()+"\n"+"ID Commande: "+qry.value(5).toString()+"\n");

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

