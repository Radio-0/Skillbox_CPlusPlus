/*Задание 2. Реализация программы симуляции мобильного телефона
Реализуйте программу простой симуляции работы мобильного телефона.
По мобильному телефону можно звонить и отправлять СМС.Также мобильный телефон содержит адресную книгу.Телефон и отдельные записи адресной книги должны быть реализованы с помощью классов.Все номера телефонов задаются в формате + 7 < 10 цифр > .
Пользователь взаимодействует с программой с помощью команд :
Команда add добавляет в адресную книгу новый номер телефона и ассоциирует его с именем контакта.Оба эти параметра команда получает от пользователя через стандартный ввод.
Команда call запрашивает у пользователя имя контакта или номер телефона, на который требуется позвонить.Сам по себе звонок симулируется с помощью вывода в консоль сообщения CALL с номером телефона, на который осуществляется вызов.
Команда sms.Запрашивает у пользователя номер телефона(или имя контакта), на который требуется послать сообщение.Само сообщение также вводится через стандартный ввод.
Команда exit — выход из программы.
Советы и рекомендации
Сам по себе тип номера телефона вы тоже можете реализовать с помощью отдельного класса.*/

#include <iostream>
#include <string>
#include <vector>

class Contacts {
    std::string name = "unknown";
    std::string number = "unknown";
public:
    Contacts(std::string name, std::string number) : name(name), number(number){}
    std::string getName() {
        return name;
    }
    std::string getNumber() {
        return number;
    }
};

class Phone {
    std::vector<Contacts> contact;
public:
    void setContact(std::string name, std::string number) {
        contact.push_back(Contacts(name, number));
    }

    void add() {
        std::string name, number;
        int attempt = 0;
        std::cout << "Enter name: ";
        std::cin >> name;
        do {
            std::cout << "Enter number: ";
            std::cin >> number;
            if (number.length() != 12 || (number[0] != '+' && number[1] != '7')) {
                std::cout << "Incorrect number.\n";
                attempt++;
            }
            else {
                setContact(name, number);
                std::cout << "Contact added\n";
            }
        } while (attempt != 5);
        std::cout << "Try adding the contact again\n";
    }
    void call() {
        if (contact.size() != 0) {
            std::string contactData;
            std::cout << "Contact list: \n";
            for (int i = 0; i < contact.size(); i++) {
                std::cout << contact[i].getName() << "\n";
            }
            std::cout << "Enter name or number to call: ";
            std::cin >> contactData;
            for (int i = 0; i < contact.size(); i++) {
                if (contactData == contact[i].getName() || contactData == contact[i].getNumber()) {
                    std::cout << "  CALL\n";
                    std::cout << contact[i].getName() << " " << contact[i].getNumber() << "\n";
                }
            }
        }
        else std::cout << "Contact list is empty\n";
    }
    void sms() {
        if (contact.size() != 0) {
            std::string contactData, message;
            std::cout << "Contact list: \n";
            for (int i = 0; i < contact.size(); i++) {
                std::cout << contact[i].getName() << "\n";
            }
            std::cout << "Enter name or number to send sms: ";
            std::cin >> contactData;
            for (int i = 0; i < contact.size(); i++) {
                if (contactData == contact[i].getName() || contactData == contact[i].getNumber()) {
                    std::cout << "Enter text message: ";
                    std::cin >> message;
                    std::cout << "Message sent\n";
                }
            }
        }
        else std::cout << "Contact list is empty\n";
    }
};

int main()
{
    std::string command;
    Phone* phone = new Phone();
    while (command != "exit") {
        std::cout << "Enter command (add, call, sms, exit): ";
        std::cin >> command;
        if (command == "add") {
            phone->add();
        }
        else if (command == "call") {
            phone->call();
        }
        else if (command == "sms") {
            phone->sms();
        }
    }
    delete phone;
    phone = nullptr;
}
