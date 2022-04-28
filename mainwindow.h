#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "facture.h"


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

    void on_pushButton_ajouter_a_clicked();

    void on_pushButton_modifier_a_clicked();

    void on_pushButton_supprimer_a_clicked();

    void on_pushButton_rechercher_a_clicked();

    void on_pushButton_tri_a_clicked();

    void on_pushButton_excel_a_clicked();

    void on_pushButton_pdf_a_clicked();

    void on_pushButton_afficher_a_clicked();

    void on_push_afficher_archive_a_clicked();

    void on_push_archiver_a_clicked();

    void on_push_Desar_a_clicked();

private:
    Ui::MainWindow *ui;
    Facture f,Etmp;
};
#endif // MAINWINDOW_H
