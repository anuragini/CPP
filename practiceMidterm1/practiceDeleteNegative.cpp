#include<iostream>
using namespace std; 

struct 
{
    int data; 
    Node*next; 
    
}
bool lengthIsEven(Node* head)
{
    int count = 0; 
    Node* ptr = head; 
    while(ptr!=NULL)
    {
        count++;
        ptr = ptr->next;
        if(count % 2 == 0)
        {
            cout<<"The length is even"<<endl;
            return true;
        }
        else 
        {
            cout<<"The lenght is odd"<<endl; 
            return false;
        }
        
    }
    
}
bool deleteAllNegatives(int data)
{ 
    if(head == NULL)
    {
        return;
    }
    Node*curr = head; 
    Node*prev; 
    while(curr!=NULL)
    if(curr->data <0)
    {
        Node*firstNode = head; //what does this mean?
        free(firstNode);
       head = head->next;
        prev->next = curr->next;
        
        
    }
    
}