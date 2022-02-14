// 19_Task3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream table;
	std::string path, buf, name;
	int sum = 0;
	int max = 0;
	int tal, tal_name, name_lenght;

	table.open("..\\Table.txt", std::ios::binary);
	if (table.is_open()) {
		std::cout << "File is open!\n";
		while (!table.eof()) {
			table.seekg(table.tellg());
			tal = table.tellg();
			table >> buf;
			table >> buf;
			tal_name = table.tellg();
			name_lenght = tal_name - tal;
			table >> buf;

			if (max < std::stoi(buf)) {
				max = std::stoi(buf);
				name = "";
				table.seekg(tal);
				table >> buf;
				name += buf;
				name += " ";
				table >> buf;
				name += buf;
				table >> buf;
			}

			sum += std::stoi(buf);
			table >> buf;
		}
		std::cout << "Sum = " << sum << " Max = " << max << " Name: " << name;
	}
	else std::cout << "File is not open!\n";

	table.close();
}