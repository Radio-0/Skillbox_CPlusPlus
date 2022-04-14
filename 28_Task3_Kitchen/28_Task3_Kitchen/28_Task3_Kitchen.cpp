/*Задание 3. Симуляция работы кухни онлайн-ресторана
Требуется реализовать упрощённую модель работы кухни ресторана, работающего в режиме онлайн-доставки.
Онлайн-заказ поступает каждые 5–10 секунд. Это случайное блюдо из пяти: пицца, суп, стейк, салат, суши. Официант, принявший заказ онлайн, оставляет его у кухни. Если кухня свободна, она принимает заказ и спустя 5–15 секунд возвращает уже готовое блюдо на выдачу. Время определяется случайным образом с помощью функции std::rand() в указанных диапазонах.
Курьер приезжает каждые 30 секунд, забирает готовые блюда на выдаче и развозит их по заказчикам.
Программа завершается после 10 успешных доставок. На каждом из этапов, будь то заказ, или готовка, или доставка заказа, выводятся соответствующие сообщения в консоль.
Советы и рекомендации
Для симуляции готовки, используйте отдельный мьютекс и запускайте отдельную нить ожидания с вызовом detach для неё.*/

#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <vector>
using namespace std;

mutex orders;
mutex kitchen;
mutex deliveryM;
string course[5] = { "Pizza", "Soup", "Steak", "Salad", "Sushi" };
vector<int> ordersNumbers;
vector<int> deliveryNumbers;

void orderReceipt() {
    srand(time(nullptr));
    int time = rand() % 10 + 5;
    this_thread::sleep_for(chrono::seconds(time));
    int count = rand() % 4;
    orders.lock();
    cout << course[count] << " ordered\n";
    ordersNumbers.push_back(count);
    orders.unlock();
}

void kitchenCook() {
    if (!ordersNumbers.empty()) {
        orders.lock();
        int count = ordersNumbers.back();
        orders.unlock();
        if (kitchen.try_lock())
            kitchen.unlock();
        srand(time(nullptr));
        int time = rand() % 15 + 5;
        this_thread::sleep_for(chrono::seconds(time));
        kitchen.lock();
        cout << course[count] << " is ready.\n";
        deliveryNumbers.push_back(count);
        kitchen.unlock();
    }    
}

int delivryOrder(int& number) {
    if (!deliveryNumbers.empty()) {
        this_thread::sleep_for(chrono::seconds(30));
        orders.lock();
        kitchen.lock();
        deliveryM.lock();
        for (int i = 0; i < deliveryNumbers.size(); i++) {
            int count = deliveryNumbers[i];
            cout << course[count] << " delivered.\n";
            number++;
        }
        deliveryNumbers.clear();
        orders.unlock();
        kitchen.unlock();
        deliveryM.unlock();
    }
    return number;
}

int main() {
    int numbDelivery = 0;
    while (numbDelivery < 10) {
        thread order(orderReceipt);
        thread cook(kitchenCook);
        thread delivery(delivryOrder, ref(numbDelivery));
        cook.detach();
        if(cook.joinable()) cook.join();
        order.join();
        delivery.join();
    }
    return 0;
}