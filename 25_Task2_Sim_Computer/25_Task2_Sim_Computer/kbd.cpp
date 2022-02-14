#include "kbd.h"
#include "ram.h"

void input() {
    int number[8];
    std::cout << "Enter 8 numbers: ";
    for (int i = 0; i < 8; i++) {
        std::cin >> number[i];
    }
    write(number);
}