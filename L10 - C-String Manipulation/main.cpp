#include <iostream>
#include <cctype>

int main() {
    
    // Character Manipulation and Strings

    // std::isalnum
    char isAlphaNumericNum = 'C';
    char isNotAlphaNumericNum = '^';

    if (std::isalnum(isAlphaNumericNum)) {
        std::cout << "The character C is alphanumeric" << std::endl;
    } else {
        std::cout << "The character C is not alphanumeric" << std::endl;
    }
    
    // Others:
    // Let x be a random character
    // std::isalpha(x) --> checks if character is in alphabet
    // std::isblank(x) --> checks if character is blank
    // std::islower(x) --> checks if character is lowercase
    // std::isupper(x) --> checks if character is uppercase
    // std::isdigit(x) --> checks if character is digit
    // std::toupper(x) --> makes characters uppercase
    // std::tolower(x) --> makes characters lowercase
    
    //Turning a character to lowercase using the std::tolower() function
    std::cout << std::endl;
    std::cout << "std::tolwer and std::toupper: " << std::endl;
    char original_str[] {"Home. The feeling of belonging"};
    char dest_str[std::size(original_str)];
    
    //Turn this to uppercase. Change the array in place
    for(size_t i{}; i < std::size(original_str) ; ++i){
        dest_str[i] = std::toupper(original_str[i]);
    }
    
    std::cout << "Original string : " << original_str << std::endl;
    std::cout << "Uppercase string : " << dest_str << std::endl;
    // remeber, printing out a character array prints it as if it is a string
    // can look back at arrays lesson for this explanation
    
    //Turn this to lowercase. Change the array in place
    for(size_t i{}; i < std::size(original_str) ; ++i){
        dest_str[i] = std::tolower(original_str[i]);
    }
    
    std::cout << "Lowercase string : " << dest_str << std::endl; 

    



    return 0;
}
