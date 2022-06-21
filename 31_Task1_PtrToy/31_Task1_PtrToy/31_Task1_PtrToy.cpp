/*Задача 1. Умный указатель на игрушку
Реализуйте умный указатель shared_ptr_toy с распределённым доступом и механикой подсчёта ссылок для класса Toy, реализованного в задании.
Указатель должен иметь все стандартные методы класса и должен быть функциональной заменой использованию shared_ptr<Toy>.
Также реализуйте свободную функцию make_shared_toy, принимающую набор аргументов и конструирующую игрушку либо от названия, либо копируя другую игрушку.
Чек-лист для проверки задачи
Класс называется shared_ptr_toy
Реализован конструктор, конструктор копий, оператор присваивания копированием, деструктор и функция make_shared*/

#include <iostream>
using namespace std;

class Toy {
    string name;
public:
    Toy(string inName) :name(inName) {
        cout << "Creat: " << inName << endl;
    }
    Toy() :name("SomeToy") {};
    string getName() {
        return name;
    }
};

class shared_ptr_toy {
    Toy* ptr_toy;
    int* count;
public:
    shared_ptr_toy(string name) {
        ptr_toy = new Toy(name);
        count = new int(1);
    }
    shared_ptr_toy(const shared_ptr_toy& other) {   //Конструктор копирования
        ptr_toy = other.ptr_toy;
        count = other.count;
        (*count)++;
    }
    shared_ptr_toy& operator=(const shared_ptr_toy& other) {    //Конструктор присваивания
        if (this == &other) return *this;
        if (ptr_toy != nullptr) {
            (*count)--;
            if ((*count) == 0) {
                delete count;
                delete ptr_toy;
            }
        }
        ptr_toy = other.ptr_toy;
        count = other.count;
        (*count)++;
        return *this;
    }
    ~shared_ptr_toy() {
        (*count)--;
        if ((*count) == 0) {
            delete count;
            delete ptr_toy;
        }
    }
};

void make_shared_toy(string name) {
    new shared_ptr_toy(name);
}

int main()
{
    make_shared_toy("Ball");
    return 0;
}