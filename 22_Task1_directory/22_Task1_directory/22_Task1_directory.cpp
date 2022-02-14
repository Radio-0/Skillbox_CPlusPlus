// 22_Task1_directory.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
/*Задание 1. Телефонный справочник
Напишите программу «Телефонный справочник».
На вход программе поступают запросы трёх типов :
69 - 70 - 30 Ivanov — добавить телефон и фамилию абонента в справочник
69 - 70 - 30 — узнать фамилию абонента по номеру телефона
Ivanov — узнать телефон абонента по фамилии
Необходимо выводить в консоль ответ на запросы 2 и 3. Обратите внимание, что абоненты по разным номерам могут иметь одинаковые фамилии.В таком случае на запрос 3 необходимо выдать все номера через пробелы.
Операции запросов должны работать за O(logn) или O(logn × количество номеров с этой фамилией).
Чек - лист для проверки задачи:
Программа корректно выводит фамилии и списки номеров.
Программа использует только заголовочные файлы <iostream>, <string>, <map> и, возможно, вектор.*/

#include <iostream>
#include <map>
#include <string>
#include <vector>

int main()
{
	std::string number;
	std::string name;
	std::map<std::string, std::string> direct;
	std::map < std::string, std::vector < std::string>> map_numbers;
	std::cout << "To add by number and by name, enter the number and the name.\n";
	std::cout << "To search by number, enter the number, and the name enter empty.\n";
	std::cout << "To search by name, enter the name, and the number enter empty.\n";

	while (true) {
		std::map<std::string, std::string>::iterator it;
		std::map < std::string, std::vector < std::string>>::iterator itv;

		std::cout << "\nNumber: ";
		getline(std::cin, number);
		std::cout << "Name: ";
		getline(std::cin, name);

		if (number.length() && name.length()) {
			direct.insert(std::pair<std::string, std::string>(number, name));
			map_numbers[name].push_back(number);
			std::cout << "\n";
			for (it = direct.begin(); it != direct.end(); it++) {
				std::cout << it->first << " " << it->second << "\n";
			}
		}

		else if (number.length() && !name.length()) {
			if (direct.find(number) == direct.end())
				std::cout << "This number NOT found\n";
			else std::cout << "Found Name: " << direct[number] << "\n";
		}

		else if (!number.length() && name.length()) {
			if (map_numbers.find(name) == map_numbers.end())
				std::cout << "This name NOT found\n";
			else {
				std::cout << "Found Numbers: ";
				for (const auto& el : map_numbers[name]) {
					for (const auto& s : el) {
						std::cout << s;
					}
					std::cout << " ";
				}
			}
		}

		else continue;
	}
	return 0;
}
