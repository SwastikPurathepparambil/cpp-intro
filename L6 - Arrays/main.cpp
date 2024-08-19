#include <iostream>
#include <cmath>

int main() {

    //Arrays
    int scores[10];
    for (size_t i = 0; i < 3; i++) {
        scores[i] = i*2;
    }

    std::cout << "Scores: " << scores << std::endl;

    for (size_t i = 0; i < 3; i++) {
        std::cout << scores[i] << std::endl;
    }

    // initialize and assign
    int scores2[4] = {1, 4, 9}; // will have two more zeros at the end
    int scores3[] = {1, 4, 9}; // will not have two more zeros

    
    // Range-based for loop: Hella goated
    for (auto val: scores2) {
        std::cout << "Sqrt:" << sqrt(val) << std::endl;
    }

    // const int scores3[] = {1, 4, 5};
    // scores3[2] = 0; --> ERROR because list is const
    int count = 4;
    for (int i = 0; i < std::size(scores2); i++) {
        std::cout << "Using std::size for lenght of array: " << i << std::endl;
    }

    // Character Arrays:
    // These are special because you can print them out straight up without loops.
    // Need to have the "\0" so compiler knows when the thing terminates if length of list 
    // isn't specified

    char message1 [] {'H','e','l','l','o','\0'};
    std::cout << "message1 : " << message1 << std::endl;
    std::cout << "sizeof(message1) : " << sizeof(message1) << std::endl;

    // If length of list is longer than current number of char in list
    // then it will also work. Sometimes compiler will also make it work regardless
    char message2 [6] {'H','e','l','l','o'};
    std::cout << "message2 : " << message2 << std::endl;
    std::cout << "sizeof(message2) : " << sizeof(message2) << std::endl;

    char message3 [5] {'H','e','l','l','o'};
    std::cout << "message3 : " << message3 << std::endl;
    std::cout << "sizeof(message3) : " << sizeof(message3) << std::endl;

    // Wackiest thing about arrays in C++
    // Accessing values outside of the bounds of an array does NOT cause an error
    // This does give a warning though, but in many cases, the warning probably
    // will not show up. WATCH OUT FOR ARRAY BOUNDS
    int numberlist[] = {1, 5, 3, 21, 9, 4};
    std::cout << "Num List : " << numberlist[7] << std::endl;


    return 0;
}