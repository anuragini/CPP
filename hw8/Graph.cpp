using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include "Graph.hpp"

using namespace std;
// function to add edge between two vertices
void Graph::addEdge(string v1, string v2){

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j]->name == v2 && i != j){
                    adjVertex av;
                    av.v = vertices[j];
                    vertices[i]->adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = vertices[i];
                    vertices[j]->adj.push_back(av2);
                }
            }
        }
    }
}


// function to add a vertex to the graph
void Graph::addVertex(string n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == n){
            found = true;
        }
    }
    if(found == false){
        vertex * v = new vertex;
        v->name = n;
        vertices.push_back(v);
    }
}

void Graph :: displayEdges()
{
    for(int i = 0; i<vertices.size();i++)
    {
        cout<< vertices[i]->name << " --> ";
        for (int j=0; j<vertices[i]->adj.size(); j++)
        {
            cout<< vertices[i]->adj[j].v->name << " ";
        }
        cout<<endl;
    }
    
}
void Graph :: breadthFirstTraverse(string sourceVertex)
{
    // Need to find the source vertex since we only have it's name 'src'
    // A pointer for source vertex
    vertex *vStart;

    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->name == sourceVertex)
        {
            vStart = vertices[i];
        }
    }

    vStart->visited = true;

    // Use the queue to keep track of visited vertices
    queue<vertex*> q;

    // Enqueue the source vertex
    q.push(vStart);

    vertex *n;
    cout<<"Starting vertex (root): " << vStart->name<< "->";

    // standard BFS
    int dist = 0;
    while(!q.empty()){

        n = q.front();
        //string nn = n->name;
        //dist = n->distance;
        q.pop();

        // go to all the adjacent vertices of n
        for( int i = 0; i < n->adj.size(); i++ )
        {
            //string mm = n->adj[i].v->name;
            //bool isVisited = n->adj[i].v->visited;
            if (n->adj[i].v->visited == false)
            {
                n->adj[i].v->visited = true; 
                q.push(n->adj[i].v);
                n->adj[i].v->distance = n->distance + 1;
                cout<< n->adj[i].v->name<<"("<< n->adj[i].v->distance <<")"<<" ";
            }
        }

    }

    return;
}
int Graph :: getConnectedComponents()
{
    int count = 0; 
    for(int i = 0; i<vertices.size();i++)
    {
        if(vertices[i]->visited == false)
        {
            count = count+1;
            breadthFirstTraverseUtils(vertices[i]->name,vertices);
        }
    }
    return count;
}