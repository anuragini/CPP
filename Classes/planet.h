//CSCI Fall 2019 
//Author: Anuragini Sinha
//Recitation 304 Thanika Reddy
//Homework 6 problem #1

#ifndef PLANET_H
#define PLANET_H
#include <string>
using namespace std; 

const double pi = 3.14; // constant value for pi
const double coefficient = 1.33; // constant value for coefficent 

class Planet 
{

    private:// these variables cannot be accesed by other classes
        string planetName;// this is a private variable
        double planetRadius;// this is also a private varibale declaration
    public: // these functions are public meaning they can be accesed by any class
        string getName(); // getter function has empty constructor
        void setName(string name);// setter is a accesor function taking in a string 
        double getRadius(); //This getter function will be implemented in the cpp file
        void setRadius(double radius); // setter will take in the radius
        double getVolume(); // this will also be implemented in the cpp file
        Planet();//empty default constructor
        Planet(string planetName, double planetRadius);// this is the parameterized constructor taking in both private varaibles

};
#endif