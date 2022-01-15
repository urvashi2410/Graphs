#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int src;
    int nbr;
    int wt;
    
    Edge(int src, int nbr, int wt){
        this->src = src;
        this->nbr = nbr;
        this->wt = wt;
    }
};

bool hasPath(vector<vector<Edge*>> graph, int src, int des, vector<bool>visited){
    if(src == des){
        return true;
    }
    
    visited[src] = true;
    for(Edge* edge: graph[src]){
        int nei = edge->nbr;
        
        if(!visited[nei]){
            if(hasPath(graph, nei, des, visited)){
                return true;
            }
        }
    }
    return false;
}


int main(){
    int v, e;
    cin >> v >> e;
    
    vector<vector<Edge*>> graph(v, vector<Edge*>());
    for(int i = 0; i < e; i++){
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        
        Edge* e1 = new Edge(v1, v2, wt);
        Edge* e2 = new Edge(v2, v1, wt);
        
        graph[v1].push_back(e1);
        graph[v2].push_back(e2);
        
    }
    
    vector<bool> visited(v, false);
    int src, des;
    cin >> src >> des;
    
    if(hasPath(graph,  src, des, visited)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
}