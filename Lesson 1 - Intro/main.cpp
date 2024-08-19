#include <iostream> // <-- this is a standard library
#include <string>
/*
STL (Standard Template Library) is a highly 
specialized type of standard libraries that has 
classes, algorithms, and other functions that 
can be used 

Core Features: 
Containers - Data structures designed to efficiently 
store information across a variety of generic types.

Iterators - Methods by which to traverse/access 
the data within the containers.

Algorithms - Basic algorithmic capabilities, such as
sort, find, max, min, replace.
*/

/*

How to Comment: Like this

*/

// Or this

// Functions
int addNums(int n1, int n2) {
    return n1+n2;
}

int main() {
    int num1 = 10;
    int num2 = 20;
    int sum = num1+num2;
    
    // Statements
    // using these curly braces are highkey useless
    int abc1 = 20;
    int abc2 = 30;

    //std::string is the type that defines strings
    std::string name;
    std::string age;

    // This creates a Runtime Error (warnings) --> int value = 7/0;

    // Printing to Terminal
    std::cout << "Num1: " << num1 << std::endl;
    std::cout << "Num2: " << num2 << std::endl;
    std::cout << "Sum: " << sum << std::endl;

    // Function Call
    std::cout << "Sum: " << addNums(1, 20) << std::endl;
    std::cout << "Sum: " << addNums(abc1, abc2) << std::endl;

    std::cout << "Type your name and age : " << std::endl;
    // Use getline to accomodate for words that have spaces
    std::getline(std::cin, name);
    std::cin >> age;

    std::cout << "Name: " << name << ", Age: " << age << std::endl;

    // Error and Log Messages
    std::cerr << "Something is seriously wrong here" << std::endl;
    std::clog << "Log Stuff" << std::endl;

    
    // std::getline DOES NOT WORK for two variables 
    int age2;
    std::string name2;
    std::cin >> age2 >> name2;
    std::cout << "Name: " << name2 << ", Age: " << age2 << std::endl;


    return 0;
}


