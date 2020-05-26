#ifndef CUPS_H
#define CUPS_H

class Cups
{
    
public:
 Cups();
Cups(int radius, double height);
 void setRadius(int radius); 
 int getRadius(); 
 void setHeight(double height);
 double getHeight():
 double getVolume(int radius, double height);
 double getSA(int radius, double height);

 
private:
int radius;
double height;

};
#endif