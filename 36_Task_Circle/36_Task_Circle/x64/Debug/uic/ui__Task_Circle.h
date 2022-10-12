/********************************************************************************
** Form generated from reading UI file '_Task_Circle.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI__TASK_CIRCLE_H
#define UI__TASK_CIRCLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui__Task_CircleClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *_Task_CircleClass)
    {
        if (_Task_CircleClass->objectName().isEmpty())
            _Task_CircleClass->setObjectName(QString::fromUtf8("_Task_CircleClass"));
        _Task_CircleClass->resize(600, 400);
        menuBar = new QMenuBar(_Task_CircleClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        _Task_CircleClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(_Task_CircleClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        _Task_CircleClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(_Task_CircleClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        _Task_CircleClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(_Task_CircleClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        _Task_CircleClass->setStatusBar(statusBar);

        retranslateUi(_Task_CircleClass);

        QMetaObject::connectSlotsByName(_Task_CircleClass);
    } // setupUi

    void retranslateUi(QMainWindow *_Task_CircleClass)
    {
        _Task_CircleClass->setWindowTitle(QCoreApplication::translate("_Task_CircleClass", "_Task_Circle", nullptr));
    } // retranslateUi

};

namespace Ui {
    class _Task_CircleClass: public Ui__Task_CircleClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI__TASK_CIRCLE_H
