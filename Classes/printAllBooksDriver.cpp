//CSCI Fall 2019 
//Author: Anuragini Sinha
//Recitation 304 Thanika Reddy
//Homework 6 problem #5




#include <iostream> 
#include <fstream>
using namespace std; 
#include "Book.h"


void printAllBooks(Book books[], int numBooks)//change to an array of book book objects
{
    
     if(numBooks <= 0) // if the size of array is less than or equal to zero
     {
         cout<<"No books are stored"<<endl;//print this statement
          
     }
    for(int i = 0; i < numBooks; i++) // cycle through both arrays with numBooks size
    {
        cout<<"Here is a list of books"<<endl;
         // cout<<titles[i]<<endl;// 
          break;
    }
    //cout<<"Here is a list of books"<<endl;
    for(int i = 0; i < numBooks; i++) // cycle thorugh authors array
    {
        //cout<<"Here is a list of books"<<endl;
        //cout<<" by "<<authors[i]<<endl;
        cout<<books[i].getTitle()<< "by "<<books[i].getAuthor()<<endl;
       
    
    }
}

int main()
{  //test case 1 

      string file = "books.txt";
     int numBooks = 2; 
     Book books[2];
    books[0] = Book("Title1", "Author1");// these call the book class
    books[1] = Book("Title2","Author2");// these call the book class
    printAllBooks(books, numBooks);// call the function
    
    //test case 2
     file = "books.txt";
     numBooks = 0; 
     books[0];
    printAllBooks(books, numBooks);// call the function
}
