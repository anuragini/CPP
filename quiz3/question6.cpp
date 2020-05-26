#include<iostream> 
using namespace std; 

int main()
{
    int x = 5; 
    int &y = x; 
    int *z = &y;

    x = 20; 
    y = 15; 
    *z = 10;
    cout<<x<<" "<<y<<endl;
}
