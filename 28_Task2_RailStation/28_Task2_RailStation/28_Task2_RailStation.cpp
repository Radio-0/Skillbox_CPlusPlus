/*Задание 2. Симуляция работы вокзала
С помощью многопоточности реализуйте простую модель железнодорожного вокзала.
С трёх точек отправления в разное время отбывают три разных поезда с условными обозначениями A, B, C.Все они идут на один и тот же вокзал и могут дойти до него в разное время.
На этом целевом вокзале единовременно может находиться только один поезд.Остальные поезда должны ждать, пока уже занятое место освободится.
В начале программы пользователь последовательно вводит для каждого поезда время в пути до вокзала(в секундах).После этого поезда начинают своё движение за заданное количество времени.Как только поезд прибыл на вокзал, он ожидает от пользователя команды depart, которая сигнализирует о его отбытии с вокзала.
По всем событиям(прибытие на вокзал, ожидание свободного места, отбытие с вокзала) вместе с условным обозначением поезда выводятся сообщения в консоль.
Программа завершается, когда на вокзале побывают все три поезда.
Советы и рекомендации
Используйте для вокзала отдельный мьютекс и симулируйте ожидание с помощью него.*/

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

const int trainNumb = 3;

mutex station;

class Train {
    string name = "none";
    int timeTravel;
public:
    Train(string inName, int inTime) {
        name = inName;
        timeTravel = inTime;
    }
    string getName() {
        return name;
    }
    int getTime() {
        return timeTravel;
    }
};

void trainTraffic(Train train) {
    
    this_thread::sleep_for(chrono::seconds(train.getTime()));
    if (station.try_lock())
        station.unlock();
    else
        std::cout << "Train " << train.getName() << " is waiting for the release of the station." << std::endl;
    station.lock();
    cout << "Train " << train.getName() << " arrived at the station.\n";
    string command;
    do {
        cout << "Waiting for the train to depart (depart): \n";
        cin >> command;
    } while (command != "depart");
    std::cout << "Train " << train.getName() << " departs.\n";
    station.unlock();    
}

int main() {
    vector<Train> train;
    string trainName[trainNumb] = { "A", "B", "C" };
    cout << "Enter time travel of the train: ";
    for (int i = 0; i < trainNumb; i++) {
        int time;
        cout << trainName[i] << ": ";
        cin >> time;
        train.push_back(Train(trainName[i], time));
    }
    thread trainThread[trainNumb];
    for (int i = 0; i < trainNumb; i++) {
        trainThread[i] = thread(trainTraffic, train[i]);
    }
    for (int i = 0; i < trainNumb; i++) {
        trainThread[i].join();
    }
    return 0;
}