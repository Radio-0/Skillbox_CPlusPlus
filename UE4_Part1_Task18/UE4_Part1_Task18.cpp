#include <iostream>
#include <string>

using namespace std;

class Person {
    string name = "";
    int points = 0;
public:
    void setName(string inName) {
        name = inName;
    }
    void setPoint(int inPoint) {
        points = inPoint;
    }
    string getName() {
        return name;
    }
    int getPoint() {
        return points;
    }
};

int main()
{    
    int sizeArr = 0;
    string nameGamer;
    int pointGamer;
    cout << "How many players to add?\n";
    cin >> sizeArr;
    Person* person = new Person[sizeArr];
    cout << "Enter name and points gamers: \n";
    for (int i = 0; i < sizeArr; i++) {
        cout << i + 1 << ":";        
        cin >> nameGamer >> pointGamer;
        person[i].setName(nameGamer);
        person[i].setPoint(pointGamer);
    }
    for (int i = 0; i < sizeArr - 1; i++) {
        for (int j = 0; j < sizeArr - 1; j++) {
            Person tmp;
            string nameTmp;
            if (person[j].getPoint() > person[j + 1].getPoint()) {
                tmp = person[j];
                person[j] = person[j + 1];
                person[j + 1] = tmp;
            }
        }
    }
    cout << "Show table Gamers:\n";
    for (int i = 0; i < sizeArr; i++) {
        cout << person[i].getName() << " " << person[i].getPoint() << endl;
    }
    delete[]person;
    return 0;
}