#include <fstream>
#include <iostream>
#include "disk.h"
#include "ram.h"
#include "gpu.h"

void save() {
    std::ofstream data("..\\data.txt");
    for (int i = 0; i < 8; i++) {
        data << read(i) << " ";
    }
    data.close();
    std::cout << "Data written to file.\n";
}

void load() {
    std::ifstream data("..\\data.txt");
    int num[8];
    for (int i = 0; i < 8; i++) {
        data >> num[i];
    }
    data.close();
    std::cout << "Data read from file.\n";
    write(num);
    display();
}