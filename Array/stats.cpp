//CSCI Fall 2019 
//Author: Anuragini Sinha
//Recitation 304 Murray Cox
//Homework 4 problem #3
#include <iostream> 
#include <iomanip>

using namespace std; 

void stats(double arr[], int len)// takes two parameters array as a double and length of array an int
{
 
    double maxValue = arr[0];
    double minValue = arr[0];
    for(int i = 1; i< len; i++)
    {
        if(arr[i] < minValue)
        {
            minValue = arr[i];
        }
        if(arr[i] > maxValue)
        {
         maxValue = arr[i];
        }
    }
    double average = (minValue + maxValue)/2;
    cout << fixed << showpoint;
    cout << setprecision(2);
    cout << "Min: " << minValue<<endl;
    cout<<"Max: "<<maxValue<<endl;   
    cout<<"Avg: "<<average<<endl;
}


int main()
{
//test case 1 
//expected output
//Min: 0.00
//Max: 3.00
//Avg:1.50
double arr[] = {0,1,2,3};
int len = 4;
stats(arr, len);
//test case 2
//expected output
// Min: 3.00
// Max: 8.00
//Avg: 5.50
double arr1[] = {3,4,5,6,7,8};
int len1 = 6;
stats(arr1,len1);
}

   
