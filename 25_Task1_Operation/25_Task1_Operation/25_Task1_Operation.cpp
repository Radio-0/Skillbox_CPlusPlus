﻿// 25_Task1_Operation.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
/*Задание 1. Симулятор проведения операций
Реализуйте простой симулятор проведения медицинской операции у пациента. Пользователь выступает в роли хирурга, который запрашивает инструменты у ассистента и применяет их сообразно ситуации.
Пользователь взаимодействует с программой с помощью команд. Команды не имеют сложной встроенной логики: они просто принимают нужные данные в качестве аргументов и выводят сообщения в консоль о выполнении. Данные команд — это одна или две двумерные точки в формате double с координатами X и Y соответственно.
scalpel — принимает на вход две двумерные координаты начала и конца разреза или линии отсечения. При выполнении этой команды в консоль выводится сообщение о том, что был сделан разрез между введёнными координатами. 
hemostat — эта команда принимает на вход одну точку, в которой требуется сделать зажим, о чём также сообщает в консоль.
tweezers — пинцет, как и зажим, принимает одну точку для применения. Сообщение об этом выводится в консоль.
suture — команда хирургической иглы, которая делает шов между двумя указанными точками.
Операция всегда начинается с команды scalpel и заканчивается командой suture. Для окончания работы программы их параметры-точки при этом должны совпасть.
Программу требуется реализовать именно с помощью одного заголовочного файла и одного файла с исходным кодом (cpp). В заголовочном файле должны находиться функции-инструменты. В основном файле — основная логика программы, обработка ввода пользователя.
Советы и рекомендации
Для удобства создайте структуру с типом двумерной координаты (точки) вместе с набором функций для ввода этой координаты из консоли, её вывода в консоль и сравнения на предмет равенства. Для этих целей удобнее всего создать ещё один заголовочный файл.*/

#include <iostream>
#include "procedure.h"

int main()
{
    coordinadets coor;
    coordinadets cut[2];
    coordinadets sut[2];
    bool check = false;
    std::cout << "Enter coordinates for the cut: ";
    for (int i = 0; i < 2; i++) {
        std::cin >> coor.x >> coor.y;
        cut[i] = coor;
    }
    scalpel(cut);
    while (!check){
        std::cout << "Enter coordinates for the clamp: ";
        std::cin >> coor.x >> coor.y;
        hemostat(coor.x, coor.y);

        std::cout << "Enter coordinates for tweezers: ";
        std::cin >> coor.x >> coor.y;
        tweezers(coor.x, coor.y);

        std::cout << "Enter coordinates for the suture: ";
        for (int i = 0; i < 2; i++) {
            std::cin >> coor.x >> coor.y;
            sut[i] = coor;
        }
        suture(sut);
        check = compare(cut, sut);

    }
    return 0;
}