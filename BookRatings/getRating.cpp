//CSCI Fall 2019 
//Author: Anuragini Sinha
//Recitation 304 Thanika Reddy
//Homework 7 problem #3


#include <iostream> 
using namespace std; 
#include "Book.h"
#include "User.h"

string to_lower(string s) // this will make all words in the file lower case
{
    string lower = "";
    for (int i=0; i<s.length(); i++) //go through forloop
    {
        char C = tolower(s[i]);//this char value will be lowered depended on the value
        lower = lower + C;// then this value will be added 
    }
    
    return lower;   //return this value
}

int getRating(string username, string bookTitle, User users[], Book books[], int numUsers,int numBooks)
{ 

    string bookValue = ""; // set this value to compare
    string userValue = ""; //set this value to compare in array
    int bookIndex = -1; // this is the default 
    int rating = -1; // this is the default
    for(int i = 0; i<numBooks;i++) //cycle through the number of books
    {
      bookValue = books[i].getTitle();// this will get the title
      string bookValueLower = to_lower(bookValue);//this will lower the value
      string bookTitleLower = to_lower(bookTitle);//this will lower the value 
      if(bookTitleLower.compare(bookValueLower) == 0 ) //bookTitle == bookValue
          {
              
              bookIndex = i; // this will equal the index
              break;
          }
    }
    if (bookIndex == -1) // if there is no book
    {
        return -3;//return the value
    }
    
    for(int i = 0; i<numUsers;i++) //cycle through the forloop
    {
        string userValueLower = to_lower(userValue);// this wil also be changed to lower
        string userNameLower = to_lower(username); // this is made to lowercase
        userValue = users[i].getUsername();// this wil get the username 
        if(userNameLower.compare(userValueLower)==0) //if the username equals the value
        {
            rating = users[i].getRatingAt(bookIndex); //getthe rating
            break;
        }
    }
    if (rating == -1) // if rating does not exist
    {
        return -3;
    }
    return rating;
        
}


int main()
{
    //test case 1
    string userName = "Anu";
    string bookTitle = "Looking for Alaska";
    books[0].setTitle(bookTitle)
    users[0].setUserName(userName);
//test case 2
  string userName = "Sam";
string bookTitle = "Someone Like You";
    books[0].setTitle(bookTitle)
    users[0].setUserName(userName);
}

