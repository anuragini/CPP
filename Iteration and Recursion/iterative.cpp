//CSCI Fall 2019
//Author: Anuragini Sinha 
//Recitation 304 Thankia Reddy
// Homework 9  problem #1

#include <iostream>
#include<string>
using namespace std; 

string decimalToBinaryIterative(int n)
{
    if(n == 0) // if the integer is 0 then return "0"(string)
    {
        return "0";
    }
    int quotient = n; 
    int rem;
    string s = "";
    for (int i = 0; i<n; i++) 
    {
        rem = quotient % 2; // this will get the reaminder each time the quotient is divisible by two
        quotient = quotient/2; // this is how many times the quotient is divisible by two
        s  = s + to_string(rem); // this is the contactentation of the remainders
        if (quotient == 1) // if the quotient is 1 then the remainder is equal to one
        {
            s  = s + "1";
            break;
        }
    }
    string binary = "";
    for (int i = s.length()-1; i>=0; i--) // this for loop will print out the concatenation in reverse order
    {
        binary = binary + s[i]; // this is the final result
    }
    return binary;

  
}


int main()
{
    //test case 1 
    //expected output 
    //101
    string d = decimalToBinaryIterative(5);
    cout<<d<<endl;
    //test case 2
    //expected output 
    //11010
    string s = decimalToBinaryIterative(26);
    cout<<s<<endl;
}

