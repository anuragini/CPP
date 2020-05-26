
#include<iostream>
using namespace std; 
  
struct Node 
{ 
    int key; 
    Node *left; 
    Node *right; 
}; 

Node* root = NULL;

//this is a preorder traversal.
// Look for all nodes with the given key value and print them out.
void print_depths_utils(Node *node,  int key, int depth) 
{ 
    if (node == NULL) 
        return; 
    if (node->key == key)
    {
        cout<< depth << " ";
    }
    print_depths_utils(node->left, key, depth + 1); //increment depth
    print_depths_utils(node->right,  key, depth + 1); 
    return; 
} 
  
void print_depths(int val) 
{ 
    //root node has depth = 0
    print_depths_utils(root, val, 0); 
    return;
} 
  
Node* createNode(int key) 
{ 
    Node *n = new Node; 
    n->key = key; 
    n->left = NULL; 
    n->right = NULL;
    return n; 
} 
  

int main() 
{ 
    //Create the binary tree given in the test paper
    root = createNode(20); //root is a class variable
    root->left = createNode(15); 
    Node* n1 = root->left;
    n1->left = createNode(10); 
    n1->right = createNode(15); 
    n1->left->left = createNode(8); 
    n1->left->right = createNode(13);
    n1->left->right->left = createNode(12);
    n1->left->right->right = createNode(13);
    
    root->right = createNode(30); 
    Node* n2 = root->right;
    n2->left = createNode(25);
    n2->left->left = createNode(24);
    n2->left->right = createNode(25);
    n2->right = createNode(30);
    n2->right = createNode(30);
    n2->right->left = NULL;
    n2->right->right = createNode(30);
    
    //print all depths of a given key
    print_depths(30); 

    return 0; 
} 