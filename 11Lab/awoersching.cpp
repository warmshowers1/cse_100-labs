#include<iostream>
#include<vector>

// The implementation of this algorithm was made possible 
// through the use of the textbook: ISBN: 978-0-262-03384-8
// on pages 634 - 636

using namespace std;

int verts, edges;

int main(){
    cin >> verts;
    cin >> edges;
    int i, j, u, v, w, *parents, weights[verts][verts]; // Weights list
    vector<int> G[verts]; // Graph
    for(i = 0; i < verts; i++)
        for(j = 0; j < verts; j++)
            weights[i][j] = -1;
    for(i = 0; i < edges; i++){
        cin >> u >> v >> w;
        graph[u].push_back(v);
        graph[v].push_back(u); //These are here because
        weights[u][v] = w; 
        weights[v][u] = w; // graph is undirected
    }
    return 0;
}

