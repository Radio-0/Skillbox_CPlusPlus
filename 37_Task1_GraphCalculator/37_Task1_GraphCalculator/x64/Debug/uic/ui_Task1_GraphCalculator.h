/********************************************************************************
** Form generated from reading UI file 'Task1_GraphCalculator.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK1_GRAPHCALCULATOR_H
#define UI_TASK1_GRAPHCALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Task1_GraphCalculatorClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit1;
    QLineEdit *lineEdit2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *Clear;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Task1_GraphCalculatorClass)
    {
        if (Task1_GraphCalculatorClass->objectName().isEmpty())
            Task1_GraphCalculatorClass->setObjectName(QString::fromUtf8("Task1_GraphCalculatorClass"));
        Task1_GraphCalculatorClass->resize(517, 372);
        centralWidget = new QWidget(Task1_GraphCalculatorClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit1 = new QLineEdit(centralWidget);
        lineEdit1->setObjectName(QString::fromUtf8("lineEdit1"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit1->sizePolicy().hasHeightForWidth());
        lineEdit1->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        lineEdit1->setFont(font);
        lineEdit1->setLayoutDirection(Qt::LeftToRight);
        lineEdit1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lineEdit1);

        lineEdit2 = new QLineEdit(centralWidget);
        lineEdit2->setObjectName(QString::fromUtf8("lineEdit2"));
        sizePolicy.setHeightForWidth(lineEdit2->sizePolicy().hasHeightForWidth());
        lineEdit2->setSizePolicy(sizePolicy);
        lineEdit2->setFont(font);
        lineEdit2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lineEdit2);


        verticalLayout->addLayout(horizontalLayout_2);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(14);
        label->setFont(font1);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(9);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        pushButton_2->setMaximumSize(QSize(100, 100));
        pushButton_2->setFont(font);

        horizontalLayout->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);
        pushButton_4->setMaximumSize(QSize(100, 100));
        pushButton_4->setFont(font);

        horizontalLayout->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);
        pushButton_3->setMaximumSize(QSize(100, 100));
        pushButton_3->setFont(font);

        horizontalLayout->addWidget(pushButton_3);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMaximumSize(QSize(100, 100));
        pushButton->setFont(font);

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        Clear = new QPushButton(centralWidget);
        Clear->setObjectName(QString::fromUtf8("Clear"));
        sizePolicy1.setHeightForWidth(Clear->sizePolicy().hasHeightForWidth());
        Clear->setSizePolicy(sizePolicy1);
        Clear->setFont(font1);
        Clear->setStyleSheet(QString::fromUtf8("backgroud-color:rgb(255, 0, 4);\n"
"color:rgb(0, 0, 0);"));

        verticalLayout->addWidget(Clear);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        Task1_GraphCalculatorClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Task1_GraphCalculatorClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 517, 26));
        Task1_GraphCalculatorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Task1_GraphCalculatorClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Task1_GraphCalculatorClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Task1_GraphCalculatorClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Task1_GraphCalculatorClass->setStatusBar(statusBar);

        retranslateUi(Task1_GraphCalculatorClass);
        QObject::connect(pushButton_2, SIGNAL(clicked()), Task1_GraphCalculatorClass, SLOT(addition()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), Task1_GraphCalculatorClass, SLOT(subtraction()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), Task1_GraphCalculatorClass, SLOT(multiplication()));
        QObject::connect(pushButton, SIGNAL(clicked()), Task1_GraphCalculatorClass, SLOT(division()));
        QObject::connect(lineEdit1, SIGNAL(textChanged(QString)), label, SLOT(setText(QString)));
        QObject::connect(lineEdit2, SIGNAL(textEdited(QString)), label, SLOT(setText(QString)));
        QObject::connect(Clear, SIGNAL(clicked()), Task1_GraphCalculatorClass, SLOT(clear()));

        QMetaObject::connectSlotsByName(Task1_GraphCalculatorClass);
    } // setupUi

    void retranslateUi(QMainWindow *Task1_GraphCalculatorClass)
    {
        Task1_GraphCalculatorClass->setWindowTitle(QCoreApplication::translate("Task1_GraphCalculatorClass", "Task1_GraphCalculator", nullptr));
        lineEdit1->setPlaceholderText(QCoreApplication::translate("Task1_GraphCalculatorClass", "Number 1", nullptr));
        lineEdit2->setPlaceholderText(QCoreApplication::translate("Task1_GraphCalculatorClass", "Number 2", nullptr));
        label->setText(QCoreApplication::translate("Task1_GraphCalculatorClass", "Solution", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Task1_GraphCalculatorClass", "+", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Task1_GraphCalculatorClass", "-", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Task1_GraphCalculatorClass", "*", nullptr));
        pushButton->setText(QCoreApplication::translate("Task1_GraphCalculatorClass", "/", nullptr));
        Clear->setText(QCoreApplication::translate("Task1_GraphCalculatorClass", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Task1_GraphCalculatorClass: public Ui_Task1_GraphCalculatorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK1_GRAPHCALCULATOR_H
