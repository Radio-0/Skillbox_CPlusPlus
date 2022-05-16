/*Задание 1. Пользовательские запросы
Реализуйте программу по осуществлению различных типов HTTP-запросов к сервису httpbin.org.
Пользователь взаимодействует с программой с помощью команд: “get”, “post”, “put”, “delete”, “patch”. В зависимости от команды к серверу httpbin.org осуществляется запрос того или иного типа. Содержимое ответа сервера выводится в стандартный вывод.
Программа завершается, когда пользователь вводит команду “exit”.*/

#include <iostream>
#include <cpr/cpr.h>
using namespace std;

int main()
{
	string command;
	while (command != "exit") {
		cout << "Enter command(get, post, delete, patch or exit):";
		cin >> command;
		if (command == "get") {
			cpr::Response httpGet = cpr::Get(cpr::Url("http://httpbin.org/get"));
			cout << httpGet.text << endl;
		}
		else if (command == "post") {
			cpr::Response httpPost = cpr::Get(cpr::Url("http://httpbin.org/post"));
			cout << httpPost.text << endl;
		}
		else if (command == "delete") {
			cpr::Response httpDelete = cpr::Get(cpr::Url("http://httpbin.org/delete"));
			cout << httpDelete.text << endl;
		}
		else if (command == "patch") {
			cpr::Response httpPath = cpr::Get(cpr::Url("http://httpbin.org/patch"));
			cout << httpPath.text << endl;
		}
	}
	return 0;
}
