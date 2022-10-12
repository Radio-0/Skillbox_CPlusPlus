/*Задание 3 (к уроку 4)
Поработать с файловой системой, используя новую библиотеку std::filesystem.
В нашем арсенале теперь есть возможность рекурсивно проходить по каталогам, то есть получить список всех файлов, каталогов (и подкаталогов), которые содержатся по указанному пути. Для этого в стандартной библиотеке есть std::filesystem::recursive_directory_iterator, принимающий на вход путь, который он будет обходить рекурсивно. На каждом шаге он будет выдавать очередной путь, это может быть как каталог, так и обычный файл. Например, код
for(auto& p: fs::recursive_directory_iterator("D:\\dir1"))
        std::cout << p.path() << '\n';
выведет полные пути ко всем файлам и подкаталогам в директории D:\dir1. 
Вызов p.path() возвращает объект типа std::filesystem::path, который позволяет:
Определить, файл это или каталог при помощи метода is_regular_file().
Получить расширение для обычного файла при помощи метода extension().
При помощи метода compare() можно сравнить расширение с произвольной строкой: p.path().extension().compare(“.torrent”).
  Создайте лямбда-функцию, которая принимает на вход путь в файловой системе и искомое расширение в виде строки, а возвращает список имён файлов, которые имеют данное расширение(). Объявление нашей функции может начинаться так:
auto recursiveGetFileNamesByExtension = [](std::filesystem::path path,
          const std::string extension)*/

#include <iostream>
#include <filesystem>
#include <vector>
using namespace std;

auto recursiveGetFileNamesByExtension = 
    [](filesystem::path path, const std::string extension)
{
    if (filesystem::is_directory(path))
    {
        for (auto& p : filesystem::recursive_directory_iterator(path))
        {
            if (!p.path().extension().compare("." + extension))
                cout << p.path().filename() << endl;
        }
    }
    else
        cout << ("Directory NO found");
};

int main()
{
    string fileSystemPath, extension;
    vector<string> listFile;
    cout << "Enter the path and desired file extension: ";
    cin >> fileSystemPath;
    cin >> extension;
    recursiveGetFileNamesByExtension(filesystem::path(fileSystemPath), extension);
    return 0;
}