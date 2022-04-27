/*Встречаясь, животные реагируют друг на друга. Реализуйте базовый класс Animal, классы-наследники Dog и Cat, и напишите функцию meeting, принимающую два указателя на базовый класс, по которому лежат элементы классов-наследников, которая выводит в консоль разные фразы в зависимости от того, какие конкретные классы встретились.
Dog + Dog → “Woof-Woof”
Dog + Cat → “Bark Meow”
Cat + Dog → “Meow Bark”
Cat + Cat → “Purr Purr”
Пример:
Animal* a = new Dog();
Animal* b = new Cat();
meeting(a,b);
Вывод:
Bark Meow
Чек-лист для проверки задачи
Функция принимает корректные типы данных, тип возвращаемого значения — void.
Решение выполнено через двойную диспетчеризацию или кастование к базовому классу.
Сигнатура функции void meeting (Animal* a, Animal* b), любая другая некорректна.*/

#include <iostream>
using namespace std;
class Dog;
class Cat;

class Animal {
public:
    virtual void voiceType(Animal*) = 0;
    virtual void voiceType(Dog*) = 0;
    virtual void voiceType(Cat*) = 0;
};
class Dog : public Animal {
public:
    virtual void voiceType(Animal* animal) {
        animal->voiceType(this);
    }
    virtual void voiceType(Dog* dog) {
        cout << "Woof ";
    }
    virtual void voiceType(Cat* cat) {
        cout << "Bork ";
    }
};
class Cat : public Animal {
public:
    virtual void voiceType(Animal* animal) {
        animal->voiceType(this);
    }
    virtual void voiceType(Cat* cat) {
        cout << "Purr ";
    }
    virtual void voiceType(Dog* dog) {
        cout << "Meow ";
    }
};
void meeting(Animal* a, Animal* b) {
    b->voiceType(a);
    a->voiceType(b);
    cout << endl;
}

int main()
{
    Animal* dog = new Dog();
    Animal* cat = new Cat();
    meeting(dog, cat);
    meeting(dog, dog);
    meeting(cat, dog);
    meeting(cat, cat);
    return 0;
}