#include "Graph.hpp"
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

// function to add edge between two vertices
void Graph::addEdge(int v1, int v2){

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->key == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j]->key == v2 && i != j){
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
void Graph::addVertex(int n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->key == n){
            found = true;
        }
    }
    if(found == false){
        vertex * v = new vertex;
        v->key = n;
        vertices.push_back(v);
    }
}

// function to visualize the graph
void Graph::printGraph(){

    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i]->key<<" --> ";
        for(int j = 0; j < vertices[i]->adj.size(); j++){
            cout << vertices[i]->adj[j].v->key << " ";
        }
        cout<<endl;
    }

}

// function to go through all vertices and set them unvisited
void Graph::setAllVerticesUnvisited()
{
  int i;
  for(i=0; i<vertices.size(); i++) {
      vertices[i]->visited = false;
  }
}


// DFS
// TODO: Complete this function, so that it can be used in the isBridge function
void Graph::DFTraversal(vertex *n)
{
    stack<vertex*> s;
    s.push(n);
    
    while(!s.empty()){
        n = s.top();
        s.pop();
        n->visited = true; 
        for( int i = 0; i < n->adj.size(); i++ )
        {
            if (n->adj[i].v->visited == false)
            {
                s.push(n->adj[i].v);
            }
        }
    }

    return;
}

// function to remove an edge connecting vertices with keys key1 and key2
// TODO: Complete this function, so that it can be used in the isBridge function
void Graph::removeEdge(int key1, int key2)
{


}


// Check if an edge connecting vertices with keys: key1 and key2 is a bridge of the graph, returns true if it is indeed a bridge otherwise false
// TODO SILVER: Follow the TODOs to complete the funciton below
bool Graph::isBridge(int key1, int key2)
{

    return false;
}
    
bool recursivecheck(vertex* n,vertex* p )
{
    n->visited = true; 
    for(int i = 0; i<n->adj.size();i++)
    {
        if(!n->adj[i].v->visited)
        {
            if(recursivecheck(n->adj[i].v,n))
            {
                return true; 
            }
        }
        else if (n->adj[i].v!=p)
        {
            return true; 
        }
    }
    return false; 
}

bool Graph :: fun()
{
    for(int u = 0; u < vertices.size();u++)
    {
        if(!vertices[u]->visited)
        {
            if(recursivecheck(vertices[u],NULL))
            {
                return true; 
            }
            return false; 
        }
    }
}

