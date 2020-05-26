#include<iostream> 
using namespace std; 

int sum_within_range(node*node,int min, int max)
{
    if(node == NULL)
    {
        return 0; 
    }
    if(node->key>=min && node->key<=max)
    {
        return node->key+sum_within_range(node->left,min, max) + sum_within_range(node->right,min, max);
        
    }
    else
    {
        return sum_within_range(node->left,min, max) + sum_within_range(node->right,min, max);
    }
}
