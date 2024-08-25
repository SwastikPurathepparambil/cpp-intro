#ifndef CYLINDER_CPP
#define CYLINDER_CPP

#include "constants.cpp"

class Cylinder {

    // All functions assumed as private
    // Usually want to keep Class variables private
    private: 
        double height;
        double radius;


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
        }

        Cylinder(double h, double r) {
            height = h;
            radius = r;
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