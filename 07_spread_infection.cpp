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

class Pair{
    public:
    int src = 0;
    int time = 0;
    
    Pair(int src, int time){
        this->src = src;
        this->time = time;
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
    
    int src, t;
    cin >> src >> t;
    
    vector<int> visited(v, -1);
    
    queue<Pair> q;
    q.push(Pair(src, 1));
    
    int count = 0;
    
    while(q.size()){
        
        Pair element = q.front();
        q.pop();
        
        // means he is already infected
        if(visited[element.src] != -1){
            continue;
        }
        
        visited[element.src] = element.time;
        if(element.time > t){
            break;
        }
        count++;
        
        for(Edge* edge : graph[element.src]){
            if(visited[edge->nbr] == -1){
                q.push(Pair(edge->nbr, element.time + 1));
            }
        }
    }
    
    cout << count << endl;
    return 0;
}