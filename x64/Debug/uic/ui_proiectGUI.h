/********************************************************************************
** Form generated from reading UI file 'proiectGUI.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROIECTGUI_H
#define UI_PROIECTGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_proiectGUIClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *proiectGUIClass)
    {
        if (proiectGUIClass->objectName().isEmpty())
            proiectGUIClass->setObjectName(QString::fromUtf8("proiectGUIClass"));
        proiectGUIClass->resize(600, 400);
        menuBar = new QMenuBar(proiectGUIClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        proiectGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(proiectGUIClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        proiectGUIClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(proiectGUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        proiectGUIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(proiectGUIClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        proiectGUIClass->setStatusBar(statusBar);

        retranslateUi(proiectGUIClass);

        QMetaObject::connectSlotsByName(proiectGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *proiectGUIClass)
    {
        proiectGUIClass->setWindowTitle(QCoreApplication::translate("proiectGUIClass", "proiectGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class proiectGUIClass: public Ui_proiectGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROIECTGUI_H
