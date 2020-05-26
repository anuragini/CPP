
#include <iostream>
#include <vector>
#include <queue>
#include<stack>
#include<bits/stdc++.h> 
#include "Graph.hpp"
#include <list> 
using namespace std; 


void Graph::addEdge(string v1, string v2,int num)
{

    for(int i = 0; i < vertices.size(); i++){ 
        if(vertices[i]->name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j]->name == v2 && i != j){
                    adjVertex av;
                    av.v = vertices[j];
                    av.weight = num;
                    vertices[i]->adj.push_back(av);
                   
                    adjVertex av2;
                    av2.v = vertices[i];//
                    av2.weight = num;//
                    vertices[j]->adj.push_back(av2);
                }
            }
        }
    }
}
void Graph :: addVertex(string name)
{
        bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == name){
            found = true;
        }
    }
    if(found == false){
        vertex * v = new vertex;
        v->name = name;
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

void DFS(vertex *n)
{
    n->visited = true;
    for( int i = 0; i < n->adj.size(); i++ )
    {
        if (n->adj[i].v->visited == false)
        {
           cout<< n->adj[i].v->name<< " -> "; 
           DFS(n->adj[i].v);
        }
    }    
}

void Graph :: depthFirstTraversal(string sourceVertex)
{
    vertex *n;

    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->name == sourceVertex)
        {
            n = vertices[i];
            break;
        }
    }
    cout<< n->name<< " -> ";
    DFS(n);
    cout<< "DONE" <<endl;
}


void Graph :: dijkstraTraverse(string start)
{
    
    for(int i = 0; i < vertices.size(); i++)
    {
        vertices[i]->visited = false;  //this represents the first node
    }
    
    vertex *vStart; // parent node
    vertex *vStop; 
    vertex *vSolved;//calculated distance(visited node)
    vertex *s; 
    vertex *parent; // parent of that node that is solved
    list<string> Q; //contain vertex name
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->name == start)
        {
            vStart = vertices[i]; //
        }
        else
        {
            Q.push_back(vertices[i]->name);    //add each vertex into list
        }

    }

    vStart->visited = true;
    vStart->distance = 0;
    vector<vertex*> solvedVertices;
    solvedVertices.push_back(vStart);
    double minDistance;
    //while(vStop->visited == false)
    while(!Q.empty()) //for each vertex there is a list of adjacent vertices that is being loooped through
    {
        minDistance = INT_MAX;//set to infinity
        vSolved = NULL;
        for(int i = 0; i < solvedVertices.size(); i++) //loop through the verticies
        {
            s = solvedVertices[i];
            for( int j = 0; j < s->adj.size(); j++ ) // the adjacent vertices
            {
                //cout << s->adj[j].v->name <<endl;
                if (s->adj[j].v->visited == false)
                {
                    double d1 = s->distance; //calcualte the distance between the vertices and the adjacent vertices
                    double d2 = s->adj[j].weight;
                    double dist = d1 + d2;
                    if (dist < minDistance) //when the distance of the adjacent weights is more than the set minimum distance
                    {
                        vSolved = s->adj[j].v; // this is the solved adjacent vertexe`
                        minDistance = dist; // the new calculated distance will be the new minDistance
                        parent = s;
                    }
                }
            }
        }
        if (vSolved != NULL) {
            //cout << "removing  " << vSolved->name << endl;
            Q.remove(vSolved->name); // when the minDistance is found for the vertex that element will be deleted
            string key = vSolved->name;
            vSolved->distance = minDistance;
            vSolved->pred = parent;
            vSolved->visited = true;
            solvedVertices.push_back(vSolved);
        }
    }   //while loop ends
    
    //Print out vertex name, distance and parent (pred)
    for(int i = 0; i < solvedVertices.size(); i++)
    {
        if (solvedVertices[i]->pred != NULL) 
        {
            cout << solvedVertices[i]->name << " " << solvedVertices[i]->distance << " " << solvedVertices[i]->pred->name << endl;
        } else
        {
            cout << solvedVertices[i]->name << " " << solvedVertices[i]->distance << " " << "NULL" << endl;
        }
    }
    return;

}
void Graph :: shortestPath(string s1, string s2)
{
    dijkstraTraverse(s1);
    vertex *vStart;
    vertex *vStop;
    vertex *vSolved;
    vertex *s;
    vertex *parent;
    list<string> Q; //contain vertex name
    for(int i = 0; i < vertices.size(); i++) //this function will print out the shortest path 
    {
        if(vertices[i]->name == s1) // this will loop through all of the vertices and adjacent verticies
        {
            vStart = vertices[i]; 
        }
        else
        {
            Q.push_back(vertices[i]->name);    //add each vertex into list
        }
        if(vertices[i]->name == s2) 
        {
            vStop = vertices[i];
        }

    }
    
    //Print name of vertices on shortest path
    list<string> pointList;
    pointList.push_back(vStop->name);
    double distance = vStop->distance;
    //cout << vStop->name << " -> ";
    while(vStop->pred != NULL)
    {
        pointList.push_back(vStop->pred->name);
        //cout << vStop->pred->name << " -> ";
        vStop = vStop->pred;
    }
    //cout << "DONE " << "[" << distance<< "]" <<endl;
    
    //Reverse list
    list<string>::iterator it;
    pointList.reverse(); //this is done by putting the list in reverse to get the first parent node
    for(it=pointList.begin(); it != pointList.end(); ++it) // and trace back 
    {
        cout << *it << " -> ";
    }
     cout << "DONE " << "[" << distance<< "]" <<endl;
    return;
  


}
int main()
{
    Graph g;
    /*
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");
    g.addVertex("E");
    g.addVertex("F");
    g.addVertex("G");
    
    g.addEdge("A","B",1);
    g.addEdge("A","C", 3);
    g.addEdge("B","C",1);
    g.addEdge("B","D",2);
    g.addEdge("B","E",4);
    g.addEdge("B","G",3);

    g.addEdge("D","F",4);
    g.addEdge("E","F",5);
    
    g.displayEdges();
    
    g.depthFirstTraversal("A");
    g.dijkstraTraverse("A");
    g.shortestPath("A", "F");
    g.shortestPath("A", "C");
    */
    
    g.addVertex("Aurora");
    g.addVertex("Bloomington");
    g.addVertex("Cheyenne");
    g.addVertex("Fruita");
    g.addVertex("Denver");
    
    
    g.addEdge("Aurora","Bloomington",5);
    g.addEdge("Aurora","Cheyenne",10);
    g.addEdge("Aurora","Denver",30);
    g.addEdge("Bloomington","Aurora",5);
    g.addEdge("Bloomington","Denver",40);
    g.addEdge("Bloomington","Fruita",15);
    g.addEdge("Cheyenne","Aurora",10);
    g.addEdge("Cheyenne","Denver",10);
    g.addEdge("Denver","Cheyenne",10);
    g.addEdge("Denver","Bloomington",40);
    g.addEdge("Fruita","Aurora",30);
    g.addEdge("Fruita","Bloomington",15);
    g.depthFirstTraversal("Aurora");
    g.dijkstraTraverse("Denver");
    g.shortestPath("Denver", "Bloomington");
  
    
    
    
}

