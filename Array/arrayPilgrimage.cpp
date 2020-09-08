//CSCI Fall 2019 
//Author: Anuragini Sinha
//Recitation 304 Murray Cox
//Homework 4 problem #1
#include <iostream>
using namespace std; 

int main()
{
    
  double temps[10] = {-495.67,-495.67,-495.67,-495.67,-495.67,-495.67,-495.67,-495.67,-495.67,-495.67};//temp will hold 10 double values
  for(int i = 0; i < 10; i++)//this for-loop will cycle through the number of elements
  {
      cout<<temps[i]<<endl;// this will print out the value
  }
  string colors[5] = {"Red","Blue","Green","Cyan","Magenta"};//this array will hold strings for colors
  for(int i = 0; i < 5; i++) // cycle through the length of the array
  {
      cout<<colors[i]<<"\n"<<endl;//then print out the value
       
  }
 
    
    int size = 101; // this will declare the size of the array
    int sequences[size];//this is is the size of the array
    for(int i = 1; i < size;i++ ) // this will cycle through the length of the array
    {
        sequences[i] = i; // the length of the array will equal i 
        cout<<sequences[i]<<endl;// print out i
    }
    
    
    char letters[52];// this is the length of both upper case and lower cases combined
    int begin = 65; // this is the letter for upper case 'A'
  
    for(int i = 0;i<26;i++) // this will cycle through the length of uppercase
    {
        letters[i] = char(i + begin);// this will be the length of letters
        letters[i+1] = char(i+begin+32);// this will increment it
        cout<<letters[i]<<letters[i+1]<<endl;// this will print out the letter of i and and the incremented version
    

}
}