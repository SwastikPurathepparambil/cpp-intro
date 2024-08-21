#include <iostream>

int main() {
    
    // References: they are sorta like Naruto Shadow Clones (well not really)
    // these clones, however, change the original as well
    // if references or original are changed, both will end up changing
    // pretty much pointers that can't point somewhere else (aka const pointers)

    double double_value {12.34};
    double& ref_double_value {double_value}; // Reference to double_value
    double* p_double_value {&double_value}; //Pointer to double_value
	
	//Reading
	std::cout << "double_value : " << double_value << std::endl;
	std::cout << "ref_double_value : " << ref_double_value << std::endl;
	std::cout << "p_double_value : " << p_double_value << std::endl;
	std::cout << "*p_double_value : " << *p_double_value << std::endl;
	
	//Writting through pointer
	*p_double_value = 15.44;
	
    std::cout << std::endl;
	std::cout << "double_value : " << double_value << std::endl;
	std::cout << "ref_double_value : " << ref_double_value << std::endl;
	std::cout << "p_double_value : " << p_double_value << std::endl;
	std::cout << "*p_double_value : " << *p_double_value << std::endl;
	
	//Writting through reference
	ref_double_value = 18.44;
	
    std::cout << std::endl;
	std::cout << "double_value : " << double_value << std::endl;
	std::cout << "ref_double_value : " << ref_double_value << std::endl;
	std::cout << "p_double_value : " << p_double_value << std::endl;
	std::cout << "*p_double_value : " << *p_double_value << std::endl;


    double some_other_double{78.45};

    //Make the reference reference something else.
    ref_double_value = some_other_double;

    std::cout << "Making the reference reference something else..." << std::endl;
    std::cout << std::endl;
	std::cout << "double_value : " << double_value << std::endl;
	std::cout << "ref_double_value : " << ref_double_value << std::endl;
	std::cout << "p_double_value : " << p_double_value << std::endl;
	std::cout << "*p_double_value : " << *p_double_value << std::endl;



    //Make the pointer point to something else
    p_double_value = &some_other_double;
    std::cout << "Making the pointer point somewhere else..." << std::endl;
    std::cout << std::endl;
	std::cout << "double_value : " << double_value << std::endl;
	std::cout << "ref_double_value : " << ref_double_value << std::endl;
    std::cout << "&double_value : " << &double_value << std::endl;
    std::cout << "&ref_double_value : " << &ref_double_value << std::endl;
	std::cout << "p_double_value : " << p_double_value << std::endl;
	std::cout << "*p_double_value : " << *p_double_value << std::endl;


    *p_double_value = 555.5;

    std::cout << std::endl;
	std::cout << "double_value : " << double_value << std::endl;
	std::cout << "ref_double_value : " << ref_double_value << std::endl;
    std::cout << "&double_value : " << &double_value << std::endl;
    std::cout << "&ref_double_value : " << &ref_double_value << std::endl;
	std::cout << "p_double_value : " << p_double_value << std::endl;
	std::cout << "*p_double_value : " << *p_double_value << std::endl;


    //cosnt reference is READ-ONLY
    //Non const reference
	std::cout << std::endl;
	std::cout << "Non const reference : " << std::endl;
	int age {27};
	const int& ref_age{age};
	
	std::cout << "age : " << age << std::endl;
    
	std::cout << "ref_age : " << ref_age << std::endl;
	
	
	//Can modify original variable through reference

	std::cout << std::endl;
	std::cout << "Modify original variable through reference : " << std::endl;
	
	// ref_age++; //Error: expression must be a modifiable value
	
	std::cout << "age : " << age << std::endl;
	std::cout << "ref_age : " << ref_age << std::endl;
    

   //Simulating reference behavior with pointers
   //const int * const p_age {&age};
   //*p_age = 45;

    return 0;
}
