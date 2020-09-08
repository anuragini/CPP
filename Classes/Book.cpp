
//CSCI Fall 2019 
//Author: Anuragini Sinha
//Recitation 304 Thanika Reddy
//Homework 6 problem #3
#include <iomanip>
#include <string>
#include "Book.h"


using namespace std; 

Book::Book()
{
    title = "";  // this sets title to blank
    author = ""; // author to blank
}
Book::Book(string titleName, string authorName) // parametrized constructor
{
    title = titleName; // title equals titleName
    author = authorName; //author equals authorName
    
}
string Book::getTitle() // getter returns title
{
    return title;
}
string Book::getAuthor() // this will also return author
{
    return author;
}
void Book::setTitle(string titleName)
{
    title = titleName; // set title equal to titleName
}
void Book::setAuthor(string authorName)
{
     author = authorName; // set author to authorName
}

