
//CSCI Fall 2019
//Author: Anuragini Sinha 
//Recitation 304 Thankia Reddy
// Homework 9  problem #2

#include <iostream> 
#include <string>
using namespace std; 

string decimalToBinaryRecursive(int n)
{
    int rem; // this is the result after quotient is divided by two
    int quotient; // how many times the integer can be divided by two
    if (n == 0) // when n is 0
    {
        return "0"; //return 0 as a string
        
    }
    if(n == 1) // when the quotient is equal to one it cannnot be divided further
    {
        return "1"; // so the remiander would always be one
    }
    else //recursive case
    {
       rem = n % 2; // this is the result after being divided by two(what is left over)
       n = n/2; // this is the actual quotient when the number is divided by two
       return decimalToBinaryRecursive(n) + to_string(rem); // this will cotacentate the reaminders each time the number is divided by two
       
    }
}
int main() 
{ 
    //test case 1
    //expected output
    //1000
    string s = decimalToBinaryRecursive(8);
    cout<<s<<endl;
    //test case 2
    //expected output
    //10011
    string n = decimalToBinaryRecursive(19);
    cout<<n<<endl; 
}