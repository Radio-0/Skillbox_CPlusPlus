/*Задание 3. Симуляция работы компании
Реализуйте симуляцию работы компании.В компании осуществляется вертикальное управление с иерархией.Есть основные рабочие подчинённые, разбитые на команды.У каждой команды есть свой менеджер среднего звена.Во главе всей компании стоит её руководитель — глава компании.
Глава компании осуществляет стратегическое управление.Он определяет основной вектор движения — задачи верхнего уровня.Менеджеры среднего звена разбивают эти задачи на подзадачи и раздают их своим подчинённым.Подчинённые осуществляют выполнение работ.
Реализация данной логики должна проходить упрощённым образом.Указания главы компании поступают из стандартного ввода и являются не более чем целочисленными идентификаторами.
Данные идентификаторы служат зерном для генератора случайных чисел.Каждый из менеджеров, принимая себе эту целочисленную команду, добавляет к ней свой порядковый номер и вызывает с результирующей суммой функцию std::srand().
На основе этой суммы вычисляется общее количество задач, которое требуется выполнить данной командой, — от 1 до количества работников в группе.Всего существует три типа задач для работников : A, B и C.Они тоже выбираются случайно и распределяются между незанятыми рабочими.
При старте программы пользователь указывает в стандартном вводе количество команд и количество работников в каждой из команд.
Далее пользователь вводит целые числа, которые соответствуют указаниям руководителя компании.Программа завершается, когда все работники заняты какими - то задачами.*/

#include <iostream>
#include <vector>
#include <string>

class Person {
    std::string name = "unknow";
public:
    std::string getName() {
        return name;
    }
    void setName(const std::string& name) {
        this->name = name;
    }
};

class Worker : public Person {
    char task = '\0';
public:
    Worker(std::string inName) {
        setName(inName);
    }
    void setTaskWorker(char task) {
        this->task = task;
    }
    char getTask() {
        return task;
    }
    bool getBusy() {
        return task != '\0';
    }
};

class Manager : public Person {
    int id = 0;
    std::vector<Worker> workers;
public:
    Manager(const std::string& inName, int inId) {
        setName(inName);
        this->id = inId;
    }
    void setWorkers(int numbWorkers) {
        for (int i = 0; i < numbWorkers; i++) {
            workers.push_back(Worker("Worker_" + std::to_string(i+1)));
        }
    }
    void setTaskManager(int command) {
        int buf = command + id;
        std::srand(buf);
        int tasksCount = rand() % workers.size() + 1;

        for (int i = 0; i < workers.size() && tasksCount > 0; ++i) {
            char task = 'A' + rand() % 3;
            if (!workers[i].getBusy()) {
                tasksCount--;
                workers[i].setTaskWorker(task);
            }
        }
    }
    bool teamBusy() {
        std::cout << getName() << "'s team" << std::endl;
        bool found = false;
        for (int i = 0; i < workers.size(); i++) {
            std::string doing = "doing a ";
            if (!workers[i].getBusy() && !found) {
                found = true;
            }
            std::cout << workers[i].getName() << ": " << (workers[i].getBusy() ?
                doing + workers[i].getTask() : "free") << "\n";
        }
        return !found;
    }

};

class Director : public Person {
    std::vector<Manager> teams;
public:
    void setTeams(int numbTeams) {
        for (int i = 0; i < numbTeams; ++i) {
            std::string name;
            int numbWorkers;
            std::cout << "Enter the manager name: ";
            std::cin >> name ;
            std::cout << "Enter the number workers: ";
            std::cin >> numbWorkers;
            std::cout << "\n";
            teams.push_back(Manager(name, 1 + i));
            teams[i].setWorkers(numbWorkers);
        }
    }
    void setCommand(int command) {
        for (int i = 0; i < teams.size(); i++) {
            teams[i].setTaskManager(command);
        }
    }
    bool companyBusy() {
        bool found = false;
        for (int i = 0; i < teams.size(); i++) {
            if (!teams[i].teamBusy() && !found) {
                found = true;
            }
        }
        return !found;
    }
};

int main() {
    Director* director = new Director();
    int numbTeams;
    std::cout << "Enter the number team: ";
    std::cin >> numbTeams;
    director->setTeams(numbTeams);
    do {
        int command = 0;
        std::cout << "Enter the command: ";
        std::cin >> command;
        director->setCommand(command);
    } while (!director->companyBusy());
    delete director;
    director = nullptr;
    return 0;
}