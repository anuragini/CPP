using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include "Graph.hpp"

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



//SILVER TODO
void Graph::printGraph(){
    // TODO 
    // loop through all vertices and adjacent vertices
    for(int i = 0; i<vertices.size();i++)
    {
        cout<< vertices[i]->key << " --> ";
        for (int j=0; j<vertices[i]->adj.size(); j++)
        {
            cout<< vertices[i]->adj[j].v->key << " ";
        }
        cout<<endl;
    }
    

}

// SILVER: Complete the following function and return the length of the shortest path (return -1 if you can't find a path)
int Graph::findShortestPath(int src, int dest){

    // Need to find the source vertex since we only have it's key 'src'
    // A pointer for source vertex
    vertex *vStart;

    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->key == src)
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

    // standard BFS
    int dist = 0;
    while(!q.empty()){

        n = q.front();
        //dist = n->distance;
        q.pop();

        // go to all the adjacent vertices of n
        for( int x = 0; x < n->adj.size(); x++ )
        {
            if (n->adj[x].v->visited == false)
            {
                n->adj[x].v->visited == true; 
                q.push(n->adj[x].v);
                n->adj[x].v->distance++;
                if (n->adj[x].v->key == dest)
                {
                   
                    return n->distance;
                }
            }
            // If a adjacent has not been visited, then mark it visited and enqueue it
            // Update the distance of the adjacent vertices along the way
            // Stop when you reach the destination vertex and return the needful
        }

    }

    return -1;

}

int main()
{
    Graph g; // undirected and unweighted
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);
    g.addVertex(6);

    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(1, 4);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(3, 4);
    g.addEdge(5, 6);

    
    // SILVER TODO : Complete the printGraph() function
    // Expected Format for printing (the vertices/adjacent vertices can be in any order):
    // 1 --> 2 3 4 
    // 2 --> 1 3 
    // 3 --> 1 2 4
    // 4 --> 1 3 5 6
    // 5 --> 4 6
    // 6 --> 4 5

    g.printGraph();


    return 0;
}
