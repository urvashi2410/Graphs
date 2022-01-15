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

class Pair{
    public:
    int src = 0;
    int level = 0;
    
    Pair(int src, int level){
        this->src = src;
        this->level = level;
    }
};

bool isbipartite(vector<vector<Edge*>> graph, int src, vector<int>visited){
    queue<Pair> q;
    
    q.push({src, 1});
    
    while(q.size()){
        
        Pair p = q.front();
        q.pop();
        
        if(visited[p.src] != -1){
            if(visited[p.src] == p.level){
                continue;
            }
            else{
                return false;
            }
        }
        
        visited[p.src] = true;
        
        for(Edge* edge : graph[p.src]){
            int nei = edge->nbr;
            if(visited[nei] == -1){
                q.push({nei, p.level + 1});
            }
        }
    }
    return true;
    
}

bool helper(vector<vector<Edge*>> graph){
    vector<int>visited(graph.size(), -1);
    
    for(int i = 0; i < graph.size(); i++){
        if(visited[i] == -1){
            if(isbipartite(graph, i, visited)){
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
    
    if(helper(graph)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    
}