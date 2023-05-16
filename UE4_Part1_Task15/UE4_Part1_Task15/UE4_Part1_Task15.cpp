#include <iostream>

void OddOrNot(int numbMax, bool isOdd) {
    const int b = numbMax;
    for (int i = isOdd ? 0 : 1; i <= b; i += 2) {
        std::cout << i << " ";
    }
}

int main()
{
    int N;
    bool pick;
    std::cout << "Enter max number for Search: ";
    std::cin >> N;
    std::cout << "Enter true (for even search) / false (for odd search): ";
    std::cin >> std::boolalpha;
    std::cin >> pick;
    OddOrNot(N, pick);
    return 0;
}