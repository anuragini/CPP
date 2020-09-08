//CSCI Fall 2019 
//Author: Anuragini Sinha
//Recitation 304 Murray Cox
//Homework 4 problem #2
#include <iostream> 
using namespace std; 

void printArrReverse(int arr[], int len)//takes two parameters the an array and len
{
 
 for(int i = len; i >= 0 ; i--)// this wil cylce through the length of the array
 {
  cout<<arr[i]<<endl;// print out the array
 }
}
int main()
{
 int  arr[] = {0,1,2,3};// this is the array
  int len = 4; // number of elements in array

 printArrReverse( arr, len);// fuction call 
}
