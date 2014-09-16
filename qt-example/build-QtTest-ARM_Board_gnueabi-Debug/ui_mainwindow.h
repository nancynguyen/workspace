/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *testButton;
    QTextEdit *testEdit;
    QGraphicsView *graphicsView;
    QToolButton *actionOpenImage;
    QPushButton *ledOnButton;
    QPushButton *ledOffButton;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 480);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        testButton = new QPushButton(centralWidget);
        testButton->setObjectName(QString::fromUtf8("testButton"));
        testButton->setGeometry(QRect(580, 80, 85, 27));
        testEdit = new QTextEdit(centralWidget);
        testEdit->setObjectName(QString::fromUtf8("testEdit"));
        testEdit->setGeometry(QRect(490, 30, 256, 31));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 441, 371));
        actionOpenImage = new QToolButton(centralWidget);
        actionOpenImage->setObjectName(QString::fromUtf8("actionOpenImage"));
        actionOpenImage->setGeometry(QRect(170, 390, 111, 25));
        ledOnButton = new QPushButton(centralWidget);
        ledOnButton->setObjectName(QString::fromUtf8("ledOnButton"));
        ledOnButton->setGeometry(QRect(490, 130, 99, 27));
        ledOffButton = new QPushButton(centralWidget);
        ledOffButton->setObjectName(QString::fromUtf8("ledOffButton"));
        ledOffButton->setGeometry(QRect(650, 130, 99, 27));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        testButton->setText(QApplication::translate("MainWindow", "Hello", 0, QApplication::UnicodeUTF8));
        actionOpenImage->setText(QApplication::translate("MainWindow", "Open Image", 0, QApplication::UnicodeUTF8));
        ledOnButton->setText(QApplication::translate("MainWindow", "ON", 0, QApplication::UnicodeUTF8));
        ledOffButton->setText(QApplication::translate("MainWindow", "OFF", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
