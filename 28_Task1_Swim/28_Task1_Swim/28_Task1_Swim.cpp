/*Задание 1. Заплыв на 100 метров
Реализуйте симуляцию состязаний по заплыву на 100 метров.
Всего шесть дорожек и шесть пловцов.Имена пловцов указываются вначале из стандартного ввода.Каждый из них плывёт с разной скоростью, которая также задаётся пользователем при старте, через стандартный ввод в метрах в секунду.
Каждую секунду в стандартный вывод выдаётся информация о том, сколько проплыл тот или иной пловец.
Как только все пловцы коснулись 100 - метровой отметки, заплыв заканчивается и выводится таблица с итоговыми результатами, отсортированная по возрастанию итогового времени заплыва.
Советы и рекомендации
Используйте нити для реализации движения каждого пловца в отдельности.*/

#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

const int distanceMax = 100;
const int numbSwim = 6;

mutex output;

class Swim {
    string name = "none";
    float speed = 0.0;
    float time = 0.0;
public:
    Swim (string inName, float inSpeed) : name(inName), speed(inSpeed){
        name = inName;
        speed = inSpeed;
        time = distanceMax / inSpeed;
    }
    string getName() {
        return name;
    }
    float getSpeed() {
        return speed;
    }
    float getTime() {
        return time;
    }
};

void info_output(Swim swim) {
    float distance = 0;
    while (distance < distanceMax){
        this_thread::sleep_for(chrono::seconds(1));
        output.lock();
        distance += swim.getSpeed();
        if (distance > distanceMax) {
            distance = distanceMax;
        }
        cout << swim.getName() << " " << distance << "m\n";
        output.unlock();
    } 
}

int main(){
    vector<Swim> swimmers;
    for (int i = 0; i < numbSwim; i++) {
        string name;
        float speed;
        cout << "Enter swimmer name and speed: ";
        cin >> name >> speed;
        swimmers.push_back(Swim(name, speed));
    }
    thread info[numbSwim];
    for (int i = 0; i < numbSwim; i++) {
        info[i] = thread(info_output, swimmers[i]);
    }
    for (int i = 0; i < numbSwim; i++) {
        info[i].join();
    }
    cout << "Finish\n";
    for (int i = 0; i < swimmers.size(); i++) {
        for (int j = 0; j < swimmers.size() - 1; j++) {
            if (swimmers[j].getTime() > swimmers[j + 1].getTime()) {
                Swim temp = swimmers[j];
                swimmers[j] = swimmers[j + 1];
                swimmers[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < swimmers.size(); i++) {
        cout << swimmers[i].getName() << " " << swimmers[i].getTime() << "s\n";
    }
    return 0;
}