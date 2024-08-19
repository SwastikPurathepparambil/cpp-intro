#include <iostream>
#include <ios>
#include <iomanip>
#include <cmath>

int main() {

    int sum = 0+1+4;
    int diff = 0-1-4;
    int mult = 4*4*7;
    int div1 = 5/2;
    double div2 = 5/2.3;
    int mod = 7 % 4;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Diff: " << diff << std::endl;
    std::cout << "Mult: " << mult << std::endl;
    std::cout << "Div1: " << div1 << std::endl;
    std::cout << "Div2: " << div2 << std::endl;
    std::cout << "Remainder: " << mod << std::endl;
    
    // C++ follows PEMDAS
    // C++ operator precedence: https://en.cppreference.com/w/cpp/language/operator_precedence

    // Prefix and Postfix
    // Prefix increments/decrements before the line is fully done
    // Postfix increments/decrements after the line completes
    int value = 5;
    
    std::cout << "The value is (incrementing) : " << value++ << std::endl; // 5
    std::cout << "The value is : " << value << std::endl; // 6

    value = 5;
    
    ++value;
    std::cout << "The value is (prefix++) : " << value << std::endl; // 6
    
    //Reset value to 5
    value = 5;
    std::cout << "The value is (prefix++ in place) : " << ++value << std::endl; // 6

    int n1 = 10;
    // Compound Operators
    n1 += 10; // n1 = 20 now
    n1 -= 5;  // n1 = 15
    n1 *= 2; // n1 = 30
    n1 /= 6; // n1 = 5
    n1 %= 2; // n1 = 1

    std::cout << "The value of n1: " << n1 << std::endl; // 1    

    // Relational Operators
    int number1 = 20;
    int number2 = 20;
    int number3 = 25;

    std::cout << std::boolalpha ; // Make bool show up as true/false instead of 1/0
	//NEED parentheses
    std::cout << "number1 < number2 : " << (number1 < number2) << std::endl;
	std::cout << "number1 <= number2 : " << (number1 <= number2) << std::endl;
    std::cout << "number1 > number2 : " << (number1 > number2) << std::endl;
    std::cout << "number1 >= number2 : " << (number1 >= number2) << std::endl;
    std::cout << "number1 == number2 : " << (number1 == number2) << std::endl;
    std::cout << "number1 != number2 : " << (number1 != number2) << std::endl;

    // Logical Operators:
    // &: and operators
    // ||: or operator
    // !: not operator
    bool a =true;
    bool b =false;
    bool c =true;

    std::cout << "!(a &&b) || c : " << (!(a &&b) || c) << std::endl; // true

    int d = 45;
	int e = 20;
	int f = 11;

    std::cout << "(d > e) && (d > f) : " << ((d > e) && (d > f)) << std::endl; // true

    // Output Formatting
    // References: https://en.cppreference.com/w/cpp/io/manip
    std::cout << "Unformatted table : " << std::endl;
    std::cout << "Daniel" << " " << "Gray" << " 25" << std::endl;
    std::cout << "Stanley" <<" "  << "Woods" << " 33" << std::endl;
    std::cout << "Jordan" << " "  << "Parker" << " 45" << std::endl;
    std::cout << "Joe" << " " << "Ball" << " 21" << std::endl;
    std::cout << "Josh" << " " << "Carr" << " 27" << std::endl;
    std::cout << "Izaiah" << " " << "Robinson" << " 29" << std::endl;
    
    std::cout << std::endl;
    std::cout << "Formatted table : " << std::endl;
    
    //std::setw sets up the Tables quite nicely 
    std::cout << std::setw(10) <<  "Lastname"  << std::setw(10) << "Firstname" << std::setw(5) << "Age" << std::endl;
    std::cout << std::setw(10) << "Daniel"  << std::setw(10) << "Gray" << std::setw(5) << "25" << std::endl;
    std::cout << std::setw(10) << "Stanley" << std::setw(10)  << "Woods" << std::setw(5) <<  "33" << std::endl;
    std::cout << std::setw(10) <<  "Jordan" << std::setw(10)  << "Parker" << std::setw(5) << "45" << std::endl;
    std::cout << std::setw(10) <<  "Joe" << std::setw(10) << "Ball" << std::setw(5) << "21" << std::endl;
    std::cout << std::setw(10) << "Josh" << std::setw(10) << "Carr" << std::setw(5) <<"27" << std::endl;
    std::cout << std::setw(10) << "Izaiah" << std::setw(10) << "Robinson" << std::setw(5) << "29" << std::endl;
    
    // The other formatting optiosn seem pretty whatever, could look back on references if I need to know

    //Math Fxns:
    // https://en.cppreference.com/w/cpp/header/cmath
    // no need to go too much into this
    // std::floor and std::ceil for rounding up or down
    // look at the docs for the rest


    return 0;
}