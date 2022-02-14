// 21_Task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

struct statement{
	std::string name = "unknow";
	std::string date = "unknow";
	int sum = 0;
};

void read_table(std::ifstream& file, statement& data) {
	
	if (file.is_open()) {
		int len_name, len_date;
		file.read((char*)&len_name, sizeof(len_name));
		data.name.resize(len_name);
		file.read((char*)data.name.c_str(), len_name);
		file.read((char*)&len_date, sizeof(len_date));
		data.name.resize(len_date);
		file.read((char*)data.date.c_str(), len_date);
		file.read((char*)&data.sum, sizeof(data.sum));

		std::cout << " Name: " << data.name << " Date: " << data.date << "Sum = " << data.sum;
	}
	else std::cout << "File is not open!\n";

	file.close();
}

void add_table(std::ofstream& file, statement& data) {
	if (file.is_open()) {
		std::cout << "\tEnter data\n";
		std::cout << "Name: ";
		std::cin >> data.name;
		int len_name = data.name.length();
		file.write((char*)&len_name, sizeof len_name);
		file.write(data.name.c_str(), len_name);
		
		std::cout << "The date in the format DD.MM.YYYY: ";
		std::cin >> data.date;
		int day = std::stoi(data.date.substr(0, 2));
		int month = std::stoi(data.date.substr(3, 2));
		int year = std::stoi(data.date.substr(6, 4));

		if (year < 2000 || year > 2024) {
			std::cout << "Incorrect year";
		}
		if (month < 1 || month > 12) {
			std::cout << "Incorrect month";
		}
		if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			&& (day < 1 || day > 31)) {
			std::cout << "Incorrect day";
		}
		if ((month == 4 || month == 6 || month == 9 || month == 11) && (day < 1 || day > 30)) {
			std::cout << "Incorrect day";
		}
		if ((month == 2 && (day < 1 || day > 28)) || (month == 2 && (year == 2024 || year == 2020 || year == 2016 || year == 2012
			|| year == 2008 || year == 2004 || year == 2000) && (day < 1 || day > 29))) {
			std::cout << "Incorrect day";
		}
		int len_date = data.date.length();
		file.write((char*)&len_date, sizeof len_date);
		file.write(data.date.c_str(), len_date);
		std::cout << "Amount of payments: ";
		std::cin >> data.sum;
		file.write((char*)&data.sum, sizeof(data.sum));
	}
	else std::cout << "File is not open!\n";
	file.close();
}

int main()
{
	std::string command;
	statement date;
	std::cout << "Enter command (read or add): ";
	std::cin >> command; //"read" or "add"
	if (command == "read") {
		std::ifstream table("..\\table.bin", std::ios::binary);
		read_table(table, date);
	}
	else if (command == "add") {
		std::ofstream table("..\\table.bin", std::ios::binary);
		add_table(table, date);
	}
	else {
		std::cout << "Command ERROR";
		return -1;
	}
}