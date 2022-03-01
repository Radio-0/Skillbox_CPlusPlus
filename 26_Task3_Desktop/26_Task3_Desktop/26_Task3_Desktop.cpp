/*Задание 3. Реализация программы управления окном рабочего стола
Реализуйте симуляцию работы окна в визуальном интерфейсе пользователя.
Окно располагается на виртуальном экране монитора, размером 80 × 50 точек.У окна есть несколько параметров, которые также задаются в пикселях : двумерные координаты левого верхнего угла и размеры, ширина и высота.Ширина и высота при этом не могут быть отрицательными, а координаты не могут выходить за область экрана.
Пользователь взаимодействует с программой с помощью команд :
Команда move принимает вектор, на который надо сместить окно на экране.Сообщение с новыми координатами окна появляется на экране.
Команда resize запрашивает из стандартного ввода новый размер окна.После изменения размера сообщение с новым размером выводится на экране.
Команда display выводит текущее изображение монитора в консоль. 0 — это пиксель вне области окна, 1 — с окном.
Команда close закрывает окно, выход из программы.
Советы и рекомендации
Сам экран монитора вы тоже можете реализовать с помощью класса.*/

#include <iostream>
#include <string>
#include <vector>

class Window {
    int widthW = 80;
    int heightW = 50;
    std::vector<int> coordinate = {0,0};
public:
    int getWidthW() {
        return widthW;
    }
    int getHeightW() {
        return heightW;
    }
    std::vector<int> getCoordinate() {
        return coordinate;
    }
    void setCoordinate(std::vector<int> coor) {
        for (int i = 0; i < 2; i++) {
            coordinate[i] += coor[i];
        }
        if (coordinate[0] < 0 || coordinate[0] > 80) coordinate[0] = 0;
        if (coordinate[1] < 0 || coordinate[1] > 50) coordinate[1] = 0;
        std::cout << "New coordinates: " << coordinate[0] << " " << coordinate[1] << "\n";
    }
    void setSize(int width, int height) {
        widthW = width;
        heightW = height;
    }
    void move(std::vector<int> coor) {
        setCoordinate(coor);
    }
    void resize() {
        int width, height;
        std::cout << "Enter new window size: \n";
        std::cout << "New width: ";
        std::cin >> width;
        if (width > 80 || width < 0) width = 80;
        std::cout << "New height: ";
        std::cin >> height;
        if (height > 50 || height < 0) height = 50;
        setSize(width, height);
        std::cout << "New window size: width = " << getWidthW() << " height = " << getHeightW() << "\n";
    }
};

class Screen {
    static const int widthS = 80;
    static const int heightS = 50;
public:
    void display(std::vector<int> coor, int width, int height) {
        int desktop[heightS][widthS] = {};
        if (width != 0 && height != 0) {
            for (int i = coor[1]; i < (coor[1] + height); i++) {
                for (int j = coor[0]; j < (coor[0] + width); j++) {
                    desktop[i][j] = 1;
                }
            }
        }
        for (int i = 0; i < 50; i++) {
            std::cout << "\n";
            for (int j = 0; j < 80; j++) {
                std::cout << desktop[i][j];
            }
        }
        std::cout << "\n";
    }
};

int main()
{
    std::string command;
    Window* window = new Window();
    Screen* screen = new Screen();
    while (command != "close") {
        std::cout << "Enter command (move, resize, display, close):";
        std::cin >> command;
        if (command == "move") {
            std::vector<int> coordinate;
            int x, y;
            std::cout << "x:";
            std::cin >> x;
            std::cout << "y:";
            std::cin >> y;
            coordinate = { x, y };
            window->move(coordinate);
        }
        else if (command == "resize") {
            window->resize();
        }
        else if (command == "display") {
            screen->display(window->getCoordinate(), window->getWidthW(), window->getHeightW());
        }
    }
    delete screen;
    screen = nullptr;
    delete window;
    window = nullptr;
}