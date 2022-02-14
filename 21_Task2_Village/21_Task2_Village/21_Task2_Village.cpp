// 21_Task2_Village.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

struct rooms {
    std::string type = "bedroom";
    double square;
};

struct floors {
    double height_roof; //высота потолка на этаже
    int num_room; //количество комнат на этаже (2-4)
    std::vector<rooms> room_vec;
};

struct building {
    std::string type = "house";
    double square_area;
    int num_floor; //количество этажей в доме(1-3)
    bool heater = false; //наличие печи (дом/баня)
    std::vector<floors> floor_vec;
};

struct steads {
    int number; //номер участка
    int num_build; //количество построек
    double square;
    std::vector<building> build_vec;
};

struct village {
    int num_stead;
    std::vector<steads> stead_vec;
};

int main()
{
    village vill;
    rooms room;
    floors floor;
    building build;
    steads stead;
    double square_stead_sum = 0, square_builds_sum = 0;
    std::cout << "Enter number of stead in village: ";
    std::cin >> vill.num_stead;

    for (int i = 0; i < vill.num_stead; i++) {
        std::cout << "Enter number stead: " << i;
        std::cin >> stead.number;
        std::cout << "Enter square of stead: " << i;
        std::cin >> stead.square;
        std::cout << "Enter number of building: " << i;
        std::cin >> stead.num_build;
        if (stead.num_build >= 1) {
            for (int j = 0; j < stead.num_build; j++) {
                do {
                    std::cout << "Enter type og building (house, garage, barn, bath): ";
                    std::cin >> build.type;
                } while (build.type != "house" && build.type != "garage" && build.type != "barn" &&
                    build.type != "bath");
                std::cout << "Enter square of building: " << j;
                std::cin >> build.square_area;
                if (build.type == "house" || build.type == "bath")
                    build.heater = true;
                if (build.type == "house") {
                    do {
                        std::cout << "Enter the number of floors in the house (1 - 3): ";
                        std::cin >> build.num_floor;
                    } while (build.num_floor < 1 || build.num_floor > 3);
                    for (int k = 0; k < build.num_floor; k++) {
                        std::cout << "Enter the ceiling height: " << k;
                        std::cin >> floor.height_roof;
                        do {
                            std::cout << "Enter the number of rooms in floor: " << k;
                            std::cin >> floor.num_room;
                        } while (floor.num_room < 2 || floor.num_room > 4);
                        for (int m = 0; m < floor.num_room; m++) {
                            do {
                                std::cout << "Enter type of room: " << m;
                                std::cin >> room.type;
                            } while (room.type != "bedroom" && room.type != "kitchen" && room.type != "bathroom" &&
                                room.type != "child_room" && room.type != "lounge");
                            std::cout << "Enter the square of room: " << m;
                            std::cin >> room.square;
                            floor.room_vec.push_back(room);
                        }
                        build.floor_vec.push_back(floor);
                    }
                }
                stead.build_vec.push_back(build);
            }
            vill.stead_vec.push_back(stead);
        }
        else {
            std::cout << "There must be a building on the site";
            return -1;
        }
    }
    for (int i = 0; i < vill.num_stead; i++) {
        square_stead_sum += vill.stead_vec[i].square;
        for (int j = 0; j < vill.stead_vec[i].num_build; j++) {
            square_builds_sum += vill.stead_vec[i].build_vec[j].square_area;
        }
    }
    std::cout << "Percentage of land occupied by buildings: " << square_builds_sum / square_stead_sum * 100;
    return 0;
}