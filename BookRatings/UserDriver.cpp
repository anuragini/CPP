//CSCI Fall 2019 
//Author: Anuragini Sinha
//Recitation 304 Thanika Reddy
//Homework 7 problem #1



#include <iomanip>
#include <iostream>
#include "User.h"
using namespace std; 

int main()
{
  int ratings[]  = {4,7,9,10};
  string s = "Anu";
  User u(s,ratings,4);
  cout<<u.getUserName()<<endl;
  
  int ratings1[]  = {5,8,9,10};
  string s = "Sam";
  User u(s,ratings,4);
  cout<<u.getUserName()<<endl;
  
}