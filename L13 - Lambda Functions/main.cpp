#include <iostream>



int main(){
    /*
    Lambda function signature : 
                                [capture list] (parameters) ->return type{
                                        // Function body
                                }
    */

    //Declaring a lambda function and calling it through a name
    /*
    auto func = [](){
        std::cout << "Hello World!" << std::endl;
    };
    func();
    */


    //Declare a lambda function and call it directly
    /*
    [](){
       std::cout << "Hello World!" << std::endl;
    }();
    */


    //Lambda function that takes parameters

    /*
    [](double a, double b){
       std::cout << "a + b : " << (a + b)  << std::endl;
    }(10.0,50.0);
    */

   /*
    auto func1 = [](double a, double b){
       std::cout << "a + b : " << (a + b)  << std::endl;
    };

    func1(10,20);
    func1(5,7);
    */


    //Lambda function that returns something
    /*
    auto result = [](double a, double b){
        return a + b;
    }(10,60);

    //std::cout << "result : " << result << std::endl;
    std::cout << "result : " << [](double a, double b){
        return a + b;
    }(10,60) << std::endl;
    */

    //Explicitly specify the return type
    auto func3 = [](double a, double b)-> int{
        return a + b;
    };

    auto func4 = [](double a, double b){
        return a + b;
    };

    double a{6.9};
    double b{3.5};

    auto result3 = func3(a,b);
    auto result4 = func4(a,b);

    std::cout << "result3 : " << result3 << std::endl;
    std::cout << "result4 : " << result4 << std::endl;
    
    // Capture Lists: Store variables from outisde the lambda fxn
    // lambda fxns by itself can't use variables outside the lambda
    // unless provided by the capture list

    //Capturing by value
    
    int c{42};
     
    auto func = [c](){
        std::cout << "Inner value : " << c << " &inner : " <<&c <<  std::endl;
    };
     
    for(size_t i{} ; i < 2 ;++i){
        std::cout << "Outer value : " << c << " &outer : " << &c << std::endl;
        func();
        ++c;
    }

    std::cout << "========" << std::endl;

    //Capture by reference
    int c1{42};
     
    auto func1 = [&c1](){
        std::cout << "Inner value : " << c1 << " &inner : " <<&c1 <<  std::endl;
    };
     
    for(size_t i{} ; i < 2 ;++i){
        std::cout << "Outer value : " << c << " &outer : " << &c1 << std::endl;
        func1();
        ++c1;
    }

    //Capture everything by value
    std::cout << "========" << std::endl;
    int c2{42};
     
    auto func2 = [=](){
        std::cout << "Inner value : " << c2 << std::endl;
    };
     
    for(size_t i{} ; i < 2 ;++i){
        std::cout << "Outer value : " << c2 << std::endl;
        func2();
        ++c2;
    }
     

    std::cout << "========" << std::endl;
    //Capturing all reference --> all changes within lambda change outside stuff too
    int c3{42};
    int d{5};
     
    auto func5 = [&](){
        std::cout << "Inner value : " << c3 << std::endl;
        std::cout << "Inner value(d) : " << d << std::endl;
    };
     
    for(size_t i{} ; i < 2 ;++i){
        std::cout << "Outer value : " << c3 << std::endl;
        func5();
        ++c3;
    }
   
    return 0;
}