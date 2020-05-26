#include<iostream> 
using namespace std; 

/*
void reset(int *ip)
{
    cout <<ip<<endl; //0x7ffc30767ba4
    ip = 0;
    cout <<ip<<endl; //0
    cout <<&ip<<endl; //0x7ffc22e0a628
}
*/
void Swap(int &x, int y) //1,2
{
    int temp = x; 
    x = y; 
    y = temp;
}
int main(void)
{
    /*
    int a[] = {1, 3, 5, 7};

//cout << *a  << endl;//*a = 1st element = 1, so *a+10 = 1+10 = 11
//*(a+2) means 3rd element becasue *a is the first element
int a1 = 8;
int b1 = 9;
int *x = &a1; 
int *y = &b1;
//doSomething(&x,&y);
//doSomething(&x,y);
int *x1, *y1;

//q5
int i = 100; 
int *p = &i; 
cout <<p <<endl;//0x7ffc30767ba4
reset(p); 
cout<<*p<<endl;

//q6
float distance = 17.9;
//float *amt = *distance;
float *amt = &distance; 
//*distance = 29.3;
//float &amt = *distance; 
//float* amt = distance; 

//q7
int a = 1; 
int b = 2; 
Swap(a,b); 
cout<<a<<","<<b<<endl;
return 0; 
*/
int m = 1, n = 2; 
int *pm = &m,*pn = &n, *r; 
r = pn; //2
pn = pm; //2
*pm = *pn + 2; //3
cout<<m<<","<<n<<","<<*r<<","<<*pm<<endl;










cout <<"hello"<<endl;



}
