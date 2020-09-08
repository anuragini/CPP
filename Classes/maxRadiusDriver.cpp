//CSCI Fall 2019 
//Author: Anuragini Sinha
//Recitation 304 Thanika Reddy
//Homework 6 problem #2

#include <iostream> 
#include <iomanip>
#include "planet.h"
using namespace std; 

int maxRadius(Planet planets[], int size)// function takes both array of planet objects planets, and size of array
{

 int maxRadIndex = 0; // this is intial value of maxium radius
 double radius = 0.0; // radius is 0.0
 if(size == 0) // if the array is empty
 {
     return -1;//return this value
 }
 for(int i = 0; i< size; i++) //cycle thorugh size of the array
 {
     double r = planets[i].getRadius();//r is equal to the index in the planets array which access the radius from planet.cpp
     if(r > radius) // if r is greater than the current radius which is zero
     {
         radius = r;// this is the new maxium radius
         maxRadIndex = i;// this index is the value in the planets[] array
     }
 }
 return maxRadIndex;// return index from array
}


int main()
{
    //test case 1
    //Bird World
    //4231
    //3.37941e+11
    Planet planets[5]; 
    planets[0] = Planet("On A Cob Planet",1234);
    planets[1] = Planet("Bird World",4321);
    int idx = maxRadius(planets, 2); 
    cout<<planets[idx].getName()<<endl; 
    cout<<planets[idx].getRadius()<<endl;
    cout<<planets[idx].getVolume()<<endl;
    
    //test case 2 
    //expected output -1
        planets[3]; 
     idx = maxRadius(planets, 0); 
     cout<<idx<<endl;
    
}

