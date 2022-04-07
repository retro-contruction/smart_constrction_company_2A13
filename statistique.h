#ifndef STATISTIQUE_H
#define STATISTIQUE_H

#include <QMainWindow>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include "terrain.h"
namespace Ui {
class statistique;
}

class statistique : public QMainWindow
{
    Q_OBJECT

public:
    explicit statistique(QWidget *parent = nullptr);
    ~statistique();

private:
    Ui::statistique *ui;
    Terrain t;
    int nb0 ,nb1;
};

#endif // STATISTIQUE_H
