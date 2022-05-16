/*Задание 2. Захват заголовка веб-страницы
Запросите с сервера HTML-страницу. Для этого изучите документацию о запросах, поддерживаемых сервисом httpbin.org/html. Найдите там запрос, который выдаёт именно HTML-страницу. Затем сделайте запрос, явным образом используя заголовок accept: text/html. В полученном ответе найдите заголовок статьи и выведите его в консоль.
Рекомендации
Заголовок статьи размещается между HTML-тегами <h1></h1>.
Для доступа к тексту ответа вам потребуется метод text класса cpr::Response. Для поиска по тексту нужных HTML-тегов лучше использовать метод find.*/

#include <iostream>
#include <cpr/cpr.h>
#include <string>
using namespace std;

int main()
{
	string header;
	cpr::Response page = cpr::Get(cpr::Url("http://httpbin.org/html"));
	cout << page.text;
	int in = page.text.find("<h1>") + 4;
	int out = page.text.find("</h1>");
	while (in != out) {
		header += page.text[in];
		in++;
	}
	cout << header;
	return 0;
}
