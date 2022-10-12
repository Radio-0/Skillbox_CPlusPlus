/*Задание 1
Вспомните пример с range-based циклом по закрытию файлов:
for(auto ¤tFile : files)
    currentFile.close();
По аналогии распечатайте числа от 1 до 5, используя auto и initializer_list.*/

#include <iostream>
#include <initializer_list>
using namespace std;

int main()
{
    initializer_list<int> initList{ 1,2,3,4,5 };
    cout << "Init list = ";
    for (auto i : initList)
        cout << i << " ";
    return 0;
}