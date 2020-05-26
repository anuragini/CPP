#include<iostream> 

int*foo(int x)
{
    int z = x*x; 
    std::cout<<&z<<std::endl; 
    return &z;
    
}
int main()
{
     int x = 100; 
     int*ret = foo(x); 
     std::cout<<"the function returned: "<<*ret<<std::endl;
}
