#include "Cups.h"
#include <iostream> 
using namespace std; 

int main()
{
    Cups redCup(2,2.5);
    cout<<redCup.getVolume(redCup.getRadius(),redCup.getHeight());
    
    Cups blueCup; 
    Cups greenCup;
    
    Cups myCups[3] = {redCup, blueCup, greenCup};
    myCups[1].setRadius(2); 
    myCups[1].setHeight(2.5);
    cout<<myCup[1].getVolume(myCup[1].getRadius(),myCup[1].getHeight());
    
    return 0;
}