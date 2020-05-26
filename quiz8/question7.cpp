
#include<vector> 
#include<queue>
#include<iostream> 
using namespace std; 


int main()
{
    vector<int> q; 
    q.push_back(1);
    q.push_back(2);
    int n = q.front(); 
    q.pop_back(); 
    q.begin(); 
    q.push_back(3); 
    q.pop_back(); 
    q.push_back(4);
    q.front(); 
    q.push_back(5); 
    
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop_back();
    }
    return 0;
}