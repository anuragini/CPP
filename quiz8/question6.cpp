
#include<vector> 
#include<queue>
#include<iostream> 
using namespace std; 

int main()
{
    queue<int> q; 
    q.push(1);
    q.push(2);
    int n = q.front(); 
    q.pop(); 
    q.front(); 
    q.push(3); 
    q.pop(); 
    q.push(4);
    q.front(); 
    q.push(5); 
    
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}