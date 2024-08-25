#include <iostream>
#include "Dog.cpp"
#include "Point.cpp"
using namespace std;


int main(){

    Dog dog1("Fluffy","Shepherd",2); //Constructor
    dog1.print_info();

    /*
    dog1.set_dog_name("Pumba");
    dog1.set_dog_breed("Wire Fox Terrier");
    dog1.set_dog_age(4);
    */

    //Chained calls using pointers
    //dog1.set_dog_name("Pumba")->set_dog_breed("Wire Fox Terrier")->set_dog_age(4);

    //Chained calls using references
    dog1.set_dog_name("Pumba").set_dog_breed("Wire Fox Terrier").set_dog_age(4);


    dog1.print_info();
   

    Point point1;
    point1.x = 10;
    point1.y = 55.5;

    print_point(point1);
    cout << "Volume of point1: " << point1.calc_volume() << endl;

    cout << "Done!" << endl;
   //Destructor happens here
    return 0;
}

// Size of class is the size of all of its member variables