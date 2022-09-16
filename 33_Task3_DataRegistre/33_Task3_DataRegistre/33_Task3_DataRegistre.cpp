/*Задание 3. Реестр данных на шаблонах
С помощью шаблонов реализуйте простой класс реестра, хранящий произвольные типы значений по ключам произвольного типа. Ключи при этом могут повторяться.
Реестр должен поддерживать следующие операции: добавление элемента с ключом, удаление элементов с заданным ключом, вывод всех значений с ключами в консоль, поиск элементов по ключу.
Для тестирования программы предусмотрите ввод данных и команд из стандартной консоли:
add — добавить элемент с ключом;
remove — удалить все элементы с заданным ключом;
print — напечатать на экране все элементы с их ключами;
find — найти все элементы по их ключу.
Данный словарь должен работать на значениях и ключах следующих типов: int, double, std::string.
Рекомендации
Для реализации можете использовать стандартный шаблон std::vector, который в свою очередь уже будет хранить ваши пары ключей и значений.
Сама пара ключа и значения как раз и будет классом (или струкурой), шаблонизированным двумя типами: типом значения и типом ключа. 
При желании вы можете создать отдельную шаблонизированную функцию с вводом команд и их данных.*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

template<typename Key, typename Value>
class Register
{
    map<Key, Value> registy;
public:
    void add()
    {
        Key key;
        Value val;
        cout << "Enter key and value to add: ";
        cin >> key;
        cin >> val;
        registy.insert(pair<Key, Value>(key, val));
    }
    void remove()
    {
        Key key;
        cout << "Enter key to delete: ";
        cin >> key;
        if (registy.find(key) == registy.end())
            cout << "No data found with this key\n";
        else
            registy.erase(key);
    }
    void print()
    {
        cout << "Key: Value\n";
        for (const auto it : registy)
            cout << it.first << ": " << it.second << endl;
    }
    void find()
    {
        Key key;
        cout << "Enter key to find value: ";
        cin >> key;
        cout << "Value:\n";
        for (const auto it : registy)
        {
            if (it.first == key)
                cout << it.second;
        }
    }
};

int main()
{
    Register<string, int> reg;
    string command;
    do
    {
        cout << "Enter command (add, remove, print, find, exit): ";
        cin >> command;
        if (command == "add")
            reg.add();
        else if (command == "remove")
            reg.remove();
        else if (command == "print")
            reg.print();
        else if (command == "find")
            reg.find();
    }while (command != "exit");
    return 0;
}

