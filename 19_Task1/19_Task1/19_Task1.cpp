// 19_Task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::ifstream words;
	std::string word, word_user;
	int rep = 0;
	std::cout << "Enter word: ";
	std::cin >> word_user;
	words.open("..\\TextFile2.txt");
	if (words.is_open()) {
		while (!words.eof()) {
			words >> word;
			if (word == word_user) rep++;
		}
		std::cout << "Repeat: " << rep;
	}
	else std::cout << "File is not open.";
	words.close();
}