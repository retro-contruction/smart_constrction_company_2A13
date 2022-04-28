#ifndef HOUSSEM_H
#define HOUSSEM_H

#include <QMainWindow>

namespace Ui {
class houssem;
}

class houssem : public QMainWindow
{
    Q_OBJECT

public:
    explicit houssem(QWidget *parent = nullptr);
    ~houssem();
    client();
    client(int,QString,QString,int,QString);
    int getId();
    QString getNom();
    QString getPrenom();
    int getNumtel();
    QString getAdresse();
    void setId(int);

    bool ajouterClient();
 QSqlQueryModel* afficherClient();
 bool supprimerClient(int);
 bool modifierClient(int,QString,QString,int,QString);

private:
    Ui::houssem *ui;
};

#endif // HOUSSEM_H
