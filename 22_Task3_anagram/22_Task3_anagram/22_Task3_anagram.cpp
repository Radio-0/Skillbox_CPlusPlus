/*Задание 3. Анаграммы 
Напишите функцию, которая принимает две строки и возвращает true, если первая строка является анаграммой второй (то есть можно получить первую строку из второй путём перестановки букв местами), и false иначе. Для достижения хорошей асимптотики решения рекомендуется использовать std::map.
Пример анаграммы: лекарство — стекловар
Чек-лист для проверки задачи
Функция принимает корректные типы данных, тип возвращаемого значения — bool.
Функция не использует библиотек, кроме <iostream>, <map>, <string>.
Функция корректно определяет, являются ли строки анаграммами.*/

#include <iostream>
#include <map>
#include <string>

bool check_anagram(std::string str_first, std::string str_second) {
	bool check = false;
	std::map<char, int> str1;
	std::map<char, int> str2;
	int n = 1;

	if (str_first.size() != str_second.size()) return check;

	for (int i = 0; i < str_first.size(); i++) {
		char buf = str_first[i];
		if (str1.find(buf) != str1.end()) str1[buf]++;
		else str1.insert(std::pair<char, int>(buf, n));
	}
	for (int i = 0; i < str_second.size(); i++) {
		char buf = str_second[i];
		if (str2.find(buf) != str2.end())
			str2[buf]++;
		else str2.insert(std::pair<char, int>(buf, n));
	}

	if (str1 == str2) check = true;
	return check;
}

int main()
{
	std::string str1, str2;
	std::cout << "Enter strings: ";
	std::cin >> str1 >> str2;
	if (check_anagram(str1, str2)) std::cout << "Strings are anagrams";
	else std::cout << "Strings are NOT anagrams";
	return 0;
}