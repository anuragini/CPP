#include <iostream>
#include "BST.hpp"
using namespace std;
#define COUNT 10

/*
PUBLIC METHODS:
*/

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

void inorderPrint(Node* currNode){
     if(currNode)
     {
        inorderPrint( currNode->left);
        cout << " "<< currNode->key;
        inorderPrint( currNode->right);
     }
 }
 
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






int main (int argc, char* argv[]){

  cout<<"------------Creating tree - test-1------------"<<endl;
  BST tree;
  int numbers[] = {5, 3, 8, 6, 15, 10, 17};
  for(int i = 0; i < 7; i++) {
    tree.addNode(numbers[i]);
  }
  
  cout << "before decrement " <<endl;
  tree.print2DUtil(1);
  tree.decrement();
  cout << "after decrement " <<endl;
  tree.print2DUtil(1);

  // ------------------ Test case - 1 ----------------------- 
  /* BEFORE:
              5
          /       \
        3           8
                  /   \
                6       15
                       /  \
                      10  17

  */

  /* AFTER run decrement() 1 time
              5
          /       \
        2           8
                  /   \
                5       15
                       /  \
                      9   16

  */
  
  cout<<"------------Creating tree - test-2------------"<<endl;
  BST tree_2;
  int numbers_2[] = {5, 3, 4, 1};
  for(int i = 0; i < 4; i++) {
    tree_2.addNode(numbers_2[i]);
  }

  cout << "before decrement " <<endl;
  tree_2.print2DUtil(1);
  tree_2.decrement();
  tree_2.decrement();
  cout << "after decrement() 2 times " <<endl;
  tree_2.print2DUtil(1);
  


  // ------------------ Test case - 2 ----------------------- 
  /* BEFORE:
            5
          /       
        3
      /   \
    1       4

  */

  /* AFTER run decrement() 2 times
            5
          /       
        3
      /   
    -1       

  */

  cout<<"------------Creating tree - test-3------------"<<endl;
  BST tree_3;
  int numbers_3[] = {7, 5, 9, 3, 6};
  for(int i = 0; i < 5; i++) {
    tree_3.addNode(numbers_3[i]);
  }

  cout << "before decrement " <<endl;
  tree_3.print2DUtil(1);
  tree_3.decrement();
  tree_3.decrement();
  tree_3.decrement();
  cout << "after decrement() 3 times " <<endl;
  tree_3.print2DUtil(1);

  
  // ------------------ Test case - 3----------------------- 
  /* BEFORE:
            7
          /   \
        5      9
      /   \
    3      6

  */

  /* AFTER run decrement() 3 times
            7
          /       
        5
      /   
    0       

  */

  

  return 0;

}

