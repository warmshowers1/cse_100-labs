#include<iostream>
#include<vector>

// The implementation of this algorithm was made possible 
// through the use of the textbook: ISBN: 978-0-262-03384-8
// on pages 634 - 636

using namespace std;

int* prim(vector<int> G[], int **weights);
bool search(vector<int> Q, int v);

int verts, edges;

int main(){
    cin >> verts;
    cin >> edges;
    int i, j, u, v, w, *parents;
    int **weights = (int**)malloc(verts * sizeof(int*));
    vector<int> G[verts]; // Graph
    for(i = 0; i < verts; i++)
        weights[i] = (int*)malloc(verts * sizeof(int));
        for(j = 0; j < verts; j++)
            weights[i][j] = -1;
    for(i = 0; i < edges; i++){
        cin >> u >> v >> w;
        G[u].push_back(v);
        G[v].push_back(u); //These are here because
        weights[u][v] = w; 
        weights[v][u] = w; // graph is undirected
    }
    parents = prim(G, weights);
    return 0;
}

int* prim(vector<int> G[], int **weights){
    int i, u, v, min, num, *parents = (int*)malloc(verts * sizeof(int)), keys[verts];
    vector<int> Q;
    for(i = 0; i < verts; i++){
        parents[i] = -1;
        keys[i] = -1;
        Q.push_back(i);
    }
    keys[0] = 0;
    while(Q.empty() == false){
        u = Q[0];
        Q.erase(Q.begin());
        for(i = 0; i < G[u].size(); i++){
            v = G[u][i];
            if((search(Q, v)) && ((weights[u][v] < keys[v] || v == -1))){
                parents[v] = u;
                keys[v] = weights[u][v];
            }
        }
    }
    return parents;
}

bool search(vector<int> Q, int v){
    for(int i : Q)
        if(v == i)
            return true;
    return false;
}
