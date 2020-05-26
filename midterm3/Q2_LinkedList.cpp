#include<iostream>
using namespace std;
struct Node{
    int key; /* Key of the node */
    Node *next; /* Pointer to the next node in the list */
};
class LinkedList {
    private:
        Node* head;
    public:
        LinkedList();
        ~LinkedList();
        void append(int key);//append function adds a new node with value key at the end of the linked list
        string print();
        void moveEvens();
        void loadDefaultSetup();
};

LinkedList::LinkedList() 
{
  head = NULL; 
}

LinkedList::~LinkedList() 
{
    
}

void LinkedList::append(int key) 
{
  return;
}
string LinkedList::print() 
{
    Node* ptr = head;
    if (ptr == NULL)
    {
        cout << "nothing in path" << endl;
    }
    else
    {
        while (ptr->next != NULL)
        {
            cout << ptr->key << " -> ";
            ptr = ptr->next;
        }
        cout << ptr->key << " -> ";
        cout << "NULL" << endl;
    }
   return "";
}

void LinkedList::moveEvens() 
{
    Node* curr = head;
    Node* prev;
    Node* prevEven = NULL;
    if (head->key%2 == 0)
    {
       prevEven = head; 
       prev = curr;
       curr = curr->next;
    }
    while (curr != NULL)
    {
    
        if (curr->key%2 == 0)
        {
            if (prevEven == NULL)
            {
                //move to head
                prev->next = curr->next;
                Node* temp = head;
                head = curr;
                head->next = temp;
                prevEven = head;
                
                //cout<<prevEven->key<<" " << head->key << " " << prev->key << " " << curr->key <<endl;
            }
            else
            {
                //if the current node and previous node are even , do not move it
                if (prev->key%2!=0)
                {
                    Node* t = prevEven->next;
                    prevEven->next = curr;
                    prev->next = curr->next;
                    curr->next = t;
                }
                prevEven = curr;
            }
        }
        //cout << curr->key << " -> ";
        prev = curr;
        curr = curr->next;
        
    }
    
    return;
  
}

void LinkedList::loadDefaultSetup()
{
    head = new Node(); 
    Node * n1 = new Node(); 
    Node * n2 = new Node(); 
    Node * n3 = new Node(); 
    Node * n4 = new Node(); 
    
    head->key = 33;
    head->next = n1;
    n1->key = 44;
    n1->next = n2;
    n2->key = 11;
    n2->next = n3;
    n3->key = 22;
    n3->next = NULL;
}

int main()
{
    LinkedList ll;
    ll.loadDefaultSetup();
    ll.print();
    ll.moveEvens();
    ll.print();
    
}