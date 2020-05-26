#include<iostream> 
using namespace std; 

struct Address
{
    string name; 
    int id; 
};

int main()
{
    Address A; //stack memory
   A.name = "Anu";
   A.id = 300;
   Address* B = new Address;
   (*B).name = "Maciej";
   (*B).id = 100; 
   B->name = "Asa";
   B->id = 200;
}