#include <iostream>
using namespace std;

// Function Templates

// Pass by Value
template <typename T>
T maximum(T x, T y) {
    return (x > y) ? x : y;
}

// Pass by Reference
template <typename T> const T& calc_max(const T& a, const T& b){
    cout << "In - &a: " << &a << endl; // // 0x111abc
    return (a > b ) ? a : b ;
}

template <>
const char * maximum<const char*> (const char* a, const char* b){
    return ( std::strcmp(a,b) > 0) ? a : b;
}

int main() {

    int x = 5;
    int y = 2;
    
    cout << "maximum(int): " << maximum(x, y) << endl;

    double a = 5.3;
    double b = 2.1; 

    cout << "maximum(double): " << maximum(a,b) << endl;

    string c = "yes";
    string d = "no";

    cout << "maximum(string): " << maximum(c,d) << endl; // comparison lexicographically

    int e{10};
	int f{23};
	double g{34.7};
	double h{23.4};
	string i{"hello"};
	string j{"world"};

    // Explicit template arguments
    // Forces type to be double
    // thus can put inputs of different types
    auto max = maximum<double>(e,h);
    cout << "max : " << max << endl;

    cout << "==========" << endl;

    double k {23.5};
    double l {51.2};

    cout << "Out - &a: " << &a << endl; 
    auto result = calc_max(a,b);
    cout << "Out - &a: " << &a << endl; 

    /*
	int a{10};
	int b{23};
	double c{34.7};
	double d{23.4};
	std::string e{"hello"};
	std::string f{"world"};
	
	auto max_int = maximum(a,b); // int type deduced
	auto max_double = maximum(c,d);// double type deduced
	auto max_str = maximum(e,f) ;// string type deduced
	
	std::cout << "max_int : " << max_int << std::endl;
	std::cout << "max_double : " << max_double << std::endl;
	std::cout << "max_str : " << max_str << std::endl;
    */

    //
	const char* u{"wild"};
	const char* v{"animal"};
	
	//This won't do what you would expect : BEWARE!
    cout << "======" << endl;

    const char* res = maximum(u,v);
	cout << "max(const char*) : " << res << endl;

    // ***********
    // Could study Concepts, but not necessary for now, 
    // and can revisit at a later date

    return 0;
}