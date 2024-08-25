#include <iostream>
#include "cylinder.cpp"
using namespace std;

int main() {
    
    Cylinder cyl;
    Cylinder cyl1(4, 7, 10);
    cout << "Volume of cyl: " << cyl.volume() << endl;
    cout << "Volume of cyl1: " << cyl1.volume() << endl;
    cout << "=======" << endl;
    cout << "Radius of cyl: " << cyl.get_radius() << endl;
    cout << "Height of cyl1: " << cyl1.get_height() << endl;
    cout << "=======" << endl;
    // Pointer Method (using dereference)
    Cylinder*cyl2 = &cyl1;
    cout << "Method 1: Volume of cyl1 through cyl2: " << (*cyl2).volume() << endl;
    // OR (using "->"  notation)
    cout << "Method 2: Volume of cyl1 through cyl2: " << cyl2->volume() << endl;
    
    Cylinder*cyl3 = new Cylinder(20,17, 10);
    cout << "Height of cyl3: " << cyl3->get_height() << endl;
    // Need to release memory
    delete cyl3;

    // Notice how the desctructor is called after everything is over
    // for all the different classes that were created
    return 0;
}
