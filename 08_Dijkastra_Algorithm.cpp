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
    int v;
    string psf;
    int wsf;
    
    Pair(int v, string psf, int wsf){
        this->v = v;
        this->psf = psf;
        this->wsf = wsf;
    }
    
    bool operator<(const class Pair& other) const
    {
        return this->wsf > other.wsf;
    }
};

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
    
    priority_queue<Pair>q;
    
    q.push({src, src + "", 0});
    
    vector<bool> visited(v, false);
    
    while(q.size()){
        Pair element = q.top();
        q.pop();
        
        if(visited[element.v]){
            continue;
        }
        
        visited[element.v] = true;
        
        cout << element.v << " via " << element.psf << " @ " << element.wsf << endl;
        
        for(Edge* edge : graph[element.v]){
            int nei = edge->nbr;
            if(!visited[nei]){
                q.push({nei, element.psf + to_string(nei), element.wsf + edge->wt});
            }
        }
    }
    
    return 0;
    
}