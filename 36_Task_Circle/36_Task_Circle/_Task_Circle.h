#pragma once

#include <QtWidgets/QMainWindow>
#include "ui__Task_Circle.h"

class _Task_Circle : public QMainWindow
{
    Q_OBJECT

public:
    _Task_Circle(QWidget *parent = nullptr);
    ~_Task_Circle();

private:
    Ui::_Task_CircleClass ui;
};
