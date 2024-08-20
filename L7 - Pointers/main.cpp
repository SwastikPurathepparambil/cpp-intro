#include <iostream>

int main() {
    
    // Pointers
    // variables that store addresses of other variables
    int int_var = 43;
    int*p_var = &int_var; // & denotes the address of int_var variable

    int int_var1 = 124;
    p_var = &int_var1;
    // Pointers only store the type for which it was declared

    int*null_pointer_var {}; //initializes a nullptr pointer

    // VERY IMPORTANT: Dereferencing a pointer: aka reading the value that an address stores
    int*p_int2 {};
    int int_data = 56;
    p_int2 = &int_data;

    std::cout << "int_data: " << *p_int2 << std::endl; 

    // Special thing about using characters
    // warning shows up
    // pretty much the string becomes a character array and
    // the pointer refers to the first character of the array
    // might want to explore the power of this
    char*p_message = "Hello World";
    std::cout << "Message: " << p_message << std::endl;
    std::cout << "Value stored: " << *p_message << std::endl;

    // Will want to look again at ***Program Memory Map*** to 
    // understand the low-level of how it works again

    // DEFINITELY DO NOT assingn garbage into an unitialized pointer
    // aka:  int*p_number;
    // cont: *p_number = 55
    // also always intialized null pointers like so:
    int*null_pt_ex {nullptr};
    //  doing *null_pt_ex = 3; is also bad because you 
    // are writing into a null address, which will crash the code

    
    // Dynamic Memory Allocation
    int*p_num {nullptr};
    p_num = new int; // using "new" stores things within the heap (usually stored in stack)
    *p_num = 18;

    // When done with p_num
    // NEVER DELETE SAME POINTER TWICE
    delete p_num;
    p_num = nullptr;

    // could also do this

    int*p_num2 = new int {23};
    std::cout << "Value stored of p_num2: " << *p_num2 << std::endl;
    delete p_num2;
    p_num2 = nullptr;//good practice to set p_num2 to nullptr

    // however, can reuse pointer
    p_num2 = new int {832};
    std::cout << "Value stored of p_num2: " << *p_num2 << std::endl;
    delete p_num2;
    p_num2 = nullptr;

    // Dangling Pointers
    //Case1 : Uninitialized pointer
	// int*p_number; // Dangling uninitialized pointer
   
	// std::cout << std::endl;
	// std::cout << "Case 1 : Uninitialized pointer : ." << std::endl;
	// std::cout << "p_number : " << p_number << std::endl;
    // std::cout << "*p_number : " << *p_number << std::endl; //CRASH!
    


   //Case 2 : deleted pointer
//    std::cout << std::endl;
//    std::cout << "Case 2 : Deleted pointer" << std::endl;
//    int * p_number1 {new int{67}};
   
//    std::cout << "*p_number1 (before delete) : " << *p_number1 << std::endl;
   
//    delete p_number1;
		
//    std::cout << "*p_number1(after delete) : " << *p_number1 << std::endl;

//Case 3 : Multiple pointers pointing to same address
    
	// std::cout << std::endl;
	// std::cout << "Case 3 : Multiple pointers pointing to same address : " << std::endl;
	
    // int *p_number3 {new int{83}};
    // int *p_number4 {p_number3};
    
    // std::cout << "p_number3 - " << p_number3 << " - " << *p_number3 << std::endl;
    // std::cout << "p_number4 - " << p_number4 << " - " << *p_number4 << std::endl;
    
    // //Deleting p_number3
    // delete p_number3;
    
    // //p_number4 points to deleted memory. Dereferncing it will lead to
	// //undefined behaviour : Crash/ garbage or whatever
    // std::cout<< "p_number4(after deleting p_number3) - " << p_number4 << " - " << *p_number4 << std::endl;
    
    // Solutions to these dangling pointer issues below:
    // https://github.com/rutura/The-C-20-Masterclass-Source-Code/blob/main/13.Pointers/13.16DanglingPointers/main.cpp 

    // new operator can fail if it's too much data being used
    // can use try catch block to catch the error before crash

    for(size_t i{0} ; i < 35090 ; ++i){
        try{
            int * data = new int[1000000000];
        }catch(std::exception& ex){
            std::cout << "  Something went wrong : " << ex.what() << std::endl;
        }
    }

    // Look here for Null Pointer Safety: https://github.com/rutura/The-C-20-Masterclass-Source-Code/blob/main/13.Pointers/13.18NullPointerSafety/main.cpp


    //Memory Leaks: super important
    //Pretty much just check to make sure that each case of a dynamic memory allocation
    // ends up getting deleted

    /*
    int *p_number {new int{67}}; // Points to some address, let's call that address1
    
    //Should delete and reset here 
    
    int number{55}; // stack variable
    
    p_number = &number; // Now p_number points to address2 , but address1 is still in use by 
                        // our program. But our program has lost access to that memory location.
						//Memory has been leaked.
    */

	//Double allocation 
    /*
    int *p_number1 {new int{55}};
    
	//Use the pointer
    
	//Should delete and reset here.
	
    p_number1 = new int{44}; // memory with int{55} leaked.

    delete p_number1;
    p_number1 = nullptr;
    */

	//Nested scopes with dynamically allocated memory
	// {
	// 	int *p_number2 {new int{57}};

    //     //Use the dynamic memory

	// }
	//Memory with int{57} leaked.

    const size_t size{10};
    double *p_salaries { new double[size]}; // salaries array will
															//contain garbage  values
    int *p_students { new(std::nothrow) int[size]{} }; // All values initialized to 0 
    
    double *p_scores { new(std::nothrow) double[size]{1,2,3,4,5}}; // Allocating memory space
																	// for an array  of size double
																	//vars. First 5 will be initialized
																	//with 1,2,3,4,5, and the 
																	//rest will be 0's.


    //nullptr check and use the allocated array
    if(p_scores){
        std::cout << "size of scores (it's a regular pointer) : " << sizeof(p_scores) << std::endl;
        std::cout << "Successfully allocated memory for scores."<< std::endl;
        
        //Print out elements. Can use regular array access notation, or pointer arithmetic
        for( size_t i{}; i < size ; ++i){
           std::cout << "value : " << p_scores[i] << " : " << *(p_scores + i) << std::endl; 
        }
    }

    delete [] p_salaries;
    p_salaries = nullptr;

    delete [] p_students;
    p_students = nullptr;

   delete [] p_scores;
   p_scores = nullptr;

   //Static arrays Vs dynamic arrays
   std::cout << "=====================================" << std::endl;

   int scores[10] {1,2,3,4,5,6,7,8,9,10}; // Lives on the stack

   std::cout << "scores size : " << std::size(scores) << std::endl;
   for( auto s : scores){
       std::cout << "value : " << s << std::endl;
   }

   int* p_scores1 = new int[10] {1,2,3,4,5,6,7,8,9,10}; // Lives on the heap.
   //std::cout << "p_scores1 size : " << std::size(p_scores) << std::endl;
   /*
   for( auto s : p_scores1){
       std::cout << "value : " << s << std::endl;
   }
   */






    return 0;
}
