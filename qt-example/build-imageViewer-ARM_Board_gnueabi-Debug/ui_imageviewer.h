/********************************************************************************
** Form generated from reading UI file 'imageviewer.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEVIEWER_H
#define UI_IMAGEVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_imageViewer
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *imageViewer)
    {
        if (imageViewer->objectName().isEmpty())
            imageViewer->setObjectName(QString::fromUtf8("imageViewer"));
        imageViewer->resize(400, 300);
        menuBar = new QMenuBar(imageViewer);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        imageViewer->setMenuBar(menuBar);
        mainToolBar = new QToolBar(imageViewer);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        imageViewer->addToolBar(mainToolBar);
        centralWidget = new QWidget(imageViewer);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        imageViewer->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(imageViewer);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        imageViewer->setStatusBar(statusBar);

        retranslateUi(imageViewer);

        QMetaObject::connectSlotsByName(imageViewer);
    } // setupUi

    void retranslateUi(QMainWindow *imageViewer)
    {
        imageViewer->setWindowTitle(QApplication::translate("imageViewer", "imageViewer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class imageViewer: public Ui_imageViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEVIEWER_H
