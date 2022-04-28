/********************************************************************************
** Form generated from reading UI file 'secdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECDIALOG_H
#define UI_SECDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SecDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *SecDialog)
    {
        if (SecDialog->objectName().isEmpty())
            SecDialog->setObjectName(QStringLiteral("SecDialog"));
        SecDialog->resize(385, 379);
        SecDialog->setStyleSheet(QLatin1String("#SecDialog{\n"
"background-color : #191919;\n"
"}\n"
"*{\n"
"color : #fff7f2;\n"
"}\n"
"QLineEdit{\n"
"color : #191919;\n"
"}"));
        verticalLayout = new QVBoxLayout(SecDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(SecDialog);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        frame_2 = new QFrame(widget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(frame_2);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        verticalLayout_2->addWidget(label_5);


        horizontalLayout->addWidget(frame_2);

        frame = new QFrame(widget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setSpacing(9);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setMinimumSize(QSize(0, 190));
        frame_3->setMaximumSize(QSize(16777215, 190));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_3);
        verticalLayout_4->setSpacing(30);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, 12, -1, 0);
        lineEdit = new QLineEdit(frame_3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout_4->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(frame_3);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        verticalLayout_4->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(frame_3);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        verticalLayout_4->addWidget(lineEdit_3);

        lineEdit_4 = new QLineEdit(frame_3);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        verticalLayout_4->addWidget(lineEdit_4);


        verticalLayout_3->addWidget(frame_3);

        frame_4 = new QFrame(frame);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setMinimumSize(QSize(0, 40));
        frame_4->setMaximumSize(QSize(16777215, 40));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_4);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        checkBox = new QCheckBox(frame_4);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout_2->addWidget(checkBox);

        checkBox_2 = new QCheckBox(frame_4);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        horizontalLayout_2->addWidget(checkBox_2);


        verticalLayout_3->addWidget(frame_4);


        horizontalLayout->addWidget(frame, 0, Qt::AlignHCenter);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(SecDialog);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(0, 60));
        widget_2->setMaximumSize(QSize(16777215, 60));
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);


        verticalLayout->addWidget(widget_2);


        retranslateUi(SecDialog);

        QMetaObject::connectSlotsByName(SecDialog);
    } // setupUi

    void retranslateUi(QDialog *SecDialog)
    {
        SecDialog->setWindowTitle(QApplication::translate("SecDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("SecDialog", "Name", Q_NULLPTR));
        label_2->setText(QApplication::translate("SecDialog", "Reference", Q_NULLPTR));
        label_3->setText(QApplication::translate("SecDialog", "Date_dachat", Q_NULLPTR));
        label_4->setText(QApplication::translate("SecDialog", "quantity", Q_NULLPTR));
        label_5->setText(QApplication::translate("SecDialog", "status", Q_NULLPTR));
        checkBox->setText(QApplication::translate("SecDialog", "Working", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("SecDialog", "Not working", Q_NULLPTR));
        pushButton->setText(QApplication::translate("SecDialog", "Save", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("SecDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SecDialog: public Ui_SecDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECDIALOG_H
