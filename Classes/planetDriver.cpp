//CSCI Fall 2019 
//Author: Anuragini Sinha
//Recitation 304 Thanika Reddy
//Homework 6 problem #1
#include <iostream> 
#include <iomanip>
#include "planet.h"
using namespace std; 

int main()
{
    //test case 1
    //expected output
    //4188.79
    Planet p("pluto",10.0);
    double v = p.getVolume();
    cout<<v<<endl;

    //test case 2 
    //expected output 
    //35510.3
    Planet p1("mars",20.0);
    v = p1.getVolume(); 
    cout<<v<<endl;
    return 0;
 

       
    
}