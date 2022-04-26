#ifndef FORM_H
#define FORM_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include<QDebug>
#include "secdialog.h"
#include "material.h"
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include <QSerialPort>
#include "employes.h"
#include "arduino.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Form; }
QT_END_NAMESPACE

class Form : public QDialog
 {
    Q_OBJECT

public:
    Form(QWidget *parent = nullptr);
    ~Form();

private slots:
    void mailSent(QString);
    void sendMail();
    void browse();
    void update_label();


    /*void on_send_clicked();

    void on_pushButton_clicked();*/

    void on_ajouter_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_supprimer_clicked();

    void on_modifier_clicked();

    void on_rechercherbutton_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_33_clicked();
    ////////////////////////////////////

    std::array<int,20> get_stat(QString);

    void on_pushButton_5_clicked();


    void on_tableView_activated(const QModelIndex &index);

    void on_tableView_clicked(const QModelIndex &index);


    void on_pushButton_6_clicked();

    void on_lineEdit_8_editingFinished();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_24_clicked();


    void on_pushButton_42_clicked();

    void on_pushButton_9_clicked();

    void statistic();


    void on_pushButton_49_clicked();

   void on_lineEdit_9_editingFinished();

    void on_lineEdit_10_editingFinished();

    void on_lineEdit_11_editingFinished();

    void on_lineEdit_12_editingFinished();

    void on_lineEdit_13_editingFinished();

    void update_materials();


    void on_pushButton_32_clicked();

    void on_pushButton_11_clicked();


    void on_pushButton_20_clicked();

    void on_calendarWidget_selectionChanged();

    void on_pushButton_19_clicked();

    void on_listView_doubleClicked(const QModelIndex &index);

    void on_pushButton_56_clicked();
    void notification();
    void highlight_date();
    void readSerial();

    void on_pushButton_63_clicked();

    void on_pushButton_10_clicked();
    QString showTime();
    void update_time(QString);
    void WRITE();

    void on_pushButton_70_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_47_clicked();

    void on_pushButton_40_clicked();

    void on_pushButton_61_clicked();

    void on_pushButton_54_clicked();

    void on_pushButton_27_clicked();


    void on_pushButton_118_clicked();

    void on_pushButton_120_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_73_clicked();

    void on_lineEdit_36_textChanged(const QString &arg1);

    void on_pushButton_150_clicked();

    void on_pushButton_149_clicked();

    void on_pushButton_155_clicked();

    void on_pushButton_156_clicked();

    void on_pushButton_157_clicked();

    void on_pushButton_158_clicked();

private:
    Ui::Form *ui;
    SecDialog *Sec;
    QStringListModel *Model;
    QString val;
    QSerialPort *ard;
    QString data;
    short int second =0;
    short int minutes = 0;
    short int hours = 0;
    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_uno_producy_id=67;
    bool test = false;
    bool work=false;
    QSerialPort * serial;
    QString arduino_port_name;
    bool arduino_is_available;
    bool write=false;
    Employes insemployes;
    QStringList files;
    arduino A;





    //material Etmp;

};

#endif // FORM_H
