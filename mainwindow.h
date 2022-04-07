#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "terrain.h"
#include "statistique.h"
#include "map.h"
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

    void on_pushButton_2_clicked();

    void on_trier_clicked();

    void on_buttStatistique_clicked();

    void on_trier_2_clicked();

    void on_pushButton_map_clicked();

    void on_pushButton_pdf_clicked();

private:
    Ui::MainWindow *ui;
    statistique *stat;
    map *maps;
    Terrain  T;
};
#endif // MAINWINDOW_H
