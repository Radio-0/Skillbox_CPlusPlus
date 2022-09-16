/*Задание 1. Работа корзины с покупками
Реализуйте простую и безопасную модель работы корзины онлайн-магазина.
В начале программы вы заполняете базу данных самого магазина через стандартную консоль. Каждый элемент этой базы данных состоит из двух компонентов — артикула и количества штук.
Корзина должна поддерживать следующие операции: добавление товара с указанным его количеством — add, удаление товара с указанным количеством — remove. Обе операции принимают артикул товара в виде строки и количество в виде целого числа.
При вводе аргументов к операциям должна осуществляться их валидация. Артикул должен быть в базе данных магазина, количество не должно превышать количество доступного продукта на складе (при удалении — в корзине).
Рекомендации
В качестве контейнера для базы данных и самой корзины можете использовать std::map.
Если пользователь ввёл некорректную информацию, то лучше выбросить std::invalid_argument, в других случаях — runtime_error.*/

#include <iostream>
#include <map>
#include <cassert>
#include <exception>
using namespace std;

void printDatabase(map<string, int> data)
{
	map<string, int>::iterator it = data.begin();
	for (; it != data.end(); it++)
	{
		cout << it->first << ": " << it->second << endl;
	}
}

class ShoppingCart
{
	map<string, int> shopCart;
public:
	void add(map<string, int> data)
	{
		string article;
		int quantityGoods;
		cout << "Enter article and quantity of goods for adding in shopping cart: ";
		cin >> article >> quantityGoods;
		try
		{
			auto artFind = data.find(article);
			if (artFind == data.end())
				throw invalid_argument("article");
			else
			{
				map<string, int>::iterator it = data.begin();
				for (; it != data.end(); it++)
				{
					if ((article == it->first) && (quantityGoods > it->second || quantityGoods < 1))
					{
						throw invalid_argument("quantity goods");
					}
					else if (article == it->first)
					{
						it->second -= quantityGoods;
					}
				}
				shopCart.insert(pair<string, int>(article, quantityGoods));
			}
		}
		catch (const invalid_argument& x)
		{
			cerr << "Invalid argument: " << x.what() << endl;
		}
		cout << "Database:\n";
		printDatabase(data);
		cout << "Shopping cart:\n";
		printDatabase(shopCart);
	}

	void remove(map<string, int> data)
	{
		string article;
		int quantityGoods;
		printDatabase(shopCart);
		cout << "Enter article and quantity of goods for removing from shopping cart: ";
		cin >> article >> quantityGoods;
		try
		{
			auto shopFind = shopCart.find(article);
			if (shopFind == shopCart.end())
				throw invalid_argument("article");
			else
			{
				map<string, int>::iterator it = shopCart.begin();
				for (; it != shopCart.end(); it++)
				{
					if ((article == it->first) && (quantityGoods > it->second || quantityGoods < 1))
					{
						throw invalid_argument("quantity goods");
					}
					else if (article == it->first)
					{
						it->second -= quantityGoods;
						auto artFind = data.find(article);
						artFind->second += quantityGoods;
						if (it->second < 1)
							shopCart.erase(shopCart.find(article));
					}
				}
			}
		}
		catch (const invalid_argument& x)
		{
			cerr << "Invalid argument: " << x.what() << endl;
		}
		cout << "Database:\n";
		printDatabase(data);
		cout << "Shopping cart:\n";
		printDatabase(shopCart);
	}

	auto getShopCart()
	{
		return shopCart;
	}
};

int main()
{
	string article;
	int quantityGoods;
	string command;
	map<string, int> database;
	ShoppingCart* cart = new ShoppingCart();
	cout << "Enter the store database (article and quantity of goods): ";
	while (database.size() < 3) {
		cin >> article >> quantityGoods;
		database.insert(pair<string, int>(article, quantityGoods));
	}
	printDatabase(database);
	do
	{
		cout << "Enter command adding or remove in shopping cart (add, remove, exit): ";
		cin >> command;
		//add
		if (command == "add")
		{
			cart->add(database);
		}
		//remove
		else if (command == "remove")
		{
			cart->remove(database);
		}
		else if(command != "exit")
			cout << "Incorrect command\n";
	} while (command != "exit");

	cout << "Shopping cart:\n";
	printDatabase(cart->getShopCart());
	return 0;
}