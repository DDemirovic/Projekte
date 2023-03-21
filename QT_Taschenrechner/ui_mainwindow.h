/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_addition;
    QPushButton *pushButton_subtraktion;
    QPushButton *pushButton_multiplikation;
    QPushButton *pushButton_dividieren;
    QPushButton *pushButton_schliessen;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_0;
    QPushButton *pushButton_ergebnis;
    QLineEdit *lineEdit_anzeige;
    QPushButton *pushButton_vorzeichen;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_punkt;
    QPushButton *pushButton_quadrieren;
    QPushButton *pushButton_cos;
    QPushButton *pushButton_wurzel;
    QPushButton *pushButton_tan;
    QPushButton *pushButton_sin;
    QPushButton *pushButton_e;
    QPushButton *pushButton_log;
    QPushButton *pushButton_ln;
    QPushButton *pushButton_pi;
    QPushButton *pushButton_eWert;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(650, 470);
        MainWindow->setMinimumSize(QSize(650, 470));
        MainWindow->setMaximumSize(QSize(1500, 800));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton_addition = new QPushButton(centralWidget);
        pushButton_addition->setObjectName(QString::fromUtf8("pushButton_addition"));
        pushButton_addition->setGeometry(QRect(440, 50, 71, 31));
        pushButton_subtraktion = new QPushButton(centralWidget);
        pushButton_subtraktion->setObjectName(QString::fromUtf8("pushButton_subtraktion"));
        pushButton_subtraktion->setGeometry(QRect(520, 50, 71, 31));
        pushButton_multiplikation = new QPushButton(centralWidget);
        pushButton_multiplikation->setObjectName(QString::fromUtf8("pushButton_multiplikation"));
        pushButton_multiplikation->setGeometry(QRect(440, 90, 71, 31));
        pushButton_dividieren = new QPushButton(centralWidget);
        pushButton_dividieren->setObjectName(QString::fromUtf8("pushButton_dividieren"));
        pushButton_dividieren->setGeometry(QRect(520, 90, 71, 31));
        pushButton_schliessen = new QPushButton(centralWidget);
        pushButton_schliessen->setObjectName(QString::fromUtf8("pushButton_schliessen"));
        pushButton_schliessen->setGeometry(QRect(110, 330, 151, 61));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(30, 110, 89, 25));
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(140, 110, 89, 25));
        pushButton_9 = new QPushButton(centralWidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(250, 110, 89, 25));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(30, 150, 89, 25));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(140, 150, 89, 25));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(250, 150, 89, 25));
        pushButton_1 = new QPushButton(centralWidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(30, 190, 89, 25));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(140, 190, 89, 25));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(250, 190, 89, 25));
        pushButton_0 = new QPushButton(centralWidget);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setGeometry(QRect(140, 230, 89, 25));
        pushButton_ergebnis = new QPushButton(centralWidget);
        pushButton_ergebnis->setObjectName(QString::fromUtf8("pushButton_ergebnis"));
        pushButton_ergebnis->setGeometry(QRect(440, 300, 151, 51));
        lineEdit_anzeige = new QLineEdit(centralWidget);
        lineEdit_anzeige->setObjectName(QString::fromUtf8("lineEdit_anzeige"));
        lineEdit_anzeige->setGeometry(QRect(30, 30, 311, 31));
        pushButton_vorzeichen = new QPushButton(centralWidget);
        pushButton_vorzeichen->setObjectName(QString::fromUtf8("pushButton_vorzeichen"));
        pushButton_vorzeichen->setGeometry(QRect(30, 230, 89, 25));
        pushButton_clear = new QPushButton(centralWidget);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        pushButton_clear->setGeometry(QRect(440, 10, 151, 25));
        pushButton_punkt = new QPushButton(centralWidget);
        pushButton_punkt->setObjectName(QString::fromUtf8("pushButton_punkt"));
        pushButton_punkt->setGeometry(QRect(250, 230, 89, 25));
        pushButton_quadrieren = new QPushButton(centralWidget);
        pushButton_quadrieren->setObjectName(QString::fromUtf8("pushButton_quadrieren"));
        pushButton_quadrieren->setGeometry(QRect(440, 130, 71, 31));
        pushButton_cos = new QPushButton(centralWidget);
        pushButton_cos->setObjectName(QString::fromUtf8("pushButton_cos"));
        pushButton_cos->setGeometry(QRect(440, 170, 71, 31));
        pushButton_wurzel = new QPushButton(centralWidget);
        pushButton_wurzel->setObjectName(QString::fromUtf8("pushButton_wurzel"));
        pushButton_wurzel->setGeometry(QRect(520, 130, 71, 31));
        pushButton_tan = new QPushButton(centralWidget);
        pushButton_tan->setObjectName(QString::fromUtf8("pushButton_tan"));
        pushButton_tan->setGeometry(QRect(440, 210, 71, 31));
        pushButton_sin = new QPushButton(centralWidget);
        pushButton_sin->setObjectName(QString::fromUtf8("pushButton_sin"));
        pushButton_sin->setGeometry(QRect(520, 170, 71, 31));
        pushButton_e = new QPushButton(centralWidget);
        pushButton_e->setObjectName(QString::fromUtf8("pushButton_e"));
        pushButton_e->setGeometry(QRect(520, 210, 71, 31));
        pushButton_log = new QPushButton(centralWidget);
        pushButton_log->setObjectName(QString::fromUtf8("pushButton_log"));
        pushButton_log->setGeometry(QRect(440, 250, 71, 31));
        pushButton_ln = new QPushButton(centralWidget);
        pushButton_ln->setObjectName(QString::fromUtf8("pushButton_ln"));
        pushButton_ln->setGeometry(QRect(520, 250, 71, 31));
        pushButton_pi = new QPushButton(centralWidget);
        pushButton_pi->setObjectName(QString::fromUtf8("pushButton_pi"));
        pushButton_pi->setGeometry(QRect(250, 270, 89, 25));
        pushButton_eWert = new QPushButton(centralWidget);
        pushButton_eWert->setObjectName(QString::fromUtf8("pushButton_eWert"));
        pushButton_eWert->setGeometry(QRect(30, 270, 89, 25));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 650, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_addition->setText(QApplication::translate("MainWindow", "+", nullptr));
        pushButton_subtraktion->setText(QApplication::translate("MainWindow", "-", nullptr));
        pushButton_multiplikation->setText(QApplication::translate("MainWindow", "x", nullptr));
        pushButton_dividieren->setText(QApplication::translate("MainWindow", "/", nullptr));
        pushButton_schliessen->setText(QApplication::translate("MainWindow", "Schlie\303\237en", nullptr));
        pushButton_7->setText(QApplication::translate("MainWindow", "7", nullptr));
        pushButton_8->setText(QApplication::translate("MainWindow", "8", nullptr));
        pushButton_9->setText(QApplication::translate("MainWindow", "9", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "4", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "5", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "6", nullptr));
        pushButton_1->setText(QApplication::translate("MainWindow", "1", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "2", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "3", nullptr));
        pushButton_0->setText(QApplication::translate("MainWindow", "0", nullptr));
        pushButton_ergebnis->setText(QApplication::translate("MainWindow", "=", nullptr));
        pushButton_vorzeichen->setText(QApplication::translate("MainWindow", "( - )", nullptr));
        pushButton_clear->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        pushButton_punkt->setText(QApplication::translate("MainWindow", ".", nullptr));
        pushButton_quadrieren->setText(QApplication::translate("MainWindow", "x\302\262", nullptr));
        pushButton_cos->setText(QApplication::translate("MainWindow", "cos(x)", nullptr));
        pushButton_wurzel->setText(QApplication::translate("MainWindow", "sqrt(x)", nullptr));
        pushButton_tan->setText(QApplication::translate("MainWindow", "tan(x)", nullptr));
        pushButton_sin->setText(QApplication::translate("MainWindow", "sin(x)", nullptr));
        pushButton_e->setText(QApplication::translate("MainWindow", "e^x", nullptr));
        pushButton_log->setText(QApplication::translate("MainWindow", "log(x)", nullptr));
        pushButton_ln->setText(QApplication::translate("MainWindow", "ln(x)", nullptr));
        pushButton_pi->setText(QApplication::translate("MainWindow", "pi", nullptr));
        pushButton_eWert->setText(QApplication::translate("MainWindow", "e", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
