//CSCI Fall 2019 
//Author: Anuragini Sinha
//Recitation 304 Murray Cox
//Homework 4 problem #5
#include <iostream>
using namespace std; 

void wordCount(string s)
{
    int count = 0;// must initalize a counter for the words
    for(int i = 0; i < s.length();i++)// for loop cycling thorugh the entire string
    {
        
        if(s[i] == ' ')// if the index equals a blank this will iterate the count
        {
            count++;
        }
    }
    cout<<count<<endl;
}
int main()
{
    //test case 1 
    //expected output 
    //3
    wordCount("apple is a fruit");
    //test case 2
    //expected output
    //5
    wordCount("I like ice cream and cake");
}