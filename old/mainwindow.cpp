#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "projet2th.h"
#include "employe.h"
#include "ajouter.h"
#include "task.h"
#include <QPrinter>
#include <QPainter>
#include <QMessageBox>
#include <QSqlError>
#include <QDir>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    projet2t p;
    employe e;
    task t;
    ui->setupUi(this);
    ui->tableView->setModel(p.afficher());
    ui->tableView_2->setModel(e.afficher());
    ui->tableView_3->setModel(t.afficher());
    ui->tableView_4->setModel(t.afficher3());
    ui->comboBox->setModel(e.afficher());
    ui->comboBox_2->setModel(p.afficher());
    ui->comboBox_3->setModel(t.afficher2());
    ui->comboBox_4->setModel(e.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{
projet2t p;
ui->tableView->setModel(p.afficher());
}

void MainWindow::on_lineEdit_3_textChanged(const QString &arg1)
{
    projet2t p;
    ui->tableView->setModel(p.recherche(arg1));
}

void MainWindow::on_pushButton_8_clicked()
{
projet2t p;
ui->tableView->setModel(p.trie());
}
void MainWindow::on_pushButton_6_clicked()
{
    projet2t p;
    p.exporterpdf(1);
}

void MainWindow::on_pushButton_9_clicked()
{
    employe el;
    QString p= ui->comboBox_2->currentText();
    QString e= ui->comboBox->currentText();
    QSqlQuery qry;
    el.update(p,e);
    ui->tableView_2->setModel(el.afficher());
    ui->comboBox_4->setModel(el.afficher());
}

void MainWindow::on_pushButton_7_clicked()
{
employe e;
ui->tableView_2->setModel(e.afficher());
}

void MainWindow::on_pushButton_11_clicked()
{
    task t2;
    QString tid= ui->lineEdit_4->text();
    QString t= ui->textEdit->toPlainText();
    t2.insert(tid,t);
    ui->tableView_4->setModel(t2.afficher3());
}
void MainWindow::on_pushButton_10_clicked()
{
    task tl;
    QString t= ui->comboBox_3->currentText();
    QString e= ui->comboBox_4->currentText();
    tl.update(t,e);
    ui->tableView_3->setModel(tl.afficher());

}
