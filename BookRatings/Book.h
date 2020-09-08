//CSCI Fall 2019 
//Author: Anuragini Sinha
//Recitation 304 Thanika Reddy
//Homework 6 problem #3

#ifndef BOOK_H
#define BOOK_H
#include <string>
using namespace std; 



class Book
{

    private:
        string author; // these variables cannot be accesed by other classes  
        string title;
    public: 
        Book();// empty or default constructor
        Book(string title, string author);// parametrized constructor
        string getTitle();//getter function empty constructor
        void setTitle(string title);// setter takes in a string
        string getAuthor();// this is getter is also an empty constructor will return value
        void setAuthor(string author);// this sets the value of author
       

};
#endif