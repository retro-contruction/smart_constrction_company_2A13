#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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


QT_BEGIN_NAMESPACE
namespace Ui { class Form; }
QT_END_NAMESPACE

class Form : public QMainWindow
 {
    Q_OBJECT

public:
    Form(QWidget *parent = nullptr);
    ~Form();

private slots:


    void on_pushButton_3_clicked();

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

private:
    Ui::Form *ui;
    SecDialog *Sec;
    QStringListModel *Model;
    QString val;

    //material Etmp;

};

#endif // MAINWINDOW_H
