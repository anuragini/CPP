//CSCI Fall 2019 
//Author: Anuragini Sinha
//Recitation 304 Thanika Reddy
//Homework 6 problem #1
#include <iomanip>
#include<math.h>
#include "planet.h"

using namespace std; 

Planet::Planet()// default
{
    planetName = ""; //sets string planetName to blank
    planetRadius = 0.0;// sets double planetRadius
}
Planet::Planet(string Name, double radius)// parametirized constructor
{
    planetName = Name; // string planetName is equal to string name
    planetRadius = radius; // double planetRadius is equal to radius
}
string Planet::getName()
{
    return planetName;// the getter function will return string planetName
}
double Planet::getRadius()
{
    return planetRadius;// the getter function will return double planetRadius
}
void Planet::setName(string Name) 
{
    planetName = Name;// the setter setName will set string Name to planetName
}
void Planet::setRadius(double radius)
{
     planetRadius = radius; // the setter setRadius will set double radius to planetRadius
}
double Planet::getVolume()
{
    double volume = (4.0/3.0) * M_PI * pow(planetRadius,3);//volume will take the constant variables and raise the radius to 
                                                           // the power of three
    return volume;// return
}
