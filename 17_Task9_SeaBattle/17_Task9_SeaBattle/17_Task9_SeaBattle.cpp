// 17_Task 9 Sea Battle.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>

void initial(char field[10][10]) {		//изначальное заполнение полей
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			field[i][j] = '-';
		}
	}
}

void arrange(char field[10][10], int ships, int section) {	//заполнение полей кораблями
	int x1, y1, x2, y2;
	int number = ships;		//счетчик количества кораблей
	while (number > 0) {
		if (ships == 4) {
			std::cout << "Enter coordinates ship: ";
			int i, j;
			std::cin >> i >> j;
			if (field[i][j] != '-') {
				std::cout << "Error. ";
				continue;
			}
			else {
				field[i][j] = 'o';
				std::cout << "Next\n";
			}
			--number;
		}
		else {
			std::cout << "Enter coordinates beginning ship: ";
			std::cin >> x1 >> y1;
			std::cout << "Enter coordinates ending ship: ";
			std::cin >> x2 >> y2;
			int delta_x = abs(x1 - x2);
			int delta_y = abs(y1 - y2);
			if (((x1 < 0 || x1>9) || (x2 < 0 || x2>9) || (y1 < 0 || y1>9) ||
				(y2 < 0 || y2>9)) || ((x1 == x2) && (y1 == y2)) || ((x1 != x2) && (y1 != y2)) ||
				((delta_x != section - 1) && (delta_y != section - 1))) {
				std::cout << "Error coordinates.\n";
				continue;
			}
			for (int i = x1; i <= x2; i++) {
				for (int j = y1; j <= y2; j++) {
					if (field[i][j] != '-') {
						std::cout << "Error. ";
						continue;
					}
					else {
						field[i][j] = 'o';
						std::cout << "Next\n";
					}
				}
			}
			--number;
		}
	}
}

void display(char field[10][10]) {		//отображение полей
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			std::cout << field[i][j] << " ";
		}
		std::cout << "\n";
	}
}

bool shoot(char field[10][10], int x, int y, bool hit_player) {	//выстрел и его проверка
	bool hit = hit_player;
	if (field[x][y] == 'o') {
		std::cout << "HIT!\n";
		field[x][y] = 'x';
		hit = true;
	}
	else {
		std::cout << "MISS!\n";
		hit = false;
	}
	return hit;
}

int main() {
	char field_first[10][10];
	char field_second[10][10];
	int small = 4;	 //количество кораблей
	int nsmall = 3;
	int middle = 2;
	int big = 1;
	int section_small = 1, section_nsmall = 2, section_middle = 3, section_big = 4; //количество секций кораблей 
	bool won_first = false;
	bool won_second = false;
	int progress = 0;
	bool hit_first = false, hit_second = false;			//результат выстрела
	int number_hit_first = 0, number_hit_second = 0;

	std::cout << "\tGame: Sea Battle. Win only ONE!\n\n";
	initial(field_first);		//изначальное заполнение полей
	initial(field_second);
	std::cout << "Arrange the ships in turn.\n\n"; //расстановка кораблей
	arrange(field_first, small, section_small);
	arrange(field_second, small, section_small);
	arrange(field_first, nsmall, section_nsmall);
	arrange(field_second, nsmall, section_nsmall);
	arrange(field_first, middle, section_middle);
	arrange(field_second, middle, section_middle);
	arrange(field_first, big, section_big);
	arrange(field_second, big, section_big);
	std::cout << "First's field.\n";	//отображение полей с кораблями
	display(field_first);
	std::cout << "Second's field.\n";
	display(field_second);
	while (!won_first && !won_second) {	//выстрел и его проверка
		int x, y;
		std::cout << "Enter coordinates shoot:\n";
		std::cin >> x >> y;
		if ((x < 0 || x>9) || (y < 0 || y>9)) {
			std::cout << "Error coordinates.\n";
			continue;
		}
		if (progress % 2 == 0) {
			hit_first = shoot(field_second, x, y, hit_first);
			if (hit_first) number_hit_first++;
			if (number_hit_first == 20) won_first = true;
		}
		else {
			hit_second = shoot(field_first, x, y, hit_second);
			if (hit_second) number_hit_second++;
			if (number_hit_second == 20) won_second = true;
		}
		++progress;
	}
	std::cout << "First's field.\n";	//отображение полей с кораблями
	display(field_first);
	std::cout << "Second's field.\n";
	display(field_second);
	if (won_first)	std::cout << "Win First";
	else if (won_second) std::cout << "Win Second";
}