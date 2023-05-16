#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    const int indF = 5;
    int numberMin = 0;
    int arr[indF][indF];
    int sumElement = 0;
    struct tm buf;
    time_t t = time(NULL);
    localtime_s(&buf, &t);
    for (int i = 0; i < indF; i++) {
        for (int j = 0; j < indF; j++) {
            arr[i][j] = numberMin + j;
        }
        numberMin++;
    }
    for (int i = 0; i < indF; i++) {
        for (int j = 0; j < indF; j++) {
            cout << arr[i][j] << " ";
            if (i == buf.tm_mday % indF)
                sumElement += arr[i][j];
        }
        cout << endl;
    }
    cout << "Sum of elements " << buf.tm_mday % indF << " line: " << sumElement << endl;
    return 0;
}