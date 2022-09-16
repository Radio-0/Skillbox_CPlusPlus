/*Задание 2. Игра по ловле рыбы
Реализуйте простую игру-симуляцию ловли рыбы. Игровое поле представляет собой девять секторов условного пруда. В начале игры в одном из этих секторов с помощью генератора случайных чисел оказывается рыба. Точно так же, случайным образом, по секторам пруда распределяются и три сапога. Сапог и рыба при этом не могут находиться в одном и том же секторе одновременно, как и несколько сапог сразу в одном из секторов.
Игрок закидывает удочку с приманкой в один из секторов, номер которого вводится стандартным способом через консоль. Задача игрока — угадать сектор, в котором находится рыба и, таким образом, поймать её. Если игрок попал на пустой сектор, то удочку надо забросить повторно. Если игрок поймал сапог, то игра завершается с отрицательным результатом.
Реализовать задачу нужно с помощью исключений: когда успешный заброс удочки генерирует специальное пользовательское исключение, после чего программа должна завершиться и оповестить пользователя об успешной рыбалке и количестве попыток, которое ему для этого потребовалось. Если же был пойман сапог, то должно выводиться сообщение о неудачной ловле.
Рекомендации
Вспомните, что вы можете выбросить в качестве исключения произвольный тип данных. Это может быть и сапог, и рыба.
В функции main потребуется расположить рыбу случайным образом. Для этого сделайте std::srand(std::time(nullptr)); а затем само расположение: field[std::rand() % 9].fish = new Fish(); Благодаря оператору % вы не выйдете за пределы массива.*/

#include <iostream>
#include <exception>
#include <cassert>
using namespace std;

class FishCaughtException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Fish caught\n";
    }
};

class BootCaughtException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Boot caught\n";
    }
};

int main()
{
    char pond[9]{};
    int sector, count = 0;
    bool input = true;
    srand(time(nullptr));
    pond[rand() % 9] = 'f';
    for (int i = 0; i < 3;) {
        int ind = rand() % 9;
        if (pond[ind] == NULL)
        {
            pond[ind] = 'b';
            i++;
        }
    }
    /*for (int i = 0; i < 9; i++) {
        cout << i << " " << pond[i] << endl;
    }*/
    while(input)
    {
        cout << "Enter number of sector: ";
        cin >> sector;
        try
        {
            if (sector < 0 || sector > 8)
                throw invalid_argument(sector < 0 ? "Number sector < 0" : "Number sector > 8");
            count++;
            if (pond[sector] == 'f')
            {
                input = false;
                throw FishCaughtException();
            }    
            else if (pond[sector] == 'b')
            {
                input = false;
                throw BootCaughtException();
            }
        }
        catch (const FishCaughtException& x)
        {
            input = false;
            cerr << x.what() << "Number of attempts: " << count << endl;
        }
        catch (const BootCaughtException& x)
        {
            input = false;
            cerr << x.what() << endl;
        }
        catch (const invalid_argument& x)
        {
            cerr << "Invalid argument: " << x.what() << endl;
        }
    }
    return 0;
}