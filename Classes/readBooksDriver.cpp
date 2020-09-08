//CSCI Fall 2019 
//Author: Anuragini Sinha
//Recitation 304 Thanika Reddy
//Homework 6 problem #4


#include <fstream>
#include <iostream> 
#include <iomanip>
#include "Book.h"
using namespace std; 

int readBooks(string fileName, Book books[], int numBookStored, int size)
{
    
    ifstream file(fileName);
    if(!file)  
    {
        return -1; // if file does not equal fileName
    }
    
    if(numBookStored == size)
    {
        return -2; // if the number of books is equal to the size of the array
    }
    
    char delimiter = ','; // the space seperating
    string s;
    int count = 0;// set counter to zero
    while(getline(file, s))
    {

        if (s.length() > 0 )
        {
            //if (numBookStored+count >= size)
            //{
            //    return count;
            //}
            string word = "";
            int phraseCount = 0; //initialize for every line. phrase1=author, phrase2=title
            for(int i = 0; i < s.length();i++)// for loop cycling thorugh the entire string
            {
                if ((s[i] == delimiter) || (i == s.length()-1))// if the index equals delimiter
                {
                    if (word.length() > 0)// when word length is more than zero 
                    {
                        
                        if (phraseCount==0)
                        {
                            //cout<<numBookStored+count<<endl;
                            //authors[numBookStored+count] = word;
                            books[numBookStored+count].setAuthor(word);
                            
                            //cout<<authors[numBookStored+phraseCount]<<endl;
                            
                        }
                        else
                        {
                            word = word + s[i];
                            //titles[numBookStored+count] = word;// new word is the array of the count of the books stored
                            books[numBookStored+count].setTitle(word);
                        }
                        //cout<<word<<endl;
                        word = "";
                        phraseCount++;
                        
                    }
                }
                else
                {
                        word = word + s[i]; // string will be concatenated
                        
                }
                
            }
            count++;
            if (numBookStored+count >=size) // if the count of numBooks is greater than size of array
            {
                //for (int j = 0;j<size;j++){ //cycle through size
                   // cout<<titles[j]<<endl; // print all titles
               // }
               return numBookStored+count; // return count
            }
        }

    }

    return numBookStored+count;//return count

}



int main()
{
    //test case 1 
    string fileName = "books.txt";
    int size = 10; // size of arry is ten
    Book books[10] = {};// this is the array
    int numBookStored = 0;// books stored
    int x = readBooks(fileName,books, numBookStored,size);
    for(int i = 0; i < size; i++) // make a for loop 
    {
        string title = books[i].getTitle();// this gets title 
        string author = books[i].getAuthor(); // this gets author
        cout<<title<<"   "<<author<<endl; // print out both
    }
    cout<<"Book count:"<<x<<endl;
 
 //test case 2 
      string fileName = "books1.txt";
       int size = 8 ; // size of arry is 8
     books[8] = {};// this is the array
      int numBookStored = 0;// books stored
     int  x = readBooks(fileName,books, numBookStored,size);
    for(int i = 0; i < size; i++) // make a for loop 
    {
          string title = books[i].getTitle();// this gets title 
          string author = books[i].getAuthor(); // this gets author
        cout<<title<<"   "<<author<<endl; // print out both
    }
    cout<<"Book count:"<<x<<endl;
        
 
}