#include "Form.h"
#include "ui_interfacelogin.h"
#include "material.h"
#include "smtp.h"
#include "arduino.h"
#include <iostream>
#include <string>
#include <QDate>
#include <QDateTime>
#include <QTimer>
#include <QPdfWriter>
#include <QPainter>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include <QTextBrowser>
#include <QtPrintSupport/QPrinter>
#include <QSerialPort>
#include <QSerialPortInfo>
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
#include <QFileDialog>


using namespace std;

Form::Form(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Form)
{
    ui->setupUi(this);
    statistic();
    update_materials();
    material a;
    ui->tableView->setModel(a.afficher());
    highlight_date();

    ard = new QSerialPort(this);


    qDebug() << "Number of ports: " << QSerialPortInfo::availablePorts().length() << "\n";
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        qDebug() << "Description: " << serialPortInfo.description() << "\n";
        qDebug() << "Has vendor id?: " << serialPortInfo.hasVendorIdentifier() << "\n";
        qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier() << "\n";
        qDebug() << "Has product id?: " << serialPortInfo.hasProductIdentifier() << "\n";
        qDebug() << "Product ID: " << serialPortInfo.productIdentifier() << "\n";

}
    bool arduino_is_available = false;
    QString arduino_uno_port_name;
    //
    //  For each available serial port
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        //  check if the serialport has both a product identifier and a vendor identifier
        if(serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier()){
            //  check if the product ID and the vendor ID match those of the arduino uno
            if((serialPortInfo.productIdentifier() == arduino_uno_producy_id)
                    && (serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id)){
                arduino_is_available = true; //    arduino uno is available on this port
                arduino_uno_port_name = serialPortInfo.portName();
            }
        }
    }

    /*
     *  Open and configure the arduino port if available
     */

    if(arduino_is_available){
        qDebug() << "Found the arduino port...\n";
        ard->setPortName(arduino_uno_port_name);
        ard->open(QSerialPort::ReadWrite);
        ard->setBaudRate(QSerialPort::Baud9600);
        ard->setDataBits(QSerialPort::Data8);
        ard->setFlowControl(QSerialPort::NoFlowControl);
        ard->setParity(QSerialPort::NoParity);
        ard->setStopBits(QSerialPort::OneStop);

    }else{
        qDebug() << "Couldn't find the correct port for the arduino.\n";
        QMessageBox::information(this, "Serial Port Error", "Couldn't open serial port to arduino.");
    }
    QObject::connect(ard, SIGNAL(readyRead()), this, SLOT(WRITE()));
    QObject::connect(ard, SIGNAL(readyRead()), this, SLOT(readSerial()));
     QObject::connect(A.getseriall(),SIGNAL(readyRead()),this,SLOT(update_label()) );
     //Arduino

         connect(ui->send, SIGNAL(clicked()),this, SLOT(sendMail()));
         connect(ui->exit, SIGNAL(clicked()),this, SLOT(close()));
         connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));

          ui->id->setValidator(new QIntValidator(0, 99999999, this));

    ui->label_23->setStyleSheet("QLabel { background-color : red; color : blue; }");

}
QString Form::showTime()
{
    QDate datee = QDate::currentDate();
    QString datee_text = datee.toString("dd/MM/yyyy");
    QString id = "ff1";
    QStringList list;
     QString jour;
    QString timee;
    QSqlQuery query;
     query.exec("SELECT * FROM casque where id_casque='"+id+"' ");
      while (query.next())
      {
          jour = query.value(1).toString();
           if(jour == datee_text)
           {
               work = true;
                timee = query.value(2).toString();
               list = timee.split(QRegularExpression("[:]"), QString::SkipEmptyParts);
               qDebug() << list.at(2);
               second = list.at(2).toInt();
               minutes = list.at(1).toInt();
               hours = list.at(0).toInt();

           }
      }
      if(work == false)
      {
          query.prepare("INSERT INTO casque (id_casque,jour,time) ""VALUES (:id_casque,:jour,:time)");

          query.bindValue(":id_casque" , id);
          query.bindValue(":jour" , datee_text);
          query.bindValue(":time" , 0);
          query.exec();
        }
       second = 1+ second;
       if(second == 60)
       {
           second = 0;
           minutes = minutes +1;
           if(minutes == 60)
           {
               minutes = 0;
               hours = hours +1;
           }
       }
       ui->hour->display(hours);
       ui->minute->display(minutes);
       ui->second->display(second);
       QString h =  QString::number(hours);
       QString m =  QString::number(minutes);
       QString s =  QString::number(second);
       QString full = h +":"+ m +":"+ s;
       qDebug() << full ;
       return full;


}
void Form::update_time(QString full_time)
{
    QDate datee = QDate::currentDate();
    QString datee_text = datee.toString("dd/MM/yyyy");
     qDebug() << datee_text ;
    QSqlQuery query;
    QString id = "ff1";
    query.prepare("update  casque set time ='"+full_time+"' where id_casque='"+id+"' AND jour='"+datee_text+"'");
    query.exec();

}
void Form::WRITE()
{
    qDebug() << write ;
    if(write == false)
    {
        qDebug() << "Is open : " << ard->isOpen() ;
        if (ard->isWritable())
        {
            ard->write("0");
        }
        else
            qDebug()<<"error en ecriture";
    }
    if(write == true)
    {
        qDebug() << "Is open : " << ard->isOpen() ;
        if (ard->isWritable())
        {
            ard->write("1");

        }
        else
            qDebug()<<"error en ecriture";
    }

}
void Form::readSerial()
{

    QByteArray serialData=ard->readAll();

    //qDebug() << serialData ;
        if(test == true)
        {
           data = QString::fromStdString(serialData.toStdString());
            qDebug() << data;
            if(data == "0")
            {
                ui->label_23->setStyleSheet("QLabel { background-color : red; color : blue; }");
                write = false;

            }
            if(data == "1")
            {
                ui->label_23->setStyleSheet("QLabel { background-color : green; color : blue; }");
                write = true;

                    QString tt = showTime();
                    update_time(tt);
            }
        }

        test = true;
}

Form::~Form()
{
    delete ui;
}

void Form::statistic()
{
    //x axis titles months
    QStringList categories;
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    std::array<int,20> f,e,a,b,c,d;

    QDate date = QDate::currentDate();
    int dates = date.month();
    if(dates == 1){ categories << "Aug" << "Sep" << "Oct" << "Nov" << "Dec" << "Jan";axisX->setRange(QString("Aug"), QString("Jan"));}
    if(dates == 2){ categories << "Sep" << "Oct" << "Nov" << "Dec" << "Jan" << "Feb";axisX->setRange(QString("Sep"), QString("Feb"));}
    if(dates == 3){ categories << "Oct" << "Nov" << "Dec" << "Jan" << "Feb" << "Mar";axisX->setRange(QString("Oct"), QString("Mar"));}
    if(dates == 4){ categories << "Nov" << "Dec" << "Jan" << "Feb" << "Mar" << "Apr";axisX->setRange(QString("Nov"), QString("Apr"));}
    if(dates == 5){categories << "Dec" << "Jan" << "Feb" << "Mar" << "Apr" << "May";axisX->setRange(QString("Dec"), QString("May"));}
    if(dates == 6){ categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";axisX->setRange(QString("Jan"), QString("Jun"));}
    if(dates == 7){categories << "Feb" << "Mar" << "Apr" << "May" << "Jun" << "Jul";axisX->setRange(QString("Feb"), QString("Jul"));}
    if(dates == 8){ categories << "Mar" << "Apr" << "May" << "Jun" << "Jul" << "Aug";axisX->setRange(QString("Mar"), QString("Aug"));}
    if(dates == 9){ categories << "Apr" << "May" << "Jun" << "Jul" << "Aug" << "Sep";axisX->setRange(QString("Apr"), QString("Sep"));}
    if(dates == 10){ categories << "May" << "Jun" << "Jul" << "Aug" << "Sep" << "Oct";axisX->setRange(QString("May"), QString("Oct"));}
    if(dates == 11){categories << "Jun" << "Jul" << "Aug" << "Sep" << "Oct" << "Nov";axisX->setRange(QString("Jun"), QString("Nov"));}
    if(dates == 12){ categories << "Jul" << "Aug" << "Sep" << "Oct" << "Nov" << "Dec";axisX->setRange(QString("Jul"), QString("Dec"));}

    cout << dates << endl;
    cout << categories.at(0).toStdString() << endl;
    int j=0,p=12;
    int i=dates;
    while(j!=6)
    {
            if(i != 0)
            {
                cout << "the fuck" << endl;
                QString mm = QString::number(i);
                if(i==dates)
                    f=get_stat(mm);
                if(i+1 == dates)
                    e=get_stat(mm);
                if(i+2 == dates)
                    d=get_stat(mm);
                if(i+3 == dates)
                    c=get_stat(mm);
                if(i+4 == dates)
                    b=get_stat(mm);
                if(i+5 == dates)
                    a=get_stat(mm);

            }
            if(i < 1)
            {

                cout << "the fuck" << endl;
                cout << j << endl;
                QString mm = QString::number(i+p);
                if(i==dates)
                    f=get_stat(mm);
                if(i+1 == dates)
                    e=get_stat(mm);
                if(i+2 == dates)
                    d=get_stat(mm);
                if(i+3 == dates)
                    c=get_stat(mm);
                if(i+4 == dates)
                    b=get_stat(mm);
                if(i+5 == dates)
                    a=get_stat(mm);
            }
    i--;
    j++;
    }

    QBarSet *set0 = new QBarSet("Iron");
    QBarSet *set1 = new QBarSet("Wood");
    QBarSet *set2 = new QBarSet("Sand");
    QBarSet *set3 = new QBarSet("Rock");
    QBarSet *set4 = new QBarSet("Gravel");

    *set0 << a[0] << b[0] << c[0] << d[0] << e[0] << f[0];
    *set1 << a[1] << b[1] << c[1] << d[1] << e[1] << f[1];
    *set2 << a[2] << b[2] << c[2]<< d[2] << e[2] << f[2];
    *set3 << a[3]<< b[3] << c[3]<< d[3] << e[3] << f[3];
    *set4 << a[4] << b[4]<< c[4] << d[4] << e[4] << f[4];

    QBarSeries *barseries = new QBarSeries();
       barseries->append(set0);
       barseries->append(set1);
       barseries->append(set2);
       barseries->append(set3);
       barseries->append(set4);

    QLineSeries *lineseries = new QLineSeries();
       lineseries->setName("trend");
       lineseries->append(QPoint(0, 4));
       lineseries->append(QPoint(1, 15));
       lineseries->append(QPoint(2, 20));
       lineseries->append(QPoint(3, 4));
       lineseries->append(QPoint(4, 12));
       lineseries->append(QPoint(5, 17));

       QChart *chart = new QChart();
          chart->addSeries(barseries);
          chart->addSeries(lineseries);
          chart->setTitle("Line and barchart example");




          axisX->append(categories);
          chart->addAxis(axisX, Qt::AlignBottom);
          lineseries->attachAxis(axisX);
          barseries->attachAxis(axisX);


         QValueAxis *axisY = new QValueAxis();
         chart->addAxis(axisY, Qt::AlignLeft);
         lineseries->attachAxis(axisY);
         barseries->attachAxis(axisY);
         axisY->setRange(0, 200);

         chart->legend()->setVisible(true);
         chart->legend()->setAlignment(Qt::AlignBottom);

         QChartView *chartView = new QChartView(chart);
         chartView->setRenderHint(QPainter::Antialiasing);
         chartView->setParent(ui->horizontalFrame);




}
std::array<int,20> Form::get_stat(QString mm)
{
    QSqlQuery query;
    std::array<int,20> h;
    query.prepare("select * from statistic where month='"+mm+"' ");
    if(query.exec())
    {
        while(query.next())
        {
            h[0]=query.value(1).toInt();
            h[1] =query.value(2).toInt();
            h[2]= query.value(3).toInt();
            h[3]= query.value(4).toInt();
            h[4]= query.value(5).toInt();
            cout << "ok god" << endl;
        }

    }
    return h;
}

void Form::on_pushButton_3_clicked()
{
    Sec = new SecDialog(this);
    Sec->show();

}
void Form::on_pushButton_5_clicked()
{
    material a;
    ui->tableView->setModel(a.afficher());

}



void Form::on_tableView_activated(const QModelIndex &index)
{

     val = ui->tableView->model()->data(index).toString();

     material a;
     a.supprimer(val);
     ui->tableView->setModel(a.afficher());

}


void Form::on_tableView_clicked(const QModelIndex &index)
{

    val = ui->tableView->model()->data(index).toString();
    QSqlQuery query;

    query.prepare("select * from materials where reference='"+val+"' ");
    if(query.exec())
    {
        while(query.next())
        {
            ui->lineEdit_3->setText(query.value(0).toString());
            ui->lineEdit_4->setText(query.value(1).toString());
            ui->lineEdit_5->setText(query.value(2).toString());
            ui->lineEdit_6->setText(query.value(3).toString());
            ui->lineEdit_7->setText(query.value(4).toString());
        }
    }

}

void Form::on_pushButton_6_clicked()
{
    QString id,name,date;
    material a;
    QString quant,status;
    name=ui->lineEdit_3->text();
    id = ui->lineEdit_4->text();
    date = ui->lineEdit_5->text();
    quant = ui->lineEdit_6->text();
    status = ui->lineEdit_7->text();
    bool ok = a.recherche_update(id,name,date,quant.toInt(),status.toInt());
    QSqlQuery query;
if(ok == true)
{
a.modifier(id, name, date, quant, status);

}
else
    QMessageBox::critical(this, tr("Erreur"),query.lastError().text());


     ui->tableView->setModel(a.afficher());



}

void Form::on_lineEdit_8_editingFinished()
{
    QString search  = ui->lineEdit_8->text();
    material a;
    if(search != NULL)
    ui->tableView->setModel(a.afficher_search(search));
    else
    {
         ui->tableView->setModel(a.afficher());
    }

}

void Form::on_pushButton_7_clicked()
{
    material a;
    ui->tableView->setModel(a.afficher_tri());
}

void Form::on_pushButton_8_clicked()
{
    material a;
    ui->tableView->setModel(a.afficher_tri_desc());
}

void Form::on_pushButton_24_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
     notification();

}

void Form::on_pushButton_42_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
     notification();
}

void Form::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    statistic();
}

void Form::on_pushButton_49_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
      notification();
}

void Form::on_lineEdit_9_editingFinished()
{
    QSqlQuery query;

    QDate date = QDate::currentDate();
    QString mm = QString::number(date.month());

    QString iron = ui->lineEdit_9->text();
    ui->label_18->setText(ui->lineEdit_9->text());
     query.prepare("update  statistic  set iron='"+iron+"' where month='"+mm+"'");
     query.exec();

}
void Form::update_materials()
{
    QSqlQuery query;
    QDate date = QDate::currentDate();
    QString mm = QString::number(date.month());
    query.prepare("select * from statistic where month='"+mm+"' ");
    if(query.exec())
    {
        while(query.next())
        {
            ui->label_18->setText(query.value(1).toString());
            ui->label_19->setText(query.value(2).toString());
             ui->label_20->setText(query.value(5).toString());
              ui->label_16->setText(query.value(3).toString());
               ui->label_17->setText(query.value(4).toString());
        }
    }
}

void Form::on_lineEdit_10_editingFinished()
{
    QDate date = QDate::currentDate();
    QString mm = QString::number(date.month());
     QSqlQuery query;

    QString wood = ui->lineEdit_10->text();
    ui->label_19->setText(ui->lineEdit_10->text());
    query.prepare("update  statistic  set wood='"+wood+"' where month='"+mm+"'");
    query.exec();


}

void Form::on_lineEdit_11_editingFinished()
{
    QDate date = QDate::currentDate();
    QString mm = QString::number(date.month());
     QSqlQuery query;

    QString grave = ui->lineEdit_11->text();
    ui->label_20->setText(ui->lineEdit_11->text());
    query.prepare("update  statistic  set gravel='"+grave+"' where month='"+mm+"'");
    query.exec();
}

void Form::on_lineEdit_12_editingFinished()
{
    QDate date = QDate::currentDate();
    QString mm = QString::number(date.month());
     QSqlQuery query;

    QString  sand = ui->lineEdit_12->text();
     ui->label_16->setText(ui->lineEdit_12->text());
     query.prepare("update  statistic  set sand='"+sand+"' where month='"+mm+"'");
     query.exec();
}

void Form::on_lineEdit_13_editingFinished()
{
    QDate date = QDate::currentDate();
    QString mm = QString::number(date.month());
     QSqlQuery query;

    QString rock = ui->lineEdit_13->text();
    ui->label_17->setText(ui->lineEdit_13->text());
    query.prepare("update  statistic  set rock='"+rock+"' where month='"+mm+"'");
    query.exec();
}



void Form::on_pushButton_32_clicked()
{
     ui->stackedWidget->setCurrentIndex(7);
}


void Form::on_pushButton_11_clicked()
{
    QPdfWriter pdf(QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf"));
    QPainter painter(&pdf);
    QString a,b,c,d,e,f;
    QFont font;
    font.setPixelSize(180); // 180
    painter.setFont(font);
    QSqlQuery qry;
    //std::list<QString> tt;
    qry.exec("select * from statistic");
    //int yy=400;
    int xx=100,i=1;
    int yy=600;
    bool trouvel = false;
    while(qry.next())
    {
        if(i<7)
        {yy=600;}
        if(i>=7)
        {
            yy=2700;
            if(trouvel==false)
            {
                xx=100;
                trouvel=true;
            }
        }
        //yy=600;
        a=qry.value(0).toString();
        painter.setPen(Qt::blue);
        painter.drawText(xx,yy,"Month : " +a);
        yy+=300;
        painter.setPen(Qt::black);
        b=qry.value(1).toString();
        painter.drawText(xx,yy,"Iron : " +b);
        c=qry.value(2).toString();
        yy+=300;
        painter.drawText(xx,yy,"Wood : " +c);
        d=qry.value(3).toString();
        yy+=300;
        painter.drawText(xx,yy,"Sand : " +d);
        e=qry.value(4).toString();
        yy+=300;
         painter.drawText(xx,yy,"Rock : " +e);
        f=qry.value(5).toString();
         yy+=300;
         painter.drawText(xx,yy,"Gravel : " +f);
         xx+=1700;//1700

         i++;
    }

    QPixmap pix = ui->horizontalFrame->grab();
    int h = painter.window().height()*0.4;
        int w = h * 2;
        int x = (painter.window().width() - 9500) ;
        int y = (painter.window().height() / 2);
        ui->horizontalFrame->resize(w, h);
        painter.drawPixmap(x, y, w, h, pix);
        painter.end();


    /*QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);
    ui->textBrowser->print(&printer);*/

}


void Form::on_pushButton_20_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    ui->label_21->setText(ui->calendarWidget->selectedDate().toString("dd/MM/yyyy"));
}


void Form::on_calendarWidget_selectionChanged()
{
     ui->label_21->setText(ui->calendarWidget->selectedDate().toString("dd/MM/yyyy"));
     //to test
     QString dates= ui->calendarWidget->selectedDate().toString("dd/MM/yyyy");
     cout << dates.toStdString() << endl;
     //
     QSqlQuery query;
     Model = new QStringListModel(this);
         QStringList list;
         Model->setStringList(list);
         ui->listView->setModel(Model);
     query.prepare("select * from calender where dates='"+dates+"' ");
     if(query.exec())
     {
         while(query.next())
         {
            list << query.value(1).toString();

         }
     }
     Model->setStringList(list);
     ui->listView->setModel(Model);

}


void Form::on_pushButton_19_clicked()
{
     QString dates= ui->calendarWidget->selectedDate().toString("dd/MM/yyyy");
     QString event = ui->lineEdit_14->text();
     material a;
     a.ajout_event( dates,event);
     highlight_date();

}


void Form::on_listView_doubleClicked(const QModelIndex &index)
{
    QString dates= ui->calendarWidget->selectedDate().toString("dd/MM/yyyy");
     QString event = ui->listView->model()->data(index).toString();
      material a;
     a.supprimer_event(event,dates);
     highlight_date();


}


void Form::on_pushButton_56_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
      notification();
}
void Form::notification()
{
    QDate date = QDate::currentDate();
    QString mm = QString::number(date.month());
    QString iron,rock,wood,sand,gravel;
    QSqlQuery query;
    query.prepare("select * from statistic where month='"+mm+"' ");
    if(query.exec())
    {
        while(query.next())
        {
            iron=query.value(1).toString();
            wood=query.value(2).toString();
            sand=query.value(3).toString();
            rock=query.value(4).toString();
            gravel=query.value(5).toString();
        }
    }
    if(iron.toInt() <30)
    {
        QMessageBox::critical(nullptr, QObject::tr("Warning"),
                    QObject::tr("the store  is low in iron !!\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    if(wood.toInt() <30)
    {
        QMessageBox::critical(nullptr, QObject::tr("Warning"),
                    QObject::tr("the store  is low in wood !!\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    if(sand.toInt() <30)
    {
        QMessageBox::critical(nullptr, QObject::tr("Warning"),
                    QObject::tr("the store  is low in sand !!\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    if(rock.toInt() <30)
    {
        QMessageBox::critical(nullptr, QObject::tr("Warning"),
                    QObject::tr("the store  is low in rock !!\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    if(gravel.toInt() <30)
    {
        QMessageBox::critical(nullptr, QObject::tr("Warning"),
                    QObject::tr("the store  is low in gravel !!\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void Form::highlight_date()
{
    QSqlQuery query;
    query.prepare("select * from calender  ");
    QStringList datee;
    QStringList list;
        //list = string.split(QRegularExpression("[\\s|,]"), QString::SkipEmptyParts);
    QTextCharFormat format = ui->calendarWidget->weekdayTextFormat(Qt::Wednesday);
    if(query.exec())
    {
        while(query.next())
        {
            datee << query.value(0).toString();
        }
    }

     for (int i = 0; i < datee.size(); ++i)
     {
     list = datee.at(i).split(QRegularExpression("[/]"), QString::SkipEmptyParts);
     int day=list.at(0).toInt();
     int month = list.at(1).toInt();
     int year = list.at(2).toInt();
         QDate d(year,month,day);
         cout << d.toString().toLocal8Bit().constData() << endl;
         format.setForeground(QBrush(Qt::yellow, Qt::SolidPattern));
         ui->calendarWidget->setDateTextFormat(d, format);
     }



}

void Form::on_pushButton_63_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void Form::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
////////////AMEN//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Form::on_ajouter_clicked()
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

void Form::on_tabWidget_currentChanged(int index)
{

    ui->test->setEnabled(true);
    ui->test->setModel(insemployes.afficher());
    ui->id_modif->setModel(insemployes.modifier_liste_employes());
    ui->supp_id->setModel(insemployes.modifier_liste_employes());


}

void Form::on_supprimer_clicked()
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



void Form::on_modifier_clicked()
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





void Form::on_rechercherbutton_clicked()
{
    QString rech =ui->rech->text();
    ui->test->setModel(insemployes.rechercher(rech));
}


void Form::on_pushButton_35_clicked()
{
    ui->test->setModel(insemployes.tri());
}


void Form::browse()
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





void Form::sendMail()
{
    smtp* Smtp = new smtp(ui->username->text(), ui->password->text(), ui->server->text(), ui->port->text().toInt());
      connect(Smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

      if( !files.isEmpty() )
          Smtp->sendMail(ui->username->text(), ui->rcpt->text() , ui->sub->text(),ui->message->toPlainText(), files );
      else
          Smtp->sendMail(ui->username->text(), ui->rcpt->text() , ui->sub->text(),ui->message->toPlainText());
  }


void Form::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    else
        QMessageBox::critical(nullptr, QObject::tr("non envoyé"),
                          QObject::tr("Erreur !\n"), QMessageBox::Cancel);
}




void Form::on_pushButton_33_clicked()
{
    Employes e;
    e.exporterpdf(ui->textBrowser);
}

//Arduino

void Form::update_label()
{


    QString id_e = ui->id_ard->text();
    QString id_b;
    data=A.read_from_arduino();
    QSqlQuery query;

    query.prepare("SELECT id from TERRAINS where id like '"+id_e+"' ");
    query.bindValue(":id",id_e);
       if(query.exec())
       {
           while(query.next())
           {

               id_b = query.value(0).toString();

           }


      }
       if(id_e==id_b)

     {
         if(data=="0")
         {
             QString zero="0";
             query.prepare("UPDATE TERRAINS set  gaz='"+zero+"' where id like '"+id_b+"' ");
             query.bindValue(":id",id_b);
             query.bindValue(":gaz", zero);
             query.exec();

         }
         else if(data=="1")
         {
             QString un="1";
             query.prepare("UPDATE TERRAINS set  gaz='"+un+"' where id like '"+id_b+"' ");
             query.bindValue(":id",id_b);
             query.bindValue(":gaz", un);
             query.exec();
         }

     }
       else
       {
            ui->arduino->setText("Terrain n'existe pas");
       }

/////////////////////////////////////////////////////////////////////////////////////////////////////////

    QString gaz="";
    query.prepare("SELECT gaz from TERRAINS where id like '"+id_b+"' ");
    query.bindValue(":id",id_b);
       if(query.exec())
       {
           while(query.next())
           {

               gaz = query.value(0).toString();
               qDebug()<< gaz;
           }

      }

    if(gaz=="1")
    {

    ui->arduino->setText("Attention fuite de gaz dans ce terrain !!");

    }

   if (gaz=="0")
    {
       ui->arduino->setText("Pas de fuite de gaz dans ce terrain ");
    }
}

//Arduino

void Form::on_pushButton_70_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}


void Form::on_pushButton_22_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}


void Form::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void Form::on_pushButton_47_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void Form::on_pushButton_40_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void Form::on_pushButton_61_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void Form::on_pushButton_54_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

