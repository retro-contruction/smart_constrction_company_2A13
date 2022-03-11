#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "terrain.h"
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


    void on_AjouterTerrain_clicked();

    void on_id_Supprimer_clicked();

    void on_pushButtonModifier_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Terrain  T;
};
#endif // MAINWINDOW_H
