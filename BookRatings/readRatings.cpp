//CSCI Fall 2019 
//Author: Anuragini Sinha
//Recitation 304 Thanika Reddy
//Homework 7 problem #2

#include <iostream> 
#include <fstream> 
#include "User.h"
using namespace std; 

int split(string s, char delimiter, string arr[])// this will take in four parameters
{
    s = s + delimiter;
    int count = 0;
    string word = "";
    
    if(s.length() == 0 || s == "")// if s is equal to zero or s equals blank return zero
    {
        return 0; 
    }
    for(int i = 0; i < s.length();i++)// for loop cycling thorugh the entire string
    {
        if(s[i] == delimiter) // if the index equals delimiter
        {
            if (word.length() > 0)// when word length is more than zero 
            {
                arr[count] = word;// the count will equal the word 
                //cout<<word<<endl;
                word = "";// this will be a blank
                count++;//iterate count
            }
        }
        else
        {
            if (s[i] != delimiter)//is s does not equal the delimter
            {
                word = word + s[i]; // string will be concatenated
            }
           

        }
    }

    return count;
}


int readRatings(string fileName, User users[], int numUsers, int maxRows, int maxColumns)
{
    string s; // this is for each line
    int len = maxRows; //length is the number of rows
    int count = 0;
    maxColumns=maxColumns+1; // there is total of 51 rows
    
        if (numUsers == maxRows) // if this condition is true 
    {
        return -2; //return 
    }
    
    ifstream file (fileName); //converting file to stream
    if (!file)// if 
    {
        //cout << "File not found" << endl;
        return -1;
    }


    
     while(getline(file, s)) // use getline function taking in file and line
    {
        if (count+numUsers >= maxRows) // this is both the count of books and numUsers
        {
            return count+numUsers;// if less than equal to max rows
        }
        if (s.length() > 0 ) // if s is greater than zero
        {
            
            string arr[maxColumns]; // array value is the columns
            char  delimiter =',';
            int x = split (s, delimiter, arr); // use split function for each array
            //users[count+numUsers] = arr[0];
            users[count+numUsers].setUserName(arr[0]);
            for (int i=0;i<maxColumns-1;i++) // cycle through columns
            {
                string s1 = arr[i+1]; // add one to the count
                if (s1 !="" || s1.length() > 0){
                    //ratings[count+numUsers][i] = stoi(arr[i+1]); // change the s value to an int
                    int value = stoi(arr[i+1]);
                    users[count+numUsers].setRatingAt(i,value);
                }
            }
            count ++; // count will increment
        }
        
    }
    return count+numUsers; // return total books and the users
}

int main()
{
// load multiple files
User users[10] = {};
int ratings[10][50] = {{0}};
int numUsers = 0;
int maxRows = 10;
int maxColumns = 50;
int numBooks = 5; // (we know it's 5 books)
//int readRatings(string fileName, User users[], int numUsers, int maxRows, int maxColumns)
numUsers = readRatings("ratings.txt", users, numUsers, maxRows, maxColumns);
cout<<numUsers<<endl;


User users[5] = {};
int ratings[5][50] = {{0}};
int numUsers = 0;
int maxRows = 5;
int maxColumns = 50;
int numBooks = 3; // (we know it's 5 books)
//int readRatings(string fileName, User users[], int numUsers, int maxRows, int maxColumns)
numUsers = readRatings("ratings.txt", users, numUsers, maxRows, maxColumns);
cout<<numUsers<<endl;
//numUsers = readRatings("ratings2.txt", users, ratings, numUsers, maxRows, maxColumns);

//cout << "Function returned value: " << numUsers << endl;
    
/*
    
// return size if it filled up
string users[10] = {};
int ratings[10][50] = {{0}};
int numUsers = 0;
int maxRows = 10;
int maxColumns = 50;
numUsers = readRatings("ratings.txt", users, ratings, numUsers, maxRows, maxColumns);

cout << "Function returned value: " << numUsers << endl;
cout << endl;
///////////////////
    

string fileName = "ratings.txt";
int maxRows = 100;
int numUsers = 0;
int maxColumns = 51;

string users[100] = {};
int ratings[100][50] = {{0}};

int x = readRatings(fileName,users,ratings,numUsers,maxRows,maxColumns);
 
 for(int i = 0; i<maxRows; i++)
 {
     cout<<users[i]<<endl; 
     for(int j = 0; j<maxColumns-1; j++)
     {
         cout<<ratings[i][j]<<",";
     }
     cout<<endl;
 }
*/

}
