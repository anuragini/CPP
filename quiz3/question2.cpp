#include<iostream> 

int main(int argc,char* argv[])
{
    int i; 
    int *pi = &i; 
    int *j = new int; 
    double *pd = new double[20]; 
    
    //delete i; 
    delete pi; 
    //delete j; 
    //delete pd; 
    return 0;
};