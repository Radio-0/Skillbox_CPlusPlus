// 19_Task _1_Speedometer.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

bool compare_max(double value, double reference, double eps) {
    return (value >= reference + eps) || (value <= reference - eps);
}

bool compare_min(double value, double reference, double eps) {
    return (value <= reference - eps);
}

int main()
{
    double start_speed = 0;
    double max_speed = 150;
    double eps = 0.01;
    double speed = 0;
    double delta;
    std::string unit = "km/h";
    std::stringstream speedometer;
    while(true) {
        std::cout << "Enter delta speed: ";
        std::cin >> delta;
        speed += delta;

        if (compare_max(speed, max_speed, eps)) {
            std::cout << "The car will not accelerate more than 150 km/h\n";
            speed -= delta;
            continue;
        }
        if (compare_min(speed, start_speed, eps)) {
            speedometer << std::fixed << std::setprecision(1) << 0. << " " << unit << std::endl;
            break;
        }
        std::cout << "Speed = " << speed << " " << unit << std::endl;

        speedometer << std::fixed << std::setprecision(1) << speed << " " << unit << std::endl;
    }

    std::cout << "Speed change on the speedometer: \n";
    std::cout << speedometer.str();

    return 0;
}