#include<iostream>
#include<vector>

// The implementation of this algorithm was made possible 
// through the use of the textbook: ISBN: 978-0-262-03384-8
// on pages 634 - 636

using namespace std;

int* prim(vector<int> G[], int **weights);
int findMinVert(vector<int> Q, int *keys);
bool search(vector<int> Q, int v);

int verts, edges;

int main(){
    cin >> verts;
    cin >> edges;
    int i, j, u, v, w, *parents;
    vector<int> G[verts]; // Graph
    int **weights = (int**)malloc(verts * sizeof(int*));
    for(i = 0; i < verts; i++){
        weights[i] = (int*)malloc(verts * sizeof(int));
        for(j = 0; j < verts; j++)
            weights[i][j] = -1;
    }
    for(i = 0; i < edges; i++){
        cin >> u >> v >> w;
        G[u].push_back(v);
        G[v].push_back(u); //These are here because
        weights[u][v] = w; 
        weights[v][u] = w; // graph is undirected
    }
    parents = prim(G, weights);
    for(i = 1; i < verts; i++) cout << parents[i] << endl;
    return 0;
}

int* prim(vector<int> G[], int **weights){
    int i, u, min, *parents = (int*)malloc(verts * sizeof(int)), *keys = (int*)malloc(verts * sizeof(int));
    vector<int> Q;
    for(i = 0; i < verts; i++){
        parents[i] = -1;
        keys[i] = INT32_MAX;
        Q.push_back(i);
    }
    keys[0] = 0;
    while(Q.empty() == false){
        min = findMinVert(Q, keys);
        u = Q[min];
        Q.erase(Q.begin() + min);
        for(i = 0; i < G[u].size(); i++){
            if((search(Q, G[u][i]) == true) && weights[u][G[u][i]] < keys[G[u][i]]){
                parents[G[u][i]] = u;
                keys[G[u][i]] = weights[u][G[u][i]];
            }
        }
    }
    return parents;
}

int findMinVert(vector<int> Q, int *keys){
    int i, m = 0, num = keys[Q.front()];
    for(i = 0; i < Q.size(); i++){
        if(keys[Q[i]] < num){
            num = keys[Q[i]];
            m = i;
        }
    }
    return m;
}

bool search(vector<int> Q, int v){
    for(int i = 0; i < Q.size(); i++)
        if(v == Q[i]) return true;
    return false;
}

