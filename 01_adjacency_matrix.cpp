#include<bits/stdc++.h>
using namespace std;

int adjMat[4][4];

// bidirectional
void addEdge(int u, int v){
    adjMat[u][v] = 1;
    adjMat[v][u] = 1;
}

void printGraph(int V){
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int V = 4;
    
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(0, 3);
    addEdge(1, 2);
    addEdge(2, 3);
    printGraph(V);
    return 0;
}