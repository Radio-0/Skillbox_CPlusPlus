// 20_Task4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

int printFile(int array[5][2]) {
    std::ofstream file("money.txt", std::ios::binary);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            file << array[i][j];
            file << ' ';
        }
        file << std::endl;
    }
    file.close();
}

void cashIn(int array[5][2]) {
    int amount = 0;
    for (int i = 0; i < 5; i++) {
        amount += array[i][1];
    }
    while (amount < 900) {
        for (int i = 0; i < 5; i++) {
            array[i][1] += rand() % 100;
        }
        amount = 0;
        for (int i = 0; i < 5; i++) {
            amount += array[i][1];
        }
    }
    if (amount > 1000) {
        array[0][1] -= (amount - 1000);
    }
}

void cashOut(int array[5][2], int* outSum) {
    for (int i = 0; i < 5; i++){
        int num = *outSum / array[i][0];
        *outSum %= array[i][0];
        if (num > array[i][1]) {
            std::cout << "Incorrect amount you want to take\n";
            break;
        }
        else {
            std::cout << "There is " << array[i][0] << " following amount " << num << "\n";
        }
        array[i][1] -= num;
    }

} 

int main() {
    std::srand(std::time(NULL));
    int outMoney;
    int* ptrOutMoney = &outMoney;
    std::string str;
    bool check = true;
    int cash[5][2] = {
      {5000, 0},
      {2000, 0},
      {1000, 0},
      {500, 0},
      {100, 0}
    };
    cashIn(cash);
    printFile(cash);
    while (check) {
        std::cout << "Enter operation (+ or -): ";
        std::cin >> str;
        if (str == "+") cashIn(cash);
        else if (str == "-") {
            std::cout << "What amount you want to take: ";
            std::cin >> outMoney;
            cashOut(cash, ptrOutMoney);
            printFile(cash);
        }
        else  check = false;
    }
    return 0;
}