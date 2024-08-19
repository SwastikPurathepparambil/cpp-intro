#include <iostream>

/*
    ------------------------------------------
    I MOSTLY SKIPPED THROUGH THIS LESSON, WILL WANT TO COME BACK FOR CS 32 LEARNING PURPOSES
    
*/


int main() {

    // Number Systems
    int n1 = 15; // decimal
    int n2 = 017; // octal -- not longer used, but put 0 in front
    int n3 = 0x0F; // hex
    int n4 = 0b00001111; // binary 

    std::cout << "Num1: " << n1 << std::endl;
    std::cout << "Num2: " << n2 << std::endl;
    std::cout << "Num3: " << n3 << std::endl;
    std::cout << "Num4: " << n4 << std::endl;

    int n5 = 2.9; // the int on a double takes only the whole #s
    std::cout << "Num5: " << n5 << std::endl;

    // Braced Assignment -- Does not seem to work on Mac ig
    // int n6 {n5+n1};
    // std::cout << "Num6: " << n6 << std::endl;

    unsigned int n7 = 5; // unsinged int means only positive numbers, //signed is both -/+
    unsigned int n8 = -3; // this should return an error but surprisingly it returns a really large number
    std::cout << "Num7: " << n7 << std::endl;
    std::cout << "Num8: " << n8 << std::endl;

    // more integer modifiers: https://www.programiz.com/cpp-programming/type-modifiers
    // there is short and long, but these felt pretty unimportant

    //Print out the sizes
    std::cout << "sizeof float : " << sizeof(float) << std::endl; 
    std::cout << "sizeof double : " << sizeof(double) << std::endl;
    std::cout << "sizeof long double : " << sizeof(long double) << std::endl;
    //would use the above to represent decimals

    float a_n = 0.1000100000001; // this prints float: 0.10001 because the zeros only go so far as the sizes 
    std::cout << "float: " << a_n << std::endl;
    
    char letter1 = 65;
    std::cout << "Char: " << letter1 << std::endl;
    std::cout << "Char: " << static_cast<int>(letter1) << std::endl;

    // auto DataType --> allows compiler to figure out the type
    auto var1 = 5.0;
    auto var2 = 'A';
    std::cout << "var1: " << var1 << std::endl;
    std::cout << "var2: " << var2 << std::endl;

    return 0;
}