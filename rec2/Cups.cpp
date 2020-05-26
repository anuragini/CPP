#include "Cups.h"

Cups :: Cups()
{
    radius = 0;
    height = 0.0; 
}
Cups :: Cups(int myRadius, int myHeight)
{
    myRadius = radius; 
    myHeight = height;
}

void Cups :: setRadius(int myRadius)
{
    radius = myRadius;
}
int Cups :: getRadius()// no inputs
{
    return radius; // will return values
}
void Cups :: setHeight(double myHeight)
{
    myHeight = height; 
}
double Cups :: getHeight()
{
    return height;
}
double Cups :: getVolume(int radius,  double height)
{
    double Volume = 3.14159 * radius* radius* height;
    return volume; 
}
double Cups :: getSA(int radius, double height)
{
    double surfaceArea = 2 * 3.14159 * radius * height;
    return surfaceArea;
}