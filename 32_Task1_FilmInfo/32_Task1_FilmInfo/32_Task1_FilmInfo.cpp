/*Задача 1. Информация о фильме с кинопортала
Запишите подробную информацию о киноленте в виде JSON-файла. Выберите понравившуюся вам картину на любимом портале, проанализируйте информацию о ней и составьте JSON-словарь.
В информации должны присутствовать: страна и дата создания киноленты, студия, которая вела съёмки, автор сценария, режиссёр и продюсер киноленты. Обязательно добавьте информацию обо всех главных действующих лицах и тех актёрах, которые их сыграли.*/

#include <iostream>
#include <string>
#include <fstream>
#include "nlohmann_json/include/nlohmann/json.hpp"
using namespace std;

struct Film {
	string country;
	string data;
	string studio;
	string screenwriter;
	string director;
	string producer;
	string mainActor;
	string minorActor;
	string supportingActor;
};

int main()
{
	Film filmInfo;
	filmInfo.country = "USA";
	filmInfo.data = "14.08.2008";
	filmInfo.director = "Christopher Nolan";
	filmInfo.mainActor = "Christian Bale";
	filmInfo.minorActor = "Heath Ledger";
	filmInfo.producer = "Christopher Nolan";
	filmInfo.screenwriter = "Jonathan Nolan";
	filmInfo.studio = "DC Comics";
	filmInfo.supportingActor = "Aaron Eckhart";

	ofstream file("../../../film_info.json");
	nlohmann::json dict = {
		{"Country", filmInfo.country},
		{"Data", filmInfo.data},
		{"Director", filmInfo.director},
		{"Bruce Wayne", filmInfo.mainActor},
		{"Joker", filmInfo.minorActor},
		{"Harvey Dent", filmInfo.supportingActor},
		{"Studio", filmInfo.studio},
		{"Screenwriter", filmInfo.screenwriter},
		{"Producer", filmInfo.producer}
	};
	file << dict;
	if (file.bad() != true) {
		cout << "File is full\n";
	}
	return 0;
}
