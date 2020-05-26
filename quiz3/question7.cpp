#include<iostream> 
using namespace std; 

int main()
{
    int a[] = {5,4,3,2,1}; 
    int *ptr = (int*)(a+4); 
    cout<<*a+1<<","<<*(ptr-1) << endl;
}