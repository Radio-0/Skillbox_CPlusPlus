// 17_Task 2  Tac-Toe.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

void fill(char field[3][3]) {	//начальное заполнение поля
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			field[i][j] = '-';
		}
	}
}

void display(char field[3][3]) {	//отображение игрового поля
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << field[i][j];
		}
		std::cout << "\n";
	}
}

int main()
{
	char field[3][3];	//поле игры
	bool won_X = false, won_O = false;
	int line, column;
	int number_cell = 0;

	fill(field);

	while (!won_X && !won_O && number_cell < 9) {

		std::cout << "Enter coordinates. For example: 1 2. But line < 3, column < 3." << std::endl;
		std::cin >> line >> column;			//ввод координат для постановки 0 или Х
		if (field[line][column] == '-') {
			if (number_cell % 2 == 0) {
				field[line][column] = 'x';
			}
			else field[line][column] = 'o';
		}
		else if(line > 2 || line < 0 || column > 2 || column < 0){
			std::cout << "Enter OTHER coordinates." << "\n";
			continue;
		}
		number_cell++;
		display(field);
		for (int i = 0; i < 3; i++) {		//проверка на победу
			for (int j = 0; j < 3; j++) {
				if ((field[i][j] == 'x' && field[i][j + 1] == 'x' && field[i][j + 2] == 'x') ||
					(field[i][j] == 'x' && field[i + 1][j] == 'x' && field[i + 2][j] == 'x'))
					won_X = true;
				else if ((field[i][j] == 'o' && field[i][j + 1] == 'o' && field[i][j + 2] == 'o') ||
					(field[i][j] == 'o' && field[i + 1][j] == 'o' && field[i + 2][j] == 'o'))
					won_O = true;
				else break;
			}
		}
	}
	if (won_X == true)
		std::cout << "Win X";
	else if (won_O == true)
		std::cout << "Win O";
	else std::cout << "Draw!";	//ничья
}