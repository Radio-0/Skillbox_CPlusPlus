// 19_Task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <istream>
#include <string>
#include <fstream>
#include <vector>

int main()
{
	std::ifstream file;
	std::string path;
	char buffer[50];
	std::cout << "Enter path to file.txt(Example: ..\\TextFile.txt):\n";
	std::getline(std::cin, path);
	file.open(path, std::ios::binary);
	if (file.is_open()) {
		std::cout << "File is open!\n";
		file.read(buffer, sizeof(buffer) - 1);
		buffer[file.gcount()] = 0;
		std::cout << buffer;
	}
	else std::cout << "File is not open!\n";

	file.close();
}