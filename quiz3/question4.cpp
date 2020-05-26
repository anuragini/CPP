
#include<iostream> 
using namespace std; 
void swap3(int *&ptr1,int *&ptr2)
{
    int *temp; 
    temp = ptr1; 
    ptr1 = ptr2; 
    ptr2 = temp;
    
}


int main()
{
    int*ptr1 = new int[5]; 
    int *ptr2 = new int[5]; 
    for(int i = 0; i<5;i++)
    {
    ptr1[i] = i; 
        
    }
    for(int i = 0; i<5;i++)
    {
        ptr2[i] = 4-i; 
        
    }
    swap3(ptr1,ptr2);
     for(int i = 0; i<5;i++)
    {
        cout<<ptr1[i]<<" ";
        
    }
    return 0;
    
    
}