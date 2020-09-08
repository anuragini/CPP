//CSCI Fall 2019 
//Author: Anuragini Sinha
//Recitation 304 Thanika Reddy
//Homework 7 problem #4


#include <iostream>
using namespace std; 
#include "Book.h"
#include "User.h"

string to_lower(string s) // this will make the words in the file lowercase
{
    string lower = "";
    for (int i=0; i<s.length(); i++)
    {
        char C = tolower(s[i]); // this char value takes the index string value
        lower = lower + C; // this then added to equal lower
    }
    
    return lower;   // this is returned
}




int getCountReadBooks(string username, User users[], int numUsers, int numBooks)//takes in 4 parameters
{

    bool userFound = false; // if the user is found set to false
    int counter = 0;
    
    for(int i = 0; i<numUsers; i++) //cycle through Numusers
    {
        string userValue = users[i].getUsername(); //get the username from user class
        string userValueLower = to_lower(userValue);//set this to lower case
        string userNameLower = to_lower(username); // this will set username to lower case
        if(userNameLower.compare(userValueLower)==0) // when userValuelower equals userNameLower
        {
            userFound = true;
            

            for(int j = 0; j<numBooks;j++) // then cycle through numBooks
            {
                if(users[i].getRatingAt(j) > 0 && users[i].getRatingAt(j) <= 5) //if the ratings are between 0 and 5
                {
                    counter++; //counter will iterate
                }
            }
            
            break; //break out
        }
        
    }
    if(userFound == false) //user was not found
    {
        return -3;
    }
    if (userFound == true) //if user was found
    {
        if (numBooks == 0) // if there are no ratings
        {
        return -3; //return -3
        }
    }
    return counter; //counter will iterate
}




int main()
{
    //test case 1
    string userName = "Anu";
    int numUsers = 1;
    int numBooks = 1;
    users[0].setUserName(userName);
    books[0].setTitle("Looking for Alaska");
    int x = getCountReadBooks(userName,users,books,numUsers,numBooks)
    cout<x<<end;
    
  //test case 2
    string userName = "Sara";
    string userName1 = "Samantha";
    int numUsers = 2;
    int numBooks = 2;
    users[0].setUserName(userName);
    users[0].setUserName(userName1);
    books[0].setTitle("Looking for Alaska");
    books[1].setTitle("Someone Like You");
    int x1 = getCountReadBooks(userName,users,books,numUsers,numBooks)
    cout<x1<<end;   
    
    
}