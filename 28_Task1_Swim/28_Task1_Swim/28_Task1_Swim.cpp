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
using namespace std;

#define DISTANCE 100
#define NUMB_SWIM 6

class Swim {
    string name = "none";
    float speed = 0.0;
    float time = 0.0;
    float distance = 0.0;
public:
    Swim (string inName, float inSpeed) : name(inName), speed(inSpeed){
        name = inName;
        speed = inSpeed;
    }
    float getDistance() {
        return distance;
    }
    void setDistance(float get) {
        distance = speed * 1 + get;
        if (distance >= DISTANCE) {
            distance = DISTANCE;
            setTime(speed);
        }            
    }
    void setTime(float speed) {
        time = DISTANCE / speed;
    }
    void setTimeTemp(float temp) {
        time = temp;
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

void info_output(string name, float distance) {
    this_thread::sleep_for(chrono::seconds(1));
    cout << name << " " << distance << "m\n";
}

int main(){
    vector<Swim> swimmers;
    string name;
    float speed;
    for (int i = 0; i < NUMB_SWIM; i++) {
        cout << "Enter swimmer name and speed: ";
        cin >> name >> speed;
        swimmers.push_back(Swim(name, speed));
    }
    float minSpeed = swimmers[0].getSpeed();
    int numbMin = 0;
    for (int i = 0; i < swimmers.size(); i++) {
        if (minSpeed > swimmers[i].getSpeed()) {
            minSpeed = swimmers[i].getSpeed();
            numbMin = i;
        }
    }
    thread info[NUMB_SWIM];
    while (swimmers[numbMin].getDistance() != DISTANCE) {
        for (int i = 0; i < swimmers.size(); i++) {
            info[i] = thread(info_output, swimmers[i].getName(), swimmers[i].getDistance());
            swimmers[i].setDistance(swimmers[i].getDistance());
        }
        for (int i = 0; i < NUMB_SWIM; i++) {

            info[i].join();
        }
        cout << endl;
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