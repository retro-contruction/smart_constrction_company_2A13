#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QSqlQueryModel>
namespace Ui {
class client;
}

class client : public QMainWindow
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);
    ~client();
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
private slots:
 void on_AjouterClient_clicked();

 void on_id_Supprimerhous_clicked();

 void on_pushButtonModifierhous_clicked();
private:
 int id,numtel;
 QString nom,prenom,adresse;
    Ui::client *ui;
};

#endif // CLIENT_H
