#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employes.h"
#include <QMainWindow>
#include <QDialog>
#include <QFileDialog>
#include "smtp.h"




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_showButton_customContextMenuRequested(const QPoint &pos);

    void on_pushButton_clicked(bool checked);

    void on_pushButton_2_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_test_activated(const QModelIndex &index);

    void on_pushButton_5_clicked();

    void on_lineEdit_5_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_6_clicked();

private slots:

     void mailSent(QString);
     void sendMail();
     void browse();



     void on_send_clicked();

private:
    Ui::MainWindow *ui;
    Employes insemployes;
    QStringList files;
};
#endif // MAINWINDOW_H
