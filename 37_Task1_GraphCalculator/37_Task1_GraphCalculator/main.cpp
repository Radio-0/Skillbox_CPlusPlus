/*Задание 1. Графический калькулятор
Реализуйте графическое приложение для основных операций с целыми числами: сложение, вычитание, умножение, деление.
В верхней части окна приложения расположено два текстовых поля для ввода двух чисел. Чуть ниже — поле с выводом результата. Далее снизу — кнопки четырёх основных действий: сложить, вычесть, умножить, разделить. Интерфейс должен быть свободно масштабируемым в зависимости от размера самого окна.
Если какая-то операция не может быть выполнена по причине некорректности данных, в поле результата записывается текст «ERROR».
Советы и рекомендации
При желании вы можете усложнить себе задачу, реализовав работу калькулятора на числах с плавающей точкой.*/
#include "Task1_GraphCalculator.h"
#include <QtWidgets/QApplication>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) // "+" "-" "*" "/"
{
    QApplication app(argc, argv);
    Task1_GraphCalculator window(nullptr);
    Ui::Task1_GraphCalculatorClass calcul;
    calcul.setupUi(&window);
    window.displayOut = calcul.label;
    window.lineEdit1 = calcul.lineEdit1;
    window.lineEdit2 = calcul.lineEdit2;
    window.resize(300, 400);
    window.show();
    return app.exec();
}
