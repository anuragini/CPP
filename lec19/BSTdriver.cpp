#include<iostream>
#include "BST.hpp"

using namespace std;

int main() {
  BST T;
  int data[10] = {11, 2, 33, 4, 55, 6, 77, -10, 38, 67};
  
  for (int i = 0; i < 10; i++)   {
    cout << "inserting " << data[i] << endl;
    getchar();
    /* 0. Implement an insert in the tree */
    T.insert(data[i]);
    T.prettyPrint();
    
    getchar();
    cout << " ================================ " << endl;
  }
  
  /* 1. First implement search in a BST */
  
  //  if (T.search(33) != 0) cout << "33 is in the tree" <<endl;
  // else cout << "33 is not in the tree" << endl;

  // if (T.search(23) != 0) cout << "23 is in the tree" <<endl;
  // else cout << "23 is not in the tree" << endl;

  /* 2. Implement Size for BST */
  //   cout << "size of the tree is " << T.size() <<endl;


   /* 3. Implement in-order traversal for BST */
   //T.inOrder();

   //cout<<endl;
  /* 4. Implement pre-order traversal for BST */
  //T.preOrder();
  // cout<<endl;
  /* 5. Implement post-order traversal for BST */
  //T.postOrder();
  //cout<<endl;
   
   /* 6. Implement function to compute minimum value in a BST */
   /* Function getMin should return a pointer to the node with smallest value */

   //if (T.getMin() != 0)
  // cout << "minimum value in the tree is " << T.getMin()->key << endl;
   
   /* 7. Implement function to compute maximum value in a BST */
   /* Function getMax should return a pointer to the node with largest value */
   //if (T.getMax() != 0)
  // cout << "maximum value in the tree is " << T.getMax()->key << endl;
   
   /* 8. Implement a function to sum all values in BST */
   //cout << "sum of value in the tree is " << T.getSum() << endl;
   
   /* 10. Implement recursive"remove" */
   //T.remove(11);
   T.remove(38);
   //T.remove(33);
   //T.remove(6);
   //T.remove(4);
   //T.inOrder();
   
}
