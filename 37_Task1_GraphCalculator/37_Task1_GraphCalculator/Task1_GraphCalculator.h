#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/qlabel.h>
#include "ui_Task1_GraphCalculator.h"

class Task1_GraphCalculator : public QMainWindow
{
    Q_OBJECT

public:
    QLineEdit* lineEdit1 = nullptr;
    QLineEdit* lineEdit2 = nullptr;
    QLabel* displayOut = nullptr;
    Task1_GraphCalculator(QWidget* parent = nullptr);
    ~Task1_GraphCalculator();

private:
    Ui::Task1_GraphCalculatorClass ui;

public slots:
    void addition() {
        float numb1, numb2, solution;
        bool checkStr = true;
        QString str1 = lineEdit1->text();
        QString str2 = lineEdit2->text();
        numb1 = str1.toFloat();
        numb2 = str2.toFloat();
        if (lineEdit1->displayText().isEmpty() || lineEdit2->displayText().isEmpty())
            displayOut->setText("Error. Value is empty.");
        else
        {
            solution = numb1 + numb2;
            QString strSolution = QString::number(solution);
            for (int i = 0; i < str1.size(); i++)
            {
                if ((str1[i] < '0' || str1[i] > '9') && str1[0] != '-' && str1[i] != '.')
                    checkStr = false;
            }
            for (int i = 0; i < str2.size(); i++)
            {
                if ((str2[i] < '0' || str2[i] > '9') && str2[0] != '-' && str2[i] != '.')
                    checkStr = false;
            }
            if(checkStr)
                displayOut->setText(str1 + "+" + str2 + "=" + strSolution);
            else
                displayOut->setText("Error. Invalid type.");
        }
    };
    void subtraction() {
        float numb1, numb2, solution;
        bool checkStr = true;
        QString str1 = lineEdit1->text();
        QString str2 = lineEdit2->text();
        numb1 = str1.toFloat();
        numb2 = str2.toFloat();
        if (lineEdit1->displayText().isEmpty() || lineEdit2->displayText().isEmpty())
            displayOut->setText("Error. Value is empty.");
        else
        {
            solution = numb1 - numb2;
            QString strSolution = QString::number(solution);
            for (int i = 0; i < str1.size(); i++)
            {
                if ((str1[i] < '0' || str1[i] > '9') && str1[0] != '-' && str1[i] != '.')
                    checkStr = false;
            }
            for (int i = 0; i < str2.size(); i++)
            {
                if ((str2[i] < '0' || str2[i] > '9') && str2[0] != '-' && str2[i] != '.')
                    checkStr = false;
            }
            if (checkStr)
                displayOut->setText(str1 + "-" + str2 + "=" + strSolution);
            else
                displayOut->setText("Error. Invalid type.");
        }
    };
    void multiplication() {
        float numb1, numb2, solution;
        bool checkStr = true;
        QString str1 = lineEdit1->text();
        QString str2 = lineEdit2->text();
        numb1 = str1.toFloat();
        numb2 = str2.toFloat();
        if (lineEdit1->displayText().isEmpty() || lineEdit2->displayText().isEmpty())
            displayOut->setText("Error. Value is empty.");
        else
        {
            solution = numb1 * numb2;
            QString strSolution = QString::number(solution);
            for (int i = 0; i < str1.size(); i++)
            {
                if ((str1[i] < '0' || str1[i] > '9') && str1[0] != '-' && str1[i] != '.')
                    checkStr = false;
            }
            for (int i = 0; i < str2.size(); i++)
            {
                if ((str2[i] < '0' || str2[i] > '9') && str2[0] != '-' && str2[i] != '.')
                    checkStr = false;
            }
            if (checkStr)
                displayOut->setText(str1 + "*" + str2 + "=" + strSolution);
            else
                displayOut->setText("Error. Invalid type.");
        }
    };
    void division() {
        float numb1, numb2, solution;
        bool checkStr = true;
        QString str1 = lineEdit1->text();
        QString str2 = lineEdit2->text();
        numb1 = str1.toFloat();
        numb2 = str2.toFloat();
        if (lineEdit1->displayText().isEmpty() || lineEdit2->displayText().isEmpty() || numb2 == 0)
            displayOut->setText("Error. Value is empty.");
        else
        {
            solution = numb1 / numb2;
            QString strSolution = QString::number(solution);
            for (int i = 0; i < str1.size(); i++)
            {
                if ((str1[i] < '0' || str1[i] > '9') && str1[0] != '-' && str1[i] != '.')
                    checkStr = false;
            }
            for (int i = 0; i < str2.size(); i++)
            {
                if ((str2[i] < '0' || str2[i] > '9') && str2[0] != '-' && str2[i] != '.')
                    checkStr = false;
            }
            if (checkStr)
                displayOut->setText(str1 + "/" + str2 + "=" + strSolution);
            else
                displayOut->setText("Error. Invalid type.");
        }
    };
    void clear()
    {
        lineEdit1->clear();
        lineEdit2->clear();
        displayOut->clear();
    }
};
