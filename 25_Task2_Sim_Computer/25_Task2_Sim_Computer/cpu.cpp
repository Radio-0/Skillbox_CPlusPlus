#include <iostream>
#include "cpu.h"
#include "ram.h"

void computer() {
    int sum = 0;
    for (int i = 0; i < 8; i++) {
        sum += read(i);
    }
    std::cout << "Sum of numbers: " << sum << "\n";
}