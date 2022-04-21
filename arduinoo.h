#ifndef ARDUINOO_H
#define ARDUINOO_H

#include <QMainWindow>

namespace Ui {
class arduinoo;
}

class arduinoo : public QMainWindow
{
    Q_OBJECT

public:
    explicit arduinoo(QWidget *parent = nullptr);
    ~arduinoo();

private:
    Ui::arduinoo *ui;
};

#endif // ARDUINOO_H
