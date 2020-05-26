//Consider the following structure of node and linked list.

struct Node {
  int key;
  Node *next;
};


//-1 -> 5 -> 30 -> 5 -> 5 -> 15 -> 5 -> 17  NULL

//What will be the output of following pseudo-code? Consider head is the pointer to the first node of above linked list.



Node *pres = head;
int count = 0;
while(pres!= NULL && count < 3) {
        if(pres->key == 5) {
            count = count + 1;
        }
        pres = pres->next;
}
cout <<  pres->key  << endl;
