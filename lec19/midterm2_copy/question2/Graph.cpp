#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
//Public

bool findShortestPath(vertex *vStart, vertex *vStop, vector<vertex*> &vertices){

    // Need to find the source vertex since we only have it's name 'src'
    // A pointer for source vertex
    string src = vStart->name;
    string dest = vStop->name;
    
    //set all vertices to false
    for(int i = 0; i < vertices.size(); i++)
    {
        vertices[i]->visited = false;

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
            string s = n->adj[x].v->name;
            //cout << s << endl;
            if (n->adj[x].v->visited == false)
            {
                n->adj[x].v->visited = true; 
                q.push(n->adj[x].v);
                if (s == dest)
                {
                   
                    return true;
                }
            }
        }
    }

    return false;

}


//Private


void Graph::addEdge(string source, string target){
    for(unsigned int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == source){
            for(unsigned int j = 0; j < vertices.size(); j++){
                if(vertices[j]->name == target && i != j){
                    adjVertex av;
                    av.v = vertices[j];
                    vertices[i]->adj.push_back(av);
                }
            }
        }
    }
}

void Graph::addVertex(string vName){
    bool found = false;
    for(unsigned int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == vName){
            found = true;
            cout<<vertices[i]->name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex * v = new vertex;
        v->name = vName;
        v->distance = 0;
        vertices.push_back(v);
    }
}

void Graph::displayEdges(){
    for(unsigned int i = 0; i < vertices.size(); i++){
        cout<<vertices[i]->name<<":"<<endl;
        for(unsigned int j = 0; j < vertices[i]->adj.size(); j++){
            cout<<" --> "<< vertices[i]->adj[j].v->name <<endl;
        }
        cout<<endl;
    }
}

bool Graph::isStronglyConnected(){
    /* 
    Implement this function. 
    This function returns true if the graph is strongly connected. Otherwise, returns false.
    */
    for(int i = 0; i<vertices.size();i++)
    {
        bool isConnected;
        vertex * v = vertices[i];
        string src = v->name;
        for(int j = 0; j<vertices.size();j++)
        {
            string dest = vertices[j]->name;
            if(src != dest)
            {
                isConnected = findShortestPath(v,vertices[j],vertices);
                //cout << src << "-->" << dest << " " << isConnected << endl;
                if(isConnected == false)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

void printMessage(bool flag) {
    if(flag) {
        cout<<"The graph is strongly connected"<<endl;
    } 
    else
    {
        cout<<"The graph is not strongly connected"<<endl;
    }
}
 
int main(int argc, char** argv)
{
    
    /*
        Test case 1
    */
    Graph g1;
    g1.addVertex("Aurora");
    g1.addVertex("Bloomington");
    g1.addVertex("Cheyenne");
    g1.addVertex("Denver");
    g1.addVertex("Fruita");
    g1.addEdge("Aurora", "Bloomington");
    g1.addEdge("Bloomington", "Cheyenne");
    g1.addEdge("Cheyenne","Denver");
    g1.addEdge("Denver","Fruita");
    g1.addEdge("Fruita", "Aurora");

    cout<<"Graph G1: "<<endl;
    g1.displayEdges();
    bool flag = g1.isStronglyConnected();
    printMessage(flag);
    cout<<endl<<endl;
    
    //return 0;

    /*
        Test case 2
    */
    Graph g2;
    g2.addVertex("Amsterdam");
    g2.addVertex("Broomfield");
    g2.addVertex("Calcutta");
    g2.addVertex("Dallas");
    g2.addVertex("Fabens");
    g2.addEdge("Amsterdam", "Broomfield");
    g2.addEdge("Broomfield", "Calcutta");
    g2.addEdge("Calcutta", "Amsterdam");
    g2.addEdge("Broomfield","Dallas");
    g2.addEdge("Dallas","Fabens");
    
    cout<<"Graph G2: "<<endl;
    g2.displayEdges();
    flag = g2.isStronglyConnected();
    printMessage(flag);
    cout<<endl<<endl;

    /*
        Test case 3
    */
    
    Graph g3;
    g3.addVertex("Arlington");
    g3.addVertex("Brisbane");
    g3.addVertex("Chandigarh");
    g3.addVertex("Detroit");
    g3.addEdge("Arlington", "Brisbane");
    g3.addEdge("Arlington", "Chandigarh");
    g3.addEdge("Arlington", "Detroit");
    g3.addEdge("Brisbane", "Arlington");
    g3.addEdge("Brisbane", "Chandigarh");
    g3.addEdge("Brisbane", "Detroit");
    g3.addEdge("Chandigarh","Arlington");
    g3.addEdge("Chandigarh","Brisbane");
    g3.addEdge("Chandigarh", "Detroit");
    g3.addEdge("Detroit", "Arlington");
    g3.addEdge("Detroit", "Brisbane");
    g3.addEdge("Detroit", "Chandigarh");

    cout<<"Graph G3: "<<endl;
    g3.displayEdges();
    flag = g3.isStronglyConnected();
    printMessage(flag);
    cout<<endl<<endl;
    

    /*
        Test case 4
    */
    Graph g4;
    g4.addVertex("Arlington");
    cout<<"Graph G4: "<<endl;
    g4.displayEdges();
    flag = g4.isStronglyConnected();
    printMessage(flag);
    cout<<endl<<endl;

    return 0;
}

