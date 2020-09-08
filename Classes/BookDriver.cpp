//CSCI Fall 2019 
//Author: Anuragini Sinha
//Recitation 304 Thanika Reddy
//Homework 6 problem #3

#include <iostream> 
#include <iomanip>
#include "Book.h"
using namespace std; 


int main()
{
    // test case 1
    Book b = Book("The Fault In Our Stars","John Green");
    cout<<b.getTitle()<<endl;
    cout<<b.getAuthor()<<endl; 
    //expected output 
    //The Fault in Our Stars 
    //John Green
    //test case 2
    //Pride and Prejudice 
    // Jane Austen
    string s = "Jane Austen";
    string s1 = "Pride and Prejudice";
    //expected output 
    //Pride and Prejudice
    // Jane Austen
    b.setAuthor(s);
    b.setTitle(s1);
    cout<<b.getTitle()<<endl;
    cout<<b.getAuthor()<<endl; 
}