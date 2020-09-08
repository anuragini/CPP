//CSCI Fall 2019 
//Author: Anuragini Sinha
//Recitation 304 Thanika Reddy
//Homework 7 problem #1




#include <iomanip>
#include <string>
#include "User.h"

using namespace std; 

User :: User()
{
  string userName = ""; // intialize username as empty string
  for(int i = 0; i<size; i++)
  {
      ratings[i] = 0; // this array is set to zero
  }
  numRatings = 0;// so is the number of books in the data base
    
}
User :: User(string Name, int Ratings[], int numRatings)//parameterized constructor
{
    userName = Name; // userName is set to this value
    for(int i = 0; i<size; i++)
    {
        ratings[i] = Ratings[i]; // ratings is ratings[i];
    }
    numRatings = numRatings; 
    if(numRatings > size) // if number of books is greater than current size of the array
    {
        numRatings = size;// this becomes the new array size
    }
}
string User :: getUserName()
{
    return userName;//return userName
}
void User :: setUserName(string Name)
{
    userName = Name;// sets userName to name
}
int User :: getRatingAt(int index)
{
  return ratings[index]; // ratings will hold indcies value
}

bool User :: setRatingAt(int index, int value)
{
   if(value < 0 && value > 5) // if this index value is not between 1 and 5
   {
       return false;// this is set to false
   }
   ratings[index] = value; // if it is
   return true;
  
}

int User :: getNumRatings() 
{
    return numRatings; //this will return number of ratings
}

void User :: setNumRatings(int numRatings)
{
    numRatings = numRatings; // this will set it to a number of values
}

int User :: getSize() 
{ 
      return size;  // this will return size
}

