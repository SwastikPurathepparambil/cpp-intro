#ifndef CYLINDER_CPP
#define CYLINDER_CPP

#include <iostream>
#include "constants.cpp"
using namespace std;

class Cylinder {

    // All functions assumed as private
    // Usually want to keep Class variables private
    private: 
        double height;
        double radius;
        double*other_value {nullptr};


    public: 
        // Constructors
        // defualt meaning nothing in it
        // can only have one Cylinder with ()
        // default has nothing in it but you can set
        // default class to have things stored
        // Cylinder() = default;

        Cylinder() {
            height = 10;
            radius = 5;
            // If we use dynamic memory allocation, will have to use destructors
            // ex:
            other_value = new double;
            *other_value = 10;
        }

        Cylinder(double h, double r, double o_val) {
            height = h;
            radius = r;
            other_value = new double;
            *other_value = o_val;
        }

        ~Cylinder() {
            delete other_value;
            cout << "other_value memory released in destructor" << endl;
        }

        double volume() {
            return PI * radius * radius * height;
        }

        // Getters and Setters have to be public
        // Getters
        double get_height() {
            return height;
        }

        double get_radius() {
            return radius;
        }

        // Setters
        void set_height(double height_param) {
            height = height_param;
        }

        void set_radius(double radius_param) {
            radius = radius_param;
        }

};

#endif