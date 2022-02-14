// 19_Task4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ifstream file;
	std::string path;
	char buffer[10];
	std::cout << "Enter path to file.txt(Example: ..\\image.png):\n";
	std::getline(std::cin, path);
	file.open(path, std::ios::binary);
	if (file.is_open()) {
		std::cout << "File read!\n";
		file.read(buffer, sizeof(buffer));
		std::cout << path.size() << "\n";
		if (path.size() <= 3) {
			std::cout << "File NOT read!\n";
			return 1;
		}

		if (buffer[0] == -119 && buffer[1] == 'P' && buffer[2] == 'N' && buffer[3] == 'G' &&
			path[path.size() - 3] == 'p' && path[path.size() - 2] == 'n' && path[path.size() - 1] == 'g')
			std::cout << "File`s format is PNG";
		else std::cout << "File`s format is NOT PNG";
	}
	else std::cout << "File NOT read!\n";

	file.close();
	return 0;
}