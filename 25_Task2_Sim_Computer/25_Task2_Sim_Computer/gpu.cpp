#include <iostream>
#include "gpu.h"
#include "ram.h"

void display() {
    std::cout << "Numbers in memory: ";
    for (int i = 0; i < 8; i++) {
        std::cout << read(i) << " ";
    }
    std::cout << std::endl;
}