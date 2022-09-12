/*Задача 2. Анализ данных о фильмах
Используя модель данных из задачи №1, создайте JSON-документ, но теперь уже для пяти различных кинолент. Ключи в этой JSON-базе данных должны быть названиями фильмов, а значениями служить уже словари с информацией о картинах.
Загрузите базу данных в C++-программу для последующего анализа. Предусмотрите следующий функционал: поиск актёра по имени (или фамилии) и вывод в консоль названий кинолент, в которых снимался актёр, и роль, которую он исполнял.*/

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include "nlohmann_json/include/nlohmann/json.hpp"
using namespace std;

int main()
{
	ifstream file("../../../films.json");
	nlohmann::json dict;
	map<string, string> films[5];
	string actor;
	string nameFilm[5] = {"The Dark Knight", "Ford v Ferrari", "The Imaginarium of Doctor Parnassus", "The Prestige", "The Brothers Grimm"};

	if (!file.is_open()) {
		cout << "File is NOT open\n";
	}
	else {
		cout << "File is open\n";
		file >> dict;
		films[0] = dict["The Dark Knight"];
		films[1] = dict["Ford v Ferrari"];
		films[2] = dict["The Imaginarium of Doctor Parnassus"];
		films[3] = dict["The Prestige"];
		films[4] = dict["The Brothers Grimm"];

		cout << "Enter first name or last name actor: ";
		cin >> actor;

		for (int i = 0; i < 5; i++) {
			map<string, string>::iterator it;
			for (it = films[i].begin(); it != films[i].end(); it++) {
				int sizeFind = 0;
				sizeFind = it->second.find(actor);
				if (sizeFind != string::npos) {
					if (it->first == "Country" || it->first == "Data" || it->first == "Director" ||
						it->first == "Producer" || it->first == "Screenwriter" || it->first == "Studio")
						cout << "Incorrect name.\n";
					else
						cout << "In film " << nameFilm[i] << ": " << it->first << endl;
				}
				else break;
			}
		}
	}
	return 0;
}
