/*Задание 2. Иерархия геометрических фигур
Спроектируйте иерархию классов различных фигур: круг, квадрат, равносторонний треугольник, прямоугольник (прямоугольный параллелепипед).
Для всех этих фигур есть общие поля-данные — это координаты их центра и условный цвет фигуры: красный, синий или зелёный.
Для отдельных фигур есть и уникальные параметры: радиус — для круга, длина ребра — для квадрата и равностороннего треугольника, ширина и высота для прямоугольника. Все данные — это вещественные числа с удвоенной точностью.
Для каждой из фигур требуется определить метод нахождения площади фигуры, а также метод нахождения прямоугольника, описывающего фигуру полностью (он может быть больше зоны фигуры, но не меньше).
Для лучшего понимания задачи приводится иллюстрация. На ней разными цветами помечены площади фигур, а пунктиром изображены прямоугольники, описывающие фигуры.
Для теста предусмотрите ввод пользователем команд: circle, square, triangle, rectangle, соответствующих фигурам. Команды должны получать параметры фигур и выводить их площадь и описывающий прямоугольник.
Советы и рекомендации
Для цвета фигуры вы можете использовать собственный тип enum, в котором может содержаться и константа отсутствия цвета - None.
Что оценивается
Элегантность выстроенной иерархии классов. Корректность работы методов вычислений для фигур важна, но не столь принципиальна. */

#include <iostream>
#include <string>
#include <cmath>

float pi = 3.14;

class Figure {
    float coordinate[2] = { 0.00, 0.00 };
    enum Color {
        NONE,
        RED,
        BLUE,
        GREEN
    };
public:
    void setCoordinate(float x, float y) {
        coordinate[0] = x;
        coordinate[1] = y;
    }
    float* getCoordinate() {
        return coordinate;
    }
};
class Circle :Figure {
    float radius = 0.00;
public:
    void setRadius() {
        float value;
        std::cout << "Enter radius of circle: ";
        std::cin >> value;
        radius = value;
    }
    void getSquareCircle() {
        setRadius();
        setCoordinate(radius, radius);
        float square = pi * radius * radius;
        std::cout << "Square of circle with radius " << radius << ": " << square << "\n";
        float* coor = getCoordinate();
        std::cout << "Center coordinate: x:" << coor[0] << " y:" << coor[1] << "\n";
    }
    void getDescribSquare() {
        float length;
        std::cout << "Enter length edge of describing the square: ";
        std::cin >> length;
        if (length < (2 * radius)) {
            std::cout << "Error. Incorrect length edge of describing the square.\n";
        }
        else {
            float* coor = getCoordinate();
            std::cout << "Center coordinate of describing the square: x:" << coor[0] << " y:" << coor[1] << "\n";
            float square = length * length;
            std::cout << "Square of describing the square:" << square << "\n";
        }
    }
};
class Square :Figure {
    float lengthEdge = 0.00;
public:
    void setLengthEdgeSquare() {
        float value;
        std::cout << "Enter length edge of square: ";
        std::cin >> value;
        lengthEdge = value;
    }
    void getSquareSquare() {
        setLengthEdgeSquare();
        setCoordinate(lengthEdge / 2, lengthEdge / 2);
        float square = lengthEdge * lengthEdge;
        std::cout << "Square of square with length edge " << lengthEdge << ": " << square << "\n";
        float* coor = getCoordinate();
        std::cout << "Center coordinate: x:" << coor[0] << " y:" << coor[1] << "\n";
    }
    void getDescribSquare() {
        float length;
        std::cout << "Enter length edge of describing the square: ";
        std::cin >> length;
        if (length < lengthEdge) {
            std::cout << "Error. Incorrect length edge of describing the square.\n";
        }
        else {
            float* coor = getCoordinate();
            std::cout << "Center coordinate of describing the square: x:" << coor[0] << " y:" << coor[1] << "\n";
            float square = length * length;
            std::cout << "Square of describing the square:" << square << "\n";
        }
    }
};
class Triangle :Figure {
    float lengthEdge = 0.00;
public:
    void setLengthEdgeTriangle() {
        float value;
        std::cout << "Enter length edge of triangle: ";
        std::cin >> value;
        lengthEdge = value;
    }
    void getSquareTriangle() {
        setLengthEdgeTriangle();
        float coorY = lengthEdge * sqrt(3) / 6;
        float coorX = 2 * coorY;
        setCoordinate(coorX, coorY);
        float square = lengthEdge * lengthEdge * sqrt(3) / 2;
        std::cout << "Square of triangle with length edge " << lengthEdge << ": " << square << "\n";
        float* coor = getCoordinate();
        std::cout << "Center coordinate: x:" << coor[0] << " y:" << coor[1] << "\n";
    }
    void getDescribSquare() {
        float length;
        std::cout << "Enter length edge of describing the square: ";
        std::cin >> length;
        if (length < (lengthEdge * sqrt(3) / 2)) {
            std::cout << "Error. Incorrect length edge of describing the square.\n";
        }
        else {
            float* coor = getCoordinate();
            std::cout << "Center coordinate of describing the square: x:" << coor[0] << " y:" << coor[1] << "\n";
            float square = length * length;
            std::cout << "Square of describing the square:" << square << "\n";
        }
    }
};
class Rectangle :Figure {
    float height = 0.00;
    float width = 0.00;
public:
    void setHeigthRectangle() {
        float value;
        std::cout << "Enter heigth of rectangle: ";
        std::cin >> value;
        height = value;
    }
    void setWidthRectangle() {
        float value;
        std::cout << "Enter width of rectangle: ";
        std::cin >> value;
        width = value;
    }
    void getSquareRectangle() {
        setHeigthRectangle();
        setWidthRectangle();
        setCoordinate(height / 2, width / 2);
        float square = height * width;
        std::cout << "Square of rectangle with height " << height << " and  width " << width << ": " << square << "\n";
        float* coor = getCoordinate();
        std::cout << "Center coordinate: x:" << coor[0] << " y:" << coor[1] << "\n";
    }
    void getDescribSquare() {
        float length;
        std::cout << "Enter length edge of describing the square: ";
        std::cin >> length;
        if (length < height && length < width) {
            std::cout << "Error. Incorrect length edge of describing the square.\n";
        }
        else {
            float* coor = getCoordinate();
            std::cout << "Center coordinate of describing the square: x:" << coor[0] << " y:" << coor[1] << "\n";
            float square = length * length;
            std::cout << "Square of describing the square:" << square << "\n";
        }
    }
};

int main() {
    std::string command;
    Circle* circle = new Circle();
    Square* square = new Square();
    Triangle* triangle = new Triangle();
    Rectangle* rectangle = new Rectangle();
    while (command != "exit") {
        std::cout << "Enter figure (circle, square, triangle, rectangle or exit):";
        std::cin >> command;
        if (command == "circle") {
            circle->getSquareCircle();
            circle->getDescribSquare();
        }
        else if (command == "square") {
            square->getSquareSquare();
            square->getDescribSquare();
        }
        else if (command == "triangle") {
            triangle->getSquareTriangle();
            triangle->getDescribSquare();
        }
        else if (command == "rectangle") {
            rectangle->getSquareRectangle();
            rectangle->getDescribSquare();
        }
    }
    return 0;
}