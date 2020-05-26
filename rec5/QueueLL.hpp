#ifndef QUEUELL_HPP
#define QUEUELL_HPP

#include <string>

class QueueLL
{
  private:
    struct Node
    {
        int key;//array
        Node *next;//what is next
    };

    // item in list to be dequeued next
    Node* queueFront;
    // item in list that was most recently enqueued
    Node* queueEnd;

  public:
    QueueLL();
    ~QueueLL();
    bool isEmpty();
    void enqueue(int key);
    void dequeue();
    int peek();
    bool isFull(); 
};

#endif
