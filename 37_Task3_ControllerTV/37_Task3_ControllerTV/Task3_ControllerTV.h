#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Task3_ControllerTV.h"
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qlabel.h>

class Task3_ControllerTV : public QMainWindow
{
    Q_OBJECT

public:
    QLabel* canalLab = nullptr;
    QLabel* volLab = nullptr;
    Task3_ControllerTV(QWidget *parent = nullptr);
    ~Task3_ControllerTV();

private:
    Ui::Task3_ControllerTVClass ui;
public slots:
    void numb1() 
    {
        QString str = canalLab->text();
        if (str.length() < 3)
            canalLab->setText(str + "1");
        else
            canalLab->setText("1");
    }
    void numb2()
    {
        QString str = canalLab->text();
        if (str.length() < 3)
            canalLab->setText(str + "2");
        else
            canalLab->setText("2");
    }
    void numb3()
    {
        QString str = canalLab->text();
        if (str.length() < 3)
            canalLab->setText(str + "3");
        else
            canalLab->setText("3");
    }
    void numb4()
    {
        QString str = canalLab->text();
        if (str.length() < 3)
            canalLab->setText(str + "4");
        else
            canalLab->setText("4");
    }
    void numb5()
    {
        QString str = canalLab->text();
        if (str.length() < 3)
            canalLab->setText(str + "5");
        else
            canalLab->setText("5");
    }
    void numb6()
    {
        QString str = canalLab->text();
        if (str.length() < 3)
            canalLab->setText(str + "6");
        else
            canalLab->setText("6");
    }
    void numb7()
    {
        QString str = canalLab->text();
        if (str.length() < 3)
            canalLab->setText(str + "7");
        else
            canalLab->setText("7");
    }
    void numb8()
    {
        QString str = canalLab->text();
        if (str.length() < 3)
            canalLab->setText(str + "8");
        else
            canalLab->setText("8");
    }
    void numb9()
    {
        QString str = canalLab->text();
        if (str.length() < 3)
            canalLab->setText(str + "9");
        else
            canalLab->setText("9");
    }
    void numb0()
    {
        QString str = canalLab->text();
        if (str.length() < 3)
            canalLab->setText(str + "0");
        else
            canalLab->setText("1");
    }
    void canNext()
    {
        int numbCanal = 1;
        QString str = canalLab->text();
        numbCanal = str.toInt();
        if (numbCanal < 20)
            numbCanal++;
        else
            numbCanal = 1;
        canalLab->setText(QString::number(numbCanal));
    }
    void canPrev()
    {
        int numbCanal = 1;
        QString str = canalLab->text();
        numbCanal = str.toInt();
        if (numbCanal > 1)
            numbCanal--;
        else
            numbCanal = 20;
        canalLab->setText(QString::number(numbCanal));
    }
    void volUp()
    {
        int volLevel = 0;
        QString str = volLab->text();
        volLevel = str.remove("%").toInt();
        volLevel += 10;
        if (volLevel > 100)
            volLevel = 100;
        volLab->setText(QString::number(volLevel) + "%");
    }
    void volDown()
    {
        int volLevel = 0;
        QString str = volLab->text();
        volLevel = str.remove("%").toInt();
        volLevel -= 10;
        if (volLevel < 0)
            volLevel = 0;
        volLab->setText(QString::number(volLevel) + "%");
    }
};
