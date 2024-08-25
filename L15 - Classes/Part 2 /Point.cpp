#ifndef CAT_CPP
#define CAT_CPP
#include <iostream>
using namespace std;

// Structs: 
// By default everything is public, but
// can set things to be private as well
// BESIDES THAT, classes and structs are
// IDENTICAL
struct Point{
    public: 
        double x;
        double y;
    
        double calc_volume() {
            return x*y*z;
        }
    
    private:
        double z = 10;
};

void print_point(const Point& point){
    std::cout << "Point [ x: " << point.x << ", y : " << point.y << "]" << std::endl;
}

#endif