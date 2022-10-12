/*Задание 2
Так как std::unordered_set позволяет нам быстро определять, есть ли указанный ключ в контейнере, мы можем использовать его для фильтрации уникальных чисел.
Создайте лямбда-выражение, принимающее на вход std::vector<int>, в котором содержатся числа, которые могут повторяться. Внутри лямбды создайте unordered_set и при помощи него определяйте, сколько раз текущее число вам встречалось раньше. В результате верните std::unique_ptr<std::vector<int>>, содержащий числа без повторов. При проходе по контейнеру используйте новый формат цикла for и ключевое слово auto. */

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

auto lambdaTerm = [](vector<int> values)
{
    unordered_set<int> set;
    vector<int> result;
    int a = 0;
    for (auto& i : values)
    {
        set.insert(i);
    }
    for (auto i : set)
        result.push_back(i);
    return make_unique<vector<int>>(result);
};

int main()
{
    vector<int> repeate {1, 3, 4, 6, 3, 2, 8, 7, 2};
    auto uni = lambdaTerm(repeate);
    for (auto i : *uni)
        cout << i << " ";
    return 0;
}