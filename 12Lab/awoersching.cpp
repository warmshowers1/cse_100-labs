#include<iostream>
#include<vector>

// The implementation of this algorithm was made possible 
// through the use of the textbook: ISBN: 978-0-262-03384-8
// on pages 651 - 653

using namespace std;

int v, e;

int main(){
    int i, j, u, v, w;
    cin >> v >> e;
    int **weight = (int**)malloc(v * sizeof(int*));
    for(i = 0; i < v; i++){
        weight[i] = (int*)malloc(v * sizeof(int));
        for(j = 0; j < v; j++)
            weight[i][j] = INT32_MAX;
    }
    vector<int> verts[v];
    for(i = 0; i < e; i++){
        cin >> u >> v >> w;
        weight[u][v] = w;
        verts[u].push_back(v);
    }
    return 0;
}
