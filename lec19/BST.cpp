#include<iostream>
#include "BST.hpp"
using namespace std;

// Implement all of the methods declared in the BST class using recursive procedures. 

BST::BST() {
  root = 0;
}

BST::~BST() {
  
}

/*
  Prints a binary tree in a 2D fashion.
  Note: The image of the tree is left rotated by 90 degrees.
*/
void BST::prettyPrint(Node* T, int space)
{
  // Base case
  if (T == 0) return;
  
    // Increase distance between levels
  space += COUNT;
  
  // Process right child first
  prettyPrint(T->right, space);
  
  // Print current node after space
  // count
  printf("\n");
  for (int i = COUNT; i < space; i++)
    printf(" ");
  printf("%d\n", T->key);
  
  // Process left child
  prettyPrint(T->left, space);
}

void BST::prettyPrint()
{
  prettyPrint(root, 1);
}


void BST::insert(int val){
  insert(root, val);
}

Node* BST::search(int k) {
  return 0;
}

int BST::size() {

  return 0;
}

void BST::inOrder() {
  inOrder(root);
}
void BST::preOrder() {
  preOrder(root);
}
void BST::postOrder() {
  postOrder(root);
}

Node* BST::getMin() {
  if
  {
    /*
    implement code later
    */
  }
  else 
  {
    Node* minRight = (T->right).getMin();
    T->key = minRight->key; 
    remove(T->right,minRight->key )
  }
  return getMin(root);
}
Node* BST::getMax() {
  return getMax(root);
}

int BST::getSum() {
  return getSum(root);
}

void BST::remove(int val){
  remove(root, val);
}

void BST::insert(Node* &T, int val) {
  return;  
}

void BST::remove(Node* &T, int val) {
  return;
}
  
int BST::getSum(Node* T) {
  
  return 0;
}
  
void BST::recursive_destruct(Node* T) {
  
  return;
}
  
Node* BST::getMin(Node* T) {
  
  return 0;
}

Node* BST::getMax(Node* T) {
  
  return 0;
}

void BST::inOrder(Node* T) {

  return;
}

void BST::preOrder(Node* T) {
  
  return;
}

void BST::postOrder(Node* T) {
  
  return;
}

int BST::size(Node* T) {
  
  return 0;
}

Node* BST::search(Node* T, int val) {
  return 0;
}
