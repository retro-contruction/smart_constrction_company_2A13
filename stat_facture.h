#ifndef STAT_FACTURE_H
#define STAT_FACTURE_H
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

#include <iostream>
#include <vector>
using namespace std;

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class stat_facture;
}

class stat_facture : public QDialog
{
    Q_OBJECT

public:
    explicit stat_facture(QWidget *parent = nullptr);
    ~stat_facture();

    QChartView *chartView ;
    void choix_pie();

private:
    Ui::stat_facture *ui;
};

#endif // STAT_FACTURE_H
