#include <iostream>
#include "cylinder.cpp"
using namespace std;

int main() {
    
    Cylinder cyl;
    Cylinder cyl1(4, 7);
    cout << "Volume of cyl: " << cyl.volume() << endl;
    cout << "Volume of cyl1: " << cyl1.volume() << endl;
    cout << "=======" << endl;
    cout << "Radius of cyl: " << cyl.get_radius() << endl;
    cout << "Height of cyl1: " << cyl1.get_height() << endl;
    


    return 0;
}
