//CSCI Fall 2019 
//Author: Anuragini Sinha
//Recitation 304 Thanika Reddy
//Homework 7 problem #1

#ifndef USER_H
#define USER_H 
#include <string> 
using namespace std; 

class User
{
    const int size = 50; // size of array
    private:// private variables only seen in this class
        string userName;
        int ratings[50]; // ratings array will hold 50 ratings
        int numRatings;// this is presented by numratings 
   
    public: 
        User(); 
        User(string userName, int ratings[], int numRatings);//parameterized constructor
        string getUserName(); //getter for username
        void setUserName(string userName);//this will set value for username
        int getRatingAt(int i);// this will get the rating in for loop
        bool setRatingAt(int index, int value);//this will determine if this index is valid
        int getNumRatings();// returns ratings
        void setNumRatings(int numRatings);// ratings is set to this value
        int getSize(); // this will return size of array
}; 
#endif 