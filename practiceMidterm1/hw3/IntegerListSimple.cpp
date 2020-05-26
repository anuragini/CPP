#include<iostream>
using namespace std;


  
struct Node { 
public: 
    int data; 
    Node* next; 
};

bool lengthIsEven(Node* head)
{
    int count = 0;
    Node* ptr = head;
    while(ptr != NULL)
    {
        count++;
        //cout<<ptr->data<< endl;
        ptr = ptr->next;
    }
    if ((count % 2) == 0)
    {
        cout <<"length is even"<<endl;
        return true;
    }
    else 
    {
        cout<<"length is odd"<<endl;
        return false;
    }
}

//1 2 -3 4 5
//delete -3
Node* deleteNegatives(Node *head)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node* curr = head; 
    Node* prev;
    bool isFound = false;
    while (curr != NULL)
    {
        if (curr->data < 0)
        {
            if (curr == head)
            {
                cout <<"deleting XX "<< curr->data <<endl;
                Node * firstNode = head;
                head = head -> next;
                free(firstNode);
                prev = curr;
    
            }
            else
            {
                cout <<"deleting YY"<< curr->data <<endl;
                prev->next = curr->next;
                free(curr);
                //prev does not change
                curr = prev->next; 
            }
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }

    }
    return head;
}


Node* deletePositives(Node *head)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node* curr = head; //create a pointer to head
    Node* prev;
    bool isFound = false;
    while (curr != NULL)
    {
        if (curr->data > 0)
        {
            if (curr == head)
            {
                cout <<"deleting XX "<< curr->data <<endl;
                Node * firstNode = head;
                head = head -> next;
                free(firstNode);
                prev = curr;
    
            }
            else
            {
                cout <<"deleting YY"<< curr->data <<endl;
                prev->next = curr->next;
                free(curr);
                //prev does not change
                curr = prev->next; 
            }
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }

    }
    return head;
}

Node* deleteOdds(Node *head)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node* curr = head; 
    Node* prev;
    bool isFound = false;
    while (curr != NULL)
    {
        if (curr->data % 2 != 0)
        {
            if (curr == head)
            {
                cout <<"deleting XX "<< curr->data <<endl;
                Node * firstNode = head;
                head = head -> next;
                free(firstNode);
                prev = curr;
    
            }
            else
            {
                cout <<"deleting YY"<< curr->data <<endl;
                prev->next = curr->next;
                free(curr);
                //prev does not change
                curr = prev->next; 
            }
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }

    }
    return head;
}

Node* deleteEvens(Node *head)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node* curr = head; //ptr=curr
    Node* prev;
    bool isFound = false;
    while (curr != NULL)
    {
        if (curr->data % 2 == 0)
        {
            //2 1 3 4 5 (remove 1)
            if (curr == head)
            {
                cout <<"deleting XX "<< curr->data <<endl;
                Node * temp = head;
                head = head -> next; //head is pointing to 1
                free(temp); //this will delete 2
                prev = head; // head now points to 1
    
            }
            else
            {
                cout <<"deleting YY"<< curr->data <<endl;
                prev->next = curr->next;//move to the next number that could be even
                free(curr);
                //prev does not change
                curr = prev->next; 
            }
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }

    }
    return head;
}

Node* deleteAllNodes(Node *head)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node* curr = head;
    Node* nextnode;
    while (curr != NULL)
    {
        nextnode = curr->next;
        head = nextnode;
        cout << "deleting: " << curr->data << endl;
        free(curr);
        
        curr = nextnode;
    }   
    cout << "Deleted list" << endl;
    return head;
}

void printPath(Node* head)
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
    
}

 
void insertNode(Node* previous, int number)
{
    
    Node* temp = new Node(); 
    temp -> data = number; 
    temp -> next = NULL;
    if (previous == NULL) 
    {
        head = temp; 
    }
    else
    {
        temp->next = previous->next; 
        previous->next = temp; 
    }
}
int main() 
{ 
    Node* head = NULL; 
    Node* second = NULL; 
    Node* third = NULL; 
    head = new Node(); 
    second = new Node(); 
    third = new Node();
    
    head->data = 1; // assign data in first node 
    head->next = second; // Link first node with 
    
    // assign data to second node 
    second->data = -2; 
  
    // Link second node with the third node 
    second->next = third; 
    
    third->data = 3; // assign data to third node 
    third->next = NULL; 
    
    bool x;
    x = lengthIsEven(head);
    cout <<x<<endl;
    printPath(head);
    
    head = deleteNegatives(head);
    //head = deletePositives(head);
    //head = deleteOdds(head);
    //head = deleteEvens(head);
    //head = deleteAllNodes(head);
    
    x = lengthIsEven(head);
    cout <<"after deleting " << x<<endl;
    printPath(head);
    
    
    return 0;
}
