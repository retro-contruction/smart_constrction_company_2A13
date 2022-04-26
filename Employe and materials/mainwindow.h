#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
<<<<<<< HEAD:old/mainwindow.h
    void on_pushButton_3_clicked();

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_pushButton_8_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_9_clicked();

    void on_tableView_2_activated(const QModelIndex &index);
=======
    void on_pushButton_clicked();
    /*void mailSent1(QString);
     void sendMail1();*/
>>>>>>> main:Employe and materials/mainwindow.h

    void on_comboBox_activated(const QString &arg1);

<<<<<<< HEAD:old/mainwindow.h
    void on_pushButton_11_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_10_clicked();

=======
>>>>>>> main:Employe and materials/mainwindow.h
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
