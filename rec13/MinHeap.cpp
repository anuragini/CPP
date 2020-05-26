#include "MinHeap.hpp"
#include <limits.h>
using namespace std;
#include<bits/stdc++.h> 

/*
Swaps two integer values
*/
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

/*
Constructor for our MinHeap implementation
*/
MinHeap::MinHeap(int cap)
{
  currentSize = 0;
  capacity = cap;
  heapArr = new int[capacity];
}

/*
Finds the parent of a node, given its index.
*/
int MinHeap::parent(int index)
{
  return (index-1)/2;
}

/*
Returns the left child of a node.
*/
int MinHeap::leftChild(int index)
{
  return ((2*index) + 1);
}

/*
Returns the right child of a node.
*/
int MinHeap::rightChild(int index)
{
  return ((2*index) + 2);
}

/*
Returns the smallest element from the heap.
*/
int MinHeap::getMin()
{
  return heapArr[0];
}

/*
When an element is removed/deleted. This method make sures the array
satisfies the heap property.
*/
// TODO Complete the heapify function
void MinHeap::heapify(int i)
{
  int l = leftChild(i);
  int r = rightChild(i);
  int smallest = i;
  if(l<currentSize && heapArr[l]< heapArr[i])
  {
    smallest = l;
  }
 if(r<currentSize && heapArr[r]< heapArr[smallest])
  {
    smallest = r;
  }
  if(smallest!=i)
  {
    swap(&heapArr[i],&heapArr[smallest]);
    heapify(smallest);
  }
}

/*
Inserts an element into the heap by maintaining the heap property.
*/
void MinHeap::insertElement(int value)
{
  if(currentSize == capacity)
  {
    cout<<"Maximum heap size reached. Cannot insert anymore"<<endl;
    return;
  }

  currentSize = currentSize + 1;
  int index = currentSize - 1;
  heapArr[index] = value;

  while (index != 0 && heapArr[parent(index)] > heapArr[index])
    {
       swap(&heapArr[index], &heapArr[parent(index)]);
       index = parent(index);
    }
}
/*
void MinHeap ::decreaseElement(int value)
{
  heapArr[index] = value;
   while (index != 0 && heapArr[parent(index)] > heapArr[index])
    {
       swap(&heapArr[index], &heapArr[parent(index)]);
       index = parent(index);
    }
  
}

void decreaseElement(int i, int value) 
{ 
    heapArr[i] = value; 
    while (i != 0 && heapArr[parent(i)] > heapArr[i]) 
    { 
       swap(&heapArr[i], &heapArr[parent(i)]); 
       i = parent(i); 
    } 
} 
*/

//Prints the elements in the heap
void MinHeap::print()
{
  int iter = 0;
  while(iter < currentSize)
  {
    cout<<heapArr[iter]<<" ";
    iter = iter + 1;
  }
  cout<<endl;
}

// SILVER TODO: Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
  if (currentSize <= 0)
      return INT_MAX;

  if (currentSize == 1)
  {
      currentSize--;
      return heapArr[0];
  }
  int root = heapArr[0];
  heapArr[0] = heapArr[currentSize -1];
  currentSize--;
  heapify(0);
  
  //TODO complete the function
  
return root;
}

// GOLD TODO: This function deletes a key
void MinHeap::deleteKey(int key)
{
    int index;
    for (int i = 0; i < currentSize; ++i) //when the key will be equal to index
        if (key == heapArr[i])
        {
          index = i;
          break;
        }
    
    heapArr[index] = INT_MIN; //negative infinity
    while (index != 0 && heapArr[parent(index)] > heapArr[index]) 
    { 
       swap(&heapArr[index], &heapArr[parent(index)]); //swap operation
       index = parent(index); 
    } 
    extractMin();//get the most minimum value
}
