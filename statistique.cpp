#include "statistique.h"
#include "ui_statistique.h"

statistique::statistique(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::statistique)
{
    ui->setupUi(this);
    QPieSeries *series = new QPieSeries;
    series->append("Terrain etat 0",2);
    series->append("Terrains etat 1",1);

    QChart *chart = new QChart();

    chart->addSeries(series);
    chart->setTitle("Statistique de terrain selon l'Etat");

    QChartView *chartview = new QChartView(chart);
    chartview->setParent(ui->horizontalFrame);
}

statistique::~statistique()
{
    delete ui;
}
