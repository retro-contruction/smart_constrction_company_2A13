#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employes.h"
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
    void on_pushButton_clicked();

    void on_showButton_customContextMenuRequested(const QPoint &pos);

    void on_pushButton_clicked(bool checked);

    void on_pushButton_2_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    Employes insemployes;
};
#endif // MAINWINDOW_H
