#pragma once /* include this file at most  once */

#define COUNT 10


struct Node {
  int key;          /* key of the node */
  Node* left;   /* initialized the left sub-tree to Null */
  Node* right;  /* initialized the right sub-tree to Null */
  Node() {key = -1; left = 0; right = 0;}
  Node(int k) {key = k; left = 0; right = 0;}
  Node(int k, Node* l, Node* r) {key = k; left = l; right = r;}
};


class BST {
private:
  Node* root; /* Root of the Binary Search Tree */
  
public:
  BST();  /* Constructor */
  ~BST(); /* Destructor */

  void insert(int val);   /* insert the value val in the BST, drop the duplicates */
  
  Node* search(int k);  /* Search if value k is in the BST, Retun a pointer if yes, and 0 otherwise. (drop equal values) */

  Node* getMin(); /* get a pointer to the node with minimum key */
  Node* getMax(); /* get a pointer to the node with maximum key */

  int size(); /* Return number of the ndoes in the BST */
  void prettyPrint(); /* pretty print the BST */
  
  void inOrder(); /* in-order traversal */ 
  void preOrder(); /* pre-order traversal */
  void postOrder(); /* post-order traversal */
  
  int getSum(); /* sum of the elements in the BST */

  void remove(int val);  /* remove the value val in the BST */
  
private:
  /* helper functions */
  void insert(Node* &T, int val);
  void remove(Node* &T, int val);  
  int getSum(Node* T);
  void recursive_destruct(Node* T);  
  Node* getMin(Node* T);
  Node* getMax(Node* T);  
  void inOrder(Node* T);
  void preOrder(Node* T);
  void postOrder(Node* T);
  int size(Node* T);  
  Node* search(Node* T, int val);
  void prettyPrint(Node* T, int space);
};

