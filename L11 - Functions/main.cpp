#include <iostream>
#include "operations.cpp"

//Function that takes a single parameter, and doesn't 
//give back the result explicitly
void enter_bar(size_t age){ // Functions parameters
    if( age > 18){
        std::cout << "You're " << age << " years old. Please proceed." << std::endl;
    }else{
        std::cout << "Sorry, you're too young for this. No offense! " << std::endl;
    }
    return ;
}


//Function that takes multiple parameters and returns the result of the computation
int max( int a, int b){
    if(a>b)
        return a;
    else
        return b;
}

//Function that doesnt' take parameters and returns nothing
void say_hello(){
    std::cout << "Hello there" << std::endl;
    return; // You could omit this return statement for functions returning void
}


//Function that takes no parameters and return something
int lucky_number(){
    return 99;
}


//Parameters passed this way are scoped localy in the function.
//Changes to them are not visible outside the function. What we
//have inside the function are actually COPIES of the arguments
//passed to the function.
double increment_multiply( double a ,double b){
	
	std::cout << "Inside function , before increment : " << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
    
    double result = ((++a)  * (++b));
    
	std::cout << "Inside function , after increment : " << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
    
    //Returning the result
    return result;
}

void say_age(int* age){ // Parameter
    ++(*age); 
    std::cout <<  "Hello , you are " << *age << " years old! &age : " << &age <<  std::endl;//24
}

void say_age2(int& age){ // Parameter
    ++age; 
    std::cout <<  "Hello , you are " << age << " years old! &age : " << &age <<  std::endl;//24

}

int main(){
    // Calling enter_bar
    enter_bar(22); // Function arguments
    
    //Calling lucy_number
    
    int result{};
    result = lucky_number();
    std::cout << "result : " << result << std::endl;

    double h{3.00};
    double i{4.00};
							
	std::cout << "Outside function , before increment : " << std::endl;
	std::cout << "h : " << h << std::endl;
	std::cout << "i : " << i << std::endl;
    
    double incr_mult_result = increment_multiply(h,i);
    
	std::cout << "Outside function , before increment : " << std::endl;
	std::cout << "h : " << h << std::endl;
	std::cout << "i : " << i << std::endl;

    int a = 5;
    int b = 7;
    // incr_mult definiton comes from operations.cpp
    int res = incr_mult(a,b);
    std::cout << "--------------" << std::endl;
    std::cout << "Result of incr_mult(a,b): " << res << std::endl;


    // Pass by Value vs. Pointer vs. Reference
    // Pass by Value is what we've been doing already
    
    // Pass by Pointer 
    int age{23}; // Local
    std::cout << "age (before call) : " << age << "&age : " << &age << std::endl; //23
    say_age(&age); // Argument
    std::cout << "age (after call) : " << age << "&age : " << &age <<  std::endl; //24
    // Notice how the age variable outside the function also changes value


    std::cout << "====================" << std::endl;
    // Pass by Reference
    int age2{23}; // Local
    std::cout << "age (before call) : " << age2 << "&age : " << &age2 << std::endl; //23
    say_age2(age2); // Argument
    std::cout << "age (after call) : " << age2 << "&age : " << &age2 <<  std::endl; //24
    // Similar to pointer, age variable outside also changes

    // Sometimes the Compiler itself optimizes pass by value to pass by reference
    // this is because you need to create a copy of the value for pass by value
    // while you do not for pass by reference. Don't need to ever worry about this though
  
    return 0;
}