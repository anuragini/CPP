#include<iostream> 
using namespace std; 

int*foo(int x)
{
    int*y = new int[x*x]; 
    return y; 
    
}
int main()
{
    int * z = foo(10); 
    //delete z; 
    //delete *z;
    delete []z; 
    //delete []y;
    
    return 0;
}