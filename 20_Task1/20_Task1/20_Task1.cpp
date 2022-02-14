// 20_Task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

int main() {
	std::string first_name, second_name, date;
	int sum;
	std::ofstream table("..\\Table.txt", std::ios::app);
	if (table.is_open()) {
		std::cout << "\tEnter data\n";
		std::cout << "First name: ";
		std::cin >> first_name;
		std::cout << "Second name: ";
		std::cin >> second_name;
		std::cout << "The date in the format DD.MM.YYYY: ";
		std::cin >> date;
		int day = std::stoi(date.substr(0, 2));
		int month = std::stoi(date.substr(3, 2));
		int year = std::stoi(date.substr(6, 4));

		if (year < 2000 || year > 2024) {
			std::cout << "Incorrect year";
			return -1;
		}
		if (month < 1 || month > 12) {
			std::cout << "Incorrect month";
			return -1;
		}
		if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			&& (day < 1 || day > 31)) {
			std::cout << "Incorrect day";
			return -1;
		}
		if((month == 4 || month == 6 || month == 9 || month == 11) && (day < 1 || day > 30)) {
			std::cout << "Incorrect day";
			return -1;
		}
		if((month == 2 && (day < 1 || day > 28)) || (month == 2 && (year == 2024 || year == 2020 || year == 2016 || year == 2012
			|| year == 2008 || year == 2004 || year == 2000) && (day < 1 || day > 29))) {
			std::cout << "Incorrect day";
			return -1;
		}

		std::cout << "Amount of payments: ";
		std::cin >> sum;
		table << first_name << " " << second_name << " " << date << " " << sum << "\n";
	}
	else std::cout << "File is not open!\n";
	table.close();
}