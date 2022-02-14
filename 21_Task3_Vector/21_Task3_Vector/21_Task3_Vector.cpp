// 21_Task3_Vector.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>

struct vector {
    float x;
    float y;
};

vector add(vector one, vector two) {     //Сложение двух векторов
    vector sum;
    sum.x = one.x + two.x;
    sum.y = one.y + two.y;
    return sum;
}

vector subtract(vector one, vector two) {    //Вычитание двух векторов
    vector sub;
    sub.x = one.x - two.x;
    sub.y = one.y - two.y;
    return sub;
}

float length(vector vec) {  //Нахождение длины вектора
    float len_vec;
    len_vec = sqrt(vec.x * vec.x + vec.y * vec.y);
    return len_vec;
}

float scale(float len, float scal) {   //Умножение вектора на скаляр
    float mult_scale;
    mult_scale = len * scal;
    return mult_scale;
}

vector normalize(vector vec, float len) {   //Нормализация вектора
    float normal = 1 / len;
    vector normal_vec;
    normal_vec.x = vec.x * normal;
    normal_vec.y = vec.x * normal;
    return normal_vec;
}

int main() {
    std::string program;
    vector vec, vec_one, vec_two, result;
    float scalar, len_vec;

    std::cout << "Enter required operation (add, subtract, lenght, scale, normalize): ";
    std::cin >> program;
    if (program == "add") {
        std::cout << "Enter coordinates of first vector: ";
        std::cin >> vec_one.x >> vec_one.y;
        std::cout << "Enter coordinates of second vector: ";
        std::cin >> vec_two.x >> vec_two.y;
        result = add(vec_one, vec_two);
        std::cout << "Sum of vectors: x = " << result.x << " y = " << result.y;
    }
    else if (program == "subtract") {
        std::cout << "Enter coordinates of first vector: ";
        std::cin >> vec_one.x >> vec_one.y;
        std::cout << "Enter coordinates of second vector: ";
        std::cin >> vec_two.x >> vec_two.y;
        result = subtract(vec_one, vec_two);
        std::cout << "Subtraction of vectors: x = " << result.x << " y = " << result.y;
    }
    else if (program == "length") {
        std::cout << "Enter coordinates of vector: ";
        std::cin >> vec.x >> vec.y;
        std::cout << "Vector length: " << length(vec);
    }
    else if (program == "scale") {
        std::cout << "Enter coordinates of vector: ";
        std::cin >> vec.x >> vec.y;
        std::cout << "Enter scalar: ";
        std::cin >> scalar;
        len_vec = length(vec);
        std::cout << "The product of a vector by a scalar: " << scale(len_vec, scalar);
    }
    else if (program == "normalize") {
        std::cout << "Enter coordinates of vector: ";
        std::cin >> vec.x >> vec.y;
        len_vec = length(vec);
        result = normalize(vec, len_vec);
        std::cout << "Coordinates of the normalized vector: x = " << result.x << " y = " << result.y;
    }
    else {
        std::cout << "Error. Wrong command.";
        return -1;
    }
    return 0;
}