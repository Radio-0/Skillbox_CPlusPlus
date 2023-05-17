#include <iostream>
#include <math.h>
using namespace std;

class Vector {
    int x, y, z;
public:
    Vector(int inX, int inY, int inZ) {
        x = inX;
        y = inY;
        z = inZ;
    }
    void getX() {
        cout << "X=" << x << endl;
    }
    void getY() {
        cout << "Y=" << y << endl;
    }
    void getZ() {
        cout << "Z=" << z << endl;
    }
    int lenghtVector() {
        int lenght = 0;
        lenght = sqrt(x * x + y * y + z * z);
        return lenght;
    }
};

int main() {
    Vector vector(1, 2, 4);
    vector.getX();
    vector.getY();
    vector.getZ();
    cout << "Vector length: " << vector.lenghtVector();
    return 0;
}