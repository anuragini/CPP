
//#pragma once
#include <iostream>
using namespace std;


struct Node
{
    int data;
    Node *next;            // pointer to the next node
};


// class for storing and manipulating linked list of integers
class IntegerList {
    private:
        Node* head;  // pointer to head of linked list 

    public:
        Node();
        void insertNode(Node* previous, int data);
        void loadDefaultSetup();
        Node* searchNetwork(int data);
        void printPath();
};