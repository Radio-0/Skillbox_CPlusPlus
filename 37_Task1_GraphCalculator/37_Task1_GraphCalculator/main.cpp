/*������� 1. ����������� �����������
���������� ����������� ���������� ��� �������� �������� � ������ �������: ��������, ���������, ���������, �������.
� ������� ����� ���� ���������� ����������� ��� ��������� ���� ��� ����� ���� �����. ���� ���� � ���� � ������� ����������. ����� ����� � ������ ������ �������� ��������: �������, �������, ��������, ���������. ��������� ������ ���� �������� �������������� � ����������� �� ������� ������ ����.
���� �����-�� �������� �� ����� ���� ��������� �� ������� �������������� ������, � ���� ���������� ������������ ����� �ERROR�.
������ � ������������
��� ������� �� ������ ��������� ���� ������, ���������� ������ ������������ �� ������ � ��������� ������.*/
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
