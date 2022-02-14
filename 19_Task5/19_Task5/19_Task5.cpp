// 19_Task5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    setlocale(LC_ALL, "Russian");
    std::ifstream qFile("..\\question.txt");
    std::ifstream aFile("..\\answer.txt");
    
    int offset, sector = 0;
    bool sectors[13];
    int nExperts = 0, nViewer = 0;

    for (int i = 0; i < 13; i++) {
        sectors[i] = true;
    }

    if (!qFile || !aFile) {
        std::cout << "Files is NOT open.";
        return 1;
    }

    while (true) {
        std::cout << "Enter sector`s offset: ";
        std::cin >> offset;
        offset--;

        if (offset < 0 || offset > 12) {
            std::cout << "Error offset\n";
            continue;
        }

        sector += offset;

        while (!sectors[sector]) {
            sector++;
            if (sector > 12) sector %= 13;
        }

        if (sector > 12) sector %= 13;

        std::cout << sector;
        std::string question;
        std::string answer;

        for (int i = 0; i <= sector; i++) {
            std::getline(qFile, question);
            std::getline(aFile, answer);
        }

        std::cout << question << std::endl;
        std::cout << "Enter answer: ";
        std::string aExpert;
        std::cin >> aExpert;

        if (aExpert == answer) {
            std::cout << "Experts are right. The point goes to them.\n";
            nExperts++;
        }
        else {
            std::cout << "Experts are wrong. The point goes to TV viewers.\n";
            std::cout << "Correct answer: " << answer << "\n";
            nViewer++;
        }

        qFile.seekg(std::ios::beg);
        aFile.seekg(std::ios::beg);
     
        if (nExperts == 6) {
            std::cout << "Experts won with a point of " << nExperts << ":" << nViewer;
            break;
        }
        if (nViewer == 6) {
            std::cout << "Viewers won with a point of " << nViewer << ":" << nExperts;
            break;
        }   
    }

    qFile.close();
    aFile.close();
    return 0;
}