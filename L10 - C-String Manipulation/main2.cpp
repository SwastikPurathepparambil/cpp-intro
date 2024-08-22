#include <iostream>
#include <cctype>

int main() {
    // C-String Manipulation
    
    // length of a string: std::strlen()
    const char message1 [] {"The sky is blue."};
	
	//Array decays into pointer when we use const char*
	const char* message2 {"The sky is blue."};
    std::cout << "message1 : " << message1 << std::endl;
	
	//strlen ignores null character
    // In C, strings (character arrays) are terminated by null character '\0' - character with value zero.
    // this null character is included in the next option when sizeof function is used
    // better to used std::strlen
    std::cout << "strlen(message1) : " << std::strlen(message1) << std::endl;
	
	// Includes the null character
    std::cout << "sizeof(message1) : " << sizeof(message1) << std::endl;
	
	//strlen still works with decayed arrays
    // This is weird because it reads as "length of the address of message2"
    // but std::strlen is kinda just like that ig
	std::cout << "strlen(message2) : " << std::strlen(message2) << std::endl;
	
	//Prints size of pointer
    std::cout << "sizeof(message2) : " << sizeof(message2) << std::endl;

    // String Comparison --> std::strcmp() or std::strncmp()
    // Returns negative if first parameter is before second parameter 
    // in lexicographical order
    // Returns 0 if first parameter is same as second parameter 
    // Returns positive if first parameter is after second parameter 
    // in lexicographical order
    // std::strncmp() allows you to choose how many characters you want to compare
    // each of the character arrays by
    std::cout << std::endl;
    std::cout << "std::strcmp : " << std::endl;
    const char* string_data1{ "Alabama" };
    const char* string_data2{ "Blabama" };

    char string_data3[]{ "Alabama" };
    char string_data4[]{ "Blabama" };

    //Print out the comparison
    std::cout << "std::strcmp (" << string_data1 << "," << string_data2 << ") : "
        << std::strcmp(string_data1, string_data2) << std::endl;

    std::cout << "std::strcmp (" << string_data3 << "," << string_data4 << ") : "
        << std::strcmp(string_data3, string_data4) << std::endl;

    // Wait a sec, why is the string_data not returning an address?

    std::cout << "---------------" << std::endl;
    std::cout << "String Data 1: " << string_data1 << std::endl;
    std::cout << "String Data 2: " << string_data2 << std::endl;
    string_data1 = "yes";
    string_data2 = "bes";
    std::cout << "String Data 1: " << string_data1 << std::endl;
    std::cout << "String Data 2: " << string_data2 << std::endl;

    // Ohhh, this is why. When we go back to the pointers lesson
    // we realize that character arrays and characters are special
    // Printing out the value of a character (string_data_1) array pointer 
    // just returns a String put together of all the characters, while 
    // using regualar pointer notation *string_data_1 gives the first 
    // character of the character array
    // This is information from Pointers: Pointer to Char
    // My compiler allows this to work, but it should be noted that some
    // compilers do not allow this

    // Moving on
    // const char* string_data1{ "Alabama" };
    // const char* string_data2{ "Blabama" };
    size_t n{3};
    std::cout << std::endl;
    std::cout << "std::strncmp : " << std::endl;
    std::cout << "std::strncmp (" << string_data1 << "," << string_data2 << "," << n << ") : " 
              << std::strncmp(string_data1,string_data2,n) << std::endl;

    string_data1 = "aaaia";
    string_data2 = "aaance";
    
    std::cout << "std::strncmp (" << string_data1 << "," << string_data2 << "," << n << ") : " 
              << std::strncmp(string_data1,string_data2,n) << std::endl;

    // wait a sec, string_data_1, which is a pointer, is being assigned a string value
    // why is that allowed?


    // std::strchr finds first instance of a character
    const char* str{ "Try not. Do, or do not. There is no try." };
	char target = 'o';
	const char* result{ nullptr };
	size_t iterations{};


	while ((result = std::strchr(str, target)) != nullptr) {
		std::cout << "Found '" << target
			<< "' starting at '" << result << "'\n";

		// Increment result, otherwise we'll find target at the same location
		++str; // Making the pointer point to the next character
		++iterations;
	}
	std::cout << "iterations : " << iterations << std::endl;

    //Find last occurence
	//CODE STOLEN FROM THE DOCS : 
    std::cout << std::endl;
    std::cout << "std::strrchr : " << std::endl;
	//doc : https://en.cppreference.com/w/cpp/string/byte/strrchr
	
    char input[] = "/home/user/hello.cpp";
    char* output = std::strrchr(input, '/');
    if(output)
        std::cout << output+1 << std::endl; //+1 because we want to start printing past 
                                            // the character found by std::strrchr.


    //Concatenation
    //doc : https://en.cppreference.com/w/cpp/string/byte/strcat

	std::cout << std::endl;
	std::cout<< "std::strcat : " << std::endl;
	//doc : https://en.cppreference.com/w/cpp/string/byte/strcat
	
	char dest[50] = "Hello ";
    char src[50] = "World!";
    std::strcat(dest, src); // Some compilers (MSVC) think these functions are unsafe!
    std::cout << "dest : " << dest << std::endl; // Hello World
    std::strcat(dest, " Goodbye World!"); 
    std::cout << "dest : " << dest << std::endl; // Hello World Goodbye World!
    


	//More concatenation
    
	std::cout << std::endl;
	std::cout << "More std::strcat : " << std::endl;
	
    char *dest1 = new char[30]{'F','i','r','e','l','o','r','d','\0'};
    char *source1 = 
        new char[30]{',','T','h','e',' ','P','h','o','e','n','i','x',' ','K','i','n','g','!','\0'};
		
	//NOTE TO SELF : 
			//Describe what's going to happen in std::strcat before you do the cat :
			//source is going to be appended to dest, and the process
			//will start by overriding the null character in dest
			
    std::cout << "std::strlen(dest1) :" << std::strlen(dest1) << std::endl;
    std::cout << "std::strlen(source1) : " << std::strlen(source1) << std::endl;
    
	std::cout << "Concatenating..." << std::endl;
    std::strcat(dest1,source1);
    
    std::cout << "std::strlen(dest1) :" << std::strlen(dest1) << std::endl;
    std::cout << "dest1 : " << dest1 << std::endl;
    


    //std::strncat  : concatenates n characters from src to dest and
	//returns a pointer to the result string
    //signature : char *strncat( char *dest, const char *src, std::size_t count );
    
    std::cout << std::endl;
    std::cout << "std::strncat:" << std::endl;
    char dest2[50] { "Hello" };
    
    char source2[30] = {" There is a bird on my window"};
    
    //You can even use the returned pointer immediately for print out
    //This is a pattern you'll see a lot in C++ code out there.
    std::cout << std::strncat(dest2,source2,6) << std::endl;
    
    //Or you can do std::strncat separately and print dest2
    std::strncat(dest2,source2,6);
    std::cout << "The concatenated string is : " << dest2 << std::endl;
    


    //std::strcpy - signature : char* strcpy( char* dest, const char* src );
    
    std::cout << std::endl;
	std::cout << "std::strcpy : " << std::endl;
    const char* source3 = "C++ is a multipurpose programming language.";
    char *dest3 = new char[std::strlen(source3) + 1];// +1 for the null character
													//Contains garbage data
													//Not initialized
													
    std::strcpy(dest3,source3);
    
    std::cout << "sizeof(dest3) : " << sizeof(dest3) << std::endl;
    std::cout << "std::strlen(dest3) : " << std::strlen(dest3) << std::endl;
    std::cout << "dest3 : " << dest3 << std::endl;
    


    //std::strncpy : Copy n characters from src to dest -
    //signature : char *strncpy( char *dest, const char *src, std::size_t count );
	std::cout << std::endl;
    std::cout << "std::strncpy:" << std::endl;
    const char* source4 = "Hello";
    char dest4[] = {'a', 'b', 'c', 'd', 'e', 'f','\0'}; // Have to put the terminating
														//null char if we want to print
    
    std::cout << "dest4 : " << dest4 << std::endl;
    
	std::cout << "Copying..." << std::endl;
    std::strncpy(dest4,source4,5);
    
    std::cout << "dest4 : " << dest4 << std::endl;
}