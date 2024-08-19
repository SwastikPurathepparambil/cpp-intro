#include <iostream>

int main() {

    // Loops

    // For Loop
    // size_t is unsigned int, which is the positive #s only
    // it is good practice to change hardcoded max length of loop to const
    size_t count = 4;
    for (size_t i = 0; i < count; ++i) {
        if (i%2 == 0) {
            std::cout << i+1 << ": Oh" << std::endl;
        } else {
            std::cout << i+1 << ": Yes" << std::endl;
        }
       
    }

    std::cout << "------------" << std::endl;
    // While Loop
    int i = 0;
    while (i < count) {
        if (i%2 == 0) {
            std::cout << i+1 << ": Oh" << std::endl;
        } else {
            std::cout << i+1 << ": Yes" << std::endl;
        }
        i++;
    }
    std::cout << "------------" << std::endl;
    // Do While Loop
    // MAIN DIFFERENCE, the check for the while is done after the execution
    // This still prints the first "Oh"
    i = 0;
    count = 0;
    do {
        std::cout << "Still prints this text once" << std::endl;
        ++i;
    } while (i<count);
}