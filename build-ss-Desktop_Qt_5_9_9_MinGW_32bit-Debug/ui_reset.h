/********************************************************************************
** Form generated from reading UI file 'reset.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESET_H
#define UI_RESET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Reset
{
public:
    QLineEdit *randcode;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QLineEdit *nvmdp;

    void setupUi(QDialog *Reset)
    {
        if (Reset->objectName().isEmpty())
            Reset->setObjectName(QStringLiteral("Reset"));
        Reset->resize(810, 445);
        randcode = new QLineEdit(Reset);
        randcode->setObjectName(QStringLiteral("randcode"));
        randcode->setGeometry(QRect(460, 100, 231, 41));
        label = new QLabel(Reset);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 100, 421, 31));
        label->setStyleSheet(QStringLiteral("font: 75 12pt \"MS Shell Dlg 2\";"));
        pushButton = new QPushButton(Reset);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(330, 310, 151, 41));
        label_2 = new QLabel(Reset);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 190, 361, 51));
        label_2->setStyleSheet(QStringLiteral("font: 75 12pt \"MS Shell Dlg 2\";"));
        nvmdp = new QLineEdit(Reset);
        nvmdp->setObjectName(QStringLiteral("nvmdp"));
        nvmdp->setGeometry(QRect(460, 190, 231, 41));

        retranslateUi(Reset);

        QMetaObject::connectSlotsByName(Reset);
    } // setupUi

    void retranslateUi(QDialog *Reset)
    {
        Reset->setWindowTitle(QApplication::translate("Reset", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Reset", "Veuillez Saisir Le Code De R\303\251installation Envoy\303\251 Par Mail : ", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Reset", "Soumettre", Q_NULLPTR));
        label_2->setText(QApplication::translate("Reset", "Veuillez Saisir Votre Nouveau Mot de Passe :", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Reset: public Ui_Reset {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESET_H
