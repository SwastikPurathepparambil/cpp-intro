#include <iostream>

int main() {
    
    //Control Flow
    int n = 3;
    int n2 = 2;

    if (n > n2) {
        std::cout << "n > n2" << std::endl;
    } else if (n < n2) {
        std::cout << "n < n2" << std::endl;
    } else {
        std::cout << "n = n2" << std::endl;
    }


    // Switch tool
    const int a = 1;
    const int b = 2;
    const int c = 3;

    int x = 3;

    // different cases of switch MUST be integral or enum
    // i.e: int, long, unsigned short, etc.
    switch (x)
    {
    case (a):
        std::cout << "a" << std::endl;
        break;
    case (b):
        std::cout << "b" << std::endl;
        break;
    case (c):
        std::cout << "c" << std::endl;
        break;

    default:
        std::cout << "default" << std::endl;
        break;
    }

    // Ternary Operators
    int num1 = 4;
    int num2 = 5;
    int result = (num1 > num2) ? 10 : 100;
    std::cout << "result: " << result << std::endl;

    return 0;
}