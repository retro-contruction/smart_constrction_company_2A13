#ifndef STATISTIQUE_H
#define STATISTIQUE_H

#include <QMainWindow>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
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
};

#endif // STATISTIQUE_H
