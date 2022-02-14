#include <iostream>
#include "ram.h"

int buf[8];

int write(int* numbers) {
    for (int i = 0; i < 8; i++) {
        buf[i] = numbers[i];
    }
    std::cout << "Data is written to the buffer.\n";
    return *buf;
}

int read(int i) {
    return buf[i];
}