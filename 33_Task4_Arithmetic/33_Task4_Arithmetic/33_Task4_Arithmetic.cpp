/*Задание 4. Среднее арифметическое число в массиве
Реализуйте шаблонную функцию подсчёта среднего арифметического числа в массиве
скалярных чисел произвольного типа. Это может быть int, double, float и так
далее. Ввод данных массива и вывод результата производится через стандартную
консоль. Рекомендации Для простоты можете реализовать подсчёт в массиве
фиксированной длины. Функцию ввода данных массива тоже рекомендуется реализовать
как шаблонную. Обе функции имеют похожую сигнатуру вида:
template < typename T >
void input(T array[8])
{
    std::cout << "Fill the array (8):";
    for (int i = 0; i < 8; ++i)
    {
//ввод отдельных элементов
    }
}*/
#include <iostream>
using namespace std;

const int size_arr = 5;

template <typename T1>
T1 input(T1 *array) {
    T1 num;
    cout << "Enter numbers: ";
    for (int i = 0; i < size_arr; i++) {
        cin >> num;
        array[i] = num;
    }
    return *array;
}
template <typename T2>
void sum(T2 *array) {
    T2 arihmet = 0;
    for (int i = 0; i < size_arr; i++) {
        arihmet += array[i];
    }
    arihmet /= size_arr;
    cout << "Arithmetic mean: " << arihmet << endl;
}

int main() {
    int num_array[size_arr];
    num_array[0] = input(num_array);
    sum(num_array);
    return 0;
}