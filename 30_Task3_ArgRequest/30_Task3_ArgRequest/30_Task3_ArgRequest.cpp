//Задание 3. Запросы с аргументами

#include <iostream>
#include <cpr/cpr.h>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main()
{
	map<string, string> listCar;
	string model, speed;
	cpr::Response request;
	while (model != "post" && model != "get") {
		cout << "Enter the model of car and its speed:";
		cin >> model;
		if (model == "post") {
			map<string, string>::iterator it;
            vector<cpr::Pair> vecPair;
			for (it = listCar.begin(); it != listCar.end(); it++) {
                cpr::Pair pair(it->first, it->second);
                vecPair.push_back(pair);
			}
            request = cpr::Post(cpr::Url("http://httpbin.org/post"),
                                cpr::Payload(vecPair.begin(), vecPair.end()));
            cout << request.text;
            break;
		}
        else if (model == "get") {
            map<string, string>::iterator it;
            string buf = "";
            for (it = listCar.begin(); it != listCar.end(); it++) {
                buf += it->first + "=" + it->second + "&";
            }
            buf = buf.substr(0, buf.length() - 1);
            cout << buf << endl;
            request = cpr::Get(cpr::Url("http://httpbin.org/get?" + buf));
            request.text.find("url");
            cout << request.text;
            break;
		}
        cin >> speed;
        listCar.insert(pair<string, string>(model, speed));
	}
	return 0;
}
