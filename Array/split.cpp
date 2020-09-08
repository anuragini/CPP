#include <iostream>
using namespace std; 

int split(string s, char delimiter, string inputarr[],int len)// this will take in four parameters
{
    s = s + delimiter;//
    string arr[len];
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
    for (int i=0; i<len; i++)// cycle through the count for the array
    {
        inputarr[i] = arr[i];// this will equal the new array
        
        
    }
    //return count
    return count;
}
int main()
{
  //test case 1 
  //expected output 4
  
    int len = 4;
    string s = "Anu is a girl";
   char  delimiter = ' ';
   string arr[len];
    int count = split( s, delimiter, arr, len);
     cout<<count<<endl;
     
     //test case 2
     //expected output 4
      int len1 = 3;
    string s1 = "I/like/cake";
   char  delimiter1 = '/';
   string arr1[len1];
    int count1 = split( s1, delimiter1, arr1, len1);
     cout<<count<<endl;
     

    
}