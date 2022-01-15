#include <bits/stdc++.h>
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

void BFS(vector<vector<Edge*>> graph, int src){
    queue<pair<int, string>> q;
    
    q.push({src, "" + to_string(src)});
    
    vector<bool> visited(graph.size(), false);
    
    while(q.size()){
        
        pair<int, string> p = q.front();
        q.pop();
        
        if(!visited[p.first]){
            visited[p.first] = true;
            cout << p.first << "@" << p.second << endl;
            
            for(Edge* edge : graph[p.first]){
                int nei = edge->nbr;
                
                if(!visited[nei]){
                    q.push({nei, p.second + to_string(nei)});
                }
            }
        }
    }
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
    
    int src;
    cin >> src;

    BFS(graph, src);
    
}