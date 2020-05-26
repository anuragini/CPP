#include <iostream>
#include "BST.hpp"
using namespace std;
#define COUNT 10

/*
PUBLIC METHODS:
*/

void inorderTraversal(Node* currNode){
     if(currNode)
     {
        inorderTraversal( currNode->left);
        //cout << " "<< currNode->key;
        if(currNode->left == NULL && currNode->right == NULL)
        {
            if (currNode->key > currNode->parent->key)
            {
                //this is the right node
                //cout << "before right "<< currNode->key<<endl;
                currNode->key = currNode->key -1;
                //cout << "after right "<< currNode->key<<endl;
                if(currNode->key == currNode->parent->key)
                {
                    Node* temp = currNode->parent;
                    delete currNode;
                    currNode = NULL;
                    currNode = temp;
                    currNode->right = NULL;
                }
            }
            else 
            {
                //this is the left node
                //cout << "before left "<< currNode->key<<endl;
                currNode->key = currNode->key -1;
                //cout << "after left "<< currNode->key<<endl;
                
            }
        }
        inorderTraversal( currNode->right);
     }
 }


// Constructor definitions:
// Default:
BST::BST(){
    root = nullptr;
}

void BST::addNode(int data){
    root = addNodeHelper(root, data);
    cout<<data<<" has been added"<<endl;
}

void BST::print2DUtil(int space)
{
    print2DUtilHelper(root, space);
}
 
/*
PRIVATE METHODS:
*/


//  TODO:
//  Write a function decrementLeaves that goes through a Binary Search Tree 
//  and subtracts 1 from each of the leaf nodes. Feel free to implement an 
//  additional helper function.
void BST::decrement(){
    // Write your code here.
    inorderTraversal(root);
}  


//   This function will add the data in the tree rooted at currNode.
//   Call this function from insert().


Node* BST:: addNodeHelper(Node* currNode, int data){
    if(currNode == nullptr){
       return createNode(data);      
    }
    else if(currNode->key < data){
        currNode->right = addNodeHelper(currNode->right,data);
        currNode->right->parent = currNode;
    }
    else if(currNode->key > data){
        currNode->left = addNodeHelper(currNode->left,data);
        currNode->left->parent = currNode;
    }
    return currNode;
}


// Create a new node, setting key value to  input data
// and all pointers to null.
Node* BST:: createNode(int data){
    Node* newNode = new Node;
    newNode->key = data;
    newNode->parent = nullptr;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* BST::getRoot(){
    return root;
}


/*
   Prints a binary tree in a 2D fashion.
Note: The image of the tree is left rotated by 90 degrees.
*/
void BST::print2DUtilHelper(Node *currNode, int space){
    // Base case
    if (currNode == nullptr)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtilHelper(currNode->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", currNode->key);

    // Process left child
    print2DUtilHelper(currNode->left, space);
}

