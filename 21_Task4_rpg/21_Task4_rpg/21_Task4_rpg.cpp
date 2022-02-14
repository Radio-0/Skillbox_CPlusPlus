// 21_Task4_rpg.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>

struct coordinates {
    int x = 1;
    int y = 1;
};

struct persons_game {
    std::string name = "unknown";
    int health = 0;
    int armor = 0;
    int damage = 0;
    coordinates coord;
};

void take_damage(persons_game& person_def, int damage) {    //получение урона
    std::cout << person_def.name << " take damage: " << damage;
    person_def.armor -= damage;
    if (person_def.armor < 0) {
        person_def.health += person_def.armor;
        person_def.armor = 0;
    }
}

void load_game(std::ifstream& file, persons_game& data) {   //загрузка данных

    if (file.is_open()) {
        int len_name, len_date;
        file.read((char*)&len_name, sizeof(len_name));
        data.name.resize(len_name);
        file.read((char*)data.name.c_str(), len_name);
        file.read((char*)&data.health, sizeof(data.health));
        file.read((char*)&data.armor, sizeof(data.armor));
        file.read((char*)&data.damage, sizeof(data.damage));
        file.read((char*)&data.coord, sizeof(data.coord));
    }
    else std::cout << "File is not open!\n";

    file.close();
}

void save_game(std::ofstream& file, persons_game& data) {   //сохранение данных
    int len = data.name.length();
    file.write((char*)&len, sizeof(len));
    file.write(data.name.c_str(), len);
    file.write((char*)&data.health, sizeof(data.health));
    file.write((char*)&data.armor, sizeof(data.armor));
    file.write((char*)&data.damage, sizeof(data.damage));
    file.write((char*)&data.coord, sizeof(data.coord));
}

int main() {
    const int num_person = 6;
    int max_coord = 40;
    std::string command;    //left, right, top, bottom, save, load, exit
    persons_game person[num_person];
    for (int i = 0; i < num_person; i++) {  //создание персонажей
        srand(time(NULL));
        person[i].name = "Enemy #" + i + 1;
        person[i].health = rand() % 150 + 50;
        person[i].armor = rand() % 50 + 0;
        person[i].damage = rand() % 30 + 15;
        person[i].coord.x = rand() % 40 + 1;
        person[i].coord.y = rand() % 40 + 1;
        if (i == 5) {
            std::cout << "Enter name person: ";
            std::cin >> person[i].name;
            std::cout << "Enter health person: ";
            std::cin >> person[i].health;
            std::cout << "Enter armor person: ";
            std::cin >> person[i].armor;
            std::cout << "Enter damage person: ";
            std::cin >> person[i].damage;
            person[i].coord.x = rand() % 40 + 1;
            person[i].coord.y = rand() % 40 + 1;
        }
    }
    
    while (command != "exit") { //ввод команд
        
            std::cout << "Enter action: left - a, right - d, top - w, bottom - s, save, load, exit: ";
            std::cin >> command;

        if (command == "a") {   //действия команд
            if (person[5].coord.x > 1) {
                person[5].coord.x -= 1;
            }
        }
        else if (command == "d") {
            if (person[5].coord.x < max_coord) {
                person[5].coord.x += 1;
            }
        }
        else if (command == "s") {
            if (person[5].coord.y > 1) {
                person[5].coord.y -= 1;
            }
        }
        else if (command == "w") {
            if (person[5].coord.y < max_coord) {
                person[5].coord.y += 1;
            }
        }
        else if (command == "save") {
            std::ofstream save_file("..\\save.bin", std::ios::binary);
            for (int i = 0; i < num_person; i++) {
                save_game(save_file, person[i]);
            }
            std::cout << "Save game";
        }
        else if (command == "load") {
            std::ifstream save_file("..\\save.bin", std::ios::binary);
            for (int i = 0; i < num_person; i++) {
                load_game(save_file, person[i]);
            }
            std::cout << "Load game";
        }
        else if (command != "exit") {
            std::cout << "Wrong command/n";
            continue;
        }
        for (int i = 0; i < num_person - 1; i++) { //перемещение
            int move[4] = { person[i].coord.x++, person[i].coord.x--, person[i].coord.y++, person[i].coord.y-- };
            srand(time(NULL));
            int move_pers = rand() % 4;
            if (person[i].coord.x < 1) {
                person[i].coord.x += 1;
            }
            if (person[i].coord.x > max_coord) {
                person[i].coord.x -= 1;
            }
            if (person[i].coord.y < 1) {
                person[i].coord.y += 1;
            }
            if (person[i].coord.y > max_coord) {
                person[i].coord.y -= 1;
            }
            if (person[i].coord.x == person[5].coord.x && person[i].coord.y == person[5].coord.y) {
                take_damage(person[5], person[i].damage);
                take_damage(person[i], person[5].damage);
            }
            if (person[5].health <= 0) {    //проверка жизней
                std::cout << "Wasted";
                return 0;
            }
            else {
                int num_enemy = 5;
                for (int i = 0; i < num_person - 1; i++) {
                    if (person[i].health <= 0) {
                        num_enemy--;
                    }
                }
                if (num_enemy == 0) {
                    std::cout << "You win";
                    return 0;
                }
            }
        }        
    }
    std::cout << "Exit game";    
    return 0;
}