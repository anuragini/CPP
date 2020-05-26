#include<iostream> 
using namespace std; 

void myFunc(int arr[], int b[], int n)
{
    for(int i = 0; i<n;i++)
    {
        a[i] = b[i] + 2*a[i];
    }
}
int main()
{
    arr[3] = {0,1,2}; 
    b[2] = {0,1}; 
    myFunc(arr,b);
}