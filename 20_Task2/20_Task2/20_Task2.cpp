// 20_Task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>

int main() {
	std::vector<int> num;
	int height, width;
	std::ofstream pic("..\\pic.txt");	
	std::srand(std::time(0));
	if (pic.is_open()) {		
		std::cout << "Enter height picture: ";
		std::cin >> height;
		std::cout << "Enter width picture: ";
		std::cin >> width;
		
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				num.push_back(std::rand() % 2 + 0);
				std::cout << num[j];
				pic << num[j];
			}
			std::cout << "\n";
			pic << "\n";
		}
	}
	else std::cout << "File is not open!\n";
	pic.close();

	return 0;
}