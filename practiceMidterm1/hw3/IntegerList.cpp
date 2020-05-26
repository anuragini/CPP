
#include "IntegerList.hpp"

using namespace std;


IntegerList::IntegerList()
{
    Node* head = NULL; 
    
}


void IntegerList::insertNode(Node* previous, int number)
{
    Node* temp = new Node();
    temp -> data = number; 
    temp -> next = NULL;
    
    if(previous == NULL)
    {
        cout<<"adding: "<< number <<" (HEAD)"<<endl;
        head = temp;
    }
    else
    {
        cout << "adding: " << number << " (prev: " << previous->data <<")" << endl;
        temp -> next = previous -> next; 
        previous->next = temp;
    }
}

Node* IntegerList::getHead()
{
    return head;
}
void IntegerList::setHead(Node* x)
{
    head = x;
}

void IntegerList::loadDefaultSetup()
{
    
    Node*  previous = NULL;
    insertNode(previous,10);
    
    //find the pointer to the first item
    previous = searchNetwork(10);
    insertNode(previous, 20); 
    
    previous = searchNetwork(20);
    insertNode(previous, 30);
    
    previous = searchNetwork(30);
    insertNode(previous,40);
    
    previous = searchNetwork(40);
    insertNode(previous,50);
    
    previous = searchNetwork(50);
    insertNode(previous,60);
    
}

Node* IntegerList::searchNetwork(int number)
{
    Node* ptr = head;
    while(ptr != NULL)
    {
        //cout << "finding nemo " << ptr->data <<endl;
        if (ptr -> data == number)
        {
            return ptr;
        }
        ptr = ptr->next; 
    }
    return NULL;

}


void IntegerList::printPath()
{
    if(head == NULL)
    {
        cout<<"printPath - head is null"<<endl;
        return;
    }
    int count = 0;
    Node* ptr = head;
    while(ptr != NULL)
    {
        count++;
        cout<<ptr->data<< " -> ";
        ptr = ptr->next;
    }
    cout<<"NULL"<<endl;
    //cout<<count<<endl;
    /*
    if(count % 2 == 0)
    {
        cout<<"even number of nodes"<<endl;
    }
    else 
    {
        cout<<"odd number of nodes"<<endl;
    }
    */
    
}

bool IntegerList :: lengthIsEven(Node * head)
{
    if (head == NULL)
    {
        cout <<"head is NULL"<<endl;
    }
    int count = 0;
    Node* ptr = head;
    while(ptr != NULL)
    {
        count++;
        cout<<ptr->data<< endl;
        ptr = ptr->next;
    }
    cout<<"number of integers: " << count<<endl;
    if(count % 2 == 0)
    {
        cout<<"even number of nodes"<<endl;
        return true;
        
    }
    else 
    {
        cout<<"odd number of nodes"<<endl;
        return false; 
    }
    
    
}


int main()
{
    IntegerList intList;
    intList.loadDefaultSetup();
    intList.printPath();
    bool x = intList.lengthIsEven(intList.getHead());
    cout<<x<<endl;
    
}


