/*Задание 2. Регистратура
Напишите программу «Регистратура».
На вход программе приходят строки с фамилиями или строка Next.Пришедшие люди становятся в очередь, а по запросу Next необходимо вызвать в регистратуру человека с фамилией, идущей первой в лексикографическом порядке(по алфавиту), и вывести его фамилию на экран.Фамилии пациентов могут повторяться.
Каждый запрос(на добавление и вывод) должен работать за O(logn).
Пример:
← Sidorov
← Ivanov
← Ivanov
← Petrov
← Next
→ Ivanov
← Next
→ Ivanov
← Next
→ Petrov
Чек - лист для проверки задачи
Программа корректно выводит фамилии в лексикографическом порядке.
Программа использует только заголовочные файлы <iostream>, <string>, <map>.*/

#include <iostream>
#include <map>
#include <string>

int main()
{
	std::string command;
	int n = 1;
	std::map<std::string, int> regist;
	std::map<std::string, int>::iterator it;
	while (command != "exit") {
		std::cout << "Enter name, 'Next', exit:\n";
		std::cin >> command;
		for (it = regist.begin(); it != regist.end(); it++) {
			std::cout << it->first << " " << it->second << "\n";
		}
		if (command == "Next" || command == "next") {
			if (!regist.empty()) {
				std::map<std::string, int>::iterator it = regist.begin();
				std::cout << it->first << "\n";
				if (regist[it->first] > 1) regist[it->first]--;
				else regist.erase(it);
			}
			else {
				std::cout << "The list is empty\n";
				continue;
			}
		}
		else {
			if (regist.find(command) != regist.end())
				regist[command]++;
			else regist.insert(std::pair<std::string, int>(command, n));
		}
	}
	return 0;
}