#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "Hello World";
    cout << "Variable value: " << str << endl;
    cout << "Lenght string: " << str.length() << endl;
    cout << "First symbol str: " << str[0] << endl;
    cout << "Last symbol str: " << str[str.length() - 1] << endl;
    return 0;
}