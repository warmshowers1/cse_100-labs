#include<iostream>
#include<vector>

// The implementation of this algorithm was made possible 
// through the use of the textbook: ISBN: 978-0-262-03384-8
// on pages 651 - 653

using namespace std;

void bell(vector<int> vert[], int **weight);

int v, e;

int main(){
    int i, j, u, v, w;
    cin >> v >> e;
    int **weight = (int**)malloc(v * sizeof(int*));
    for(i = 0; i < v; i++){
        weight[i] = (int*)malloc(v * sizeof(int));
        for(j = 0; j < v; j++)
            weight[i][j] = INT32_MAX; // Closest number to infinity
    }
    vector<int> vert[v];
    for(i = 0; i < e; i++){
        cin >> u >> v >> w;
        weight[u][v] = w;
        vert[u].push_back(v);
    }
    bell(vert, weight);
    return 0;
}

void bell(vector<int> vert[], int **weight){
    int i, j, k, dist[v], parent[v]; // Initializes distances of each vertex 
    bool noCycle = true;
    for(i = 0; i < v; i++){ // from source and parents of each vertex
        dist[i] = INT32_MAX;
        parent[i] = -1;
    }
    dist[0] = 0;
    for(i = 0; i < (v-1); i++){
        for(j = 0; j < v; j++){ // for each edge
            for(k = 0; k < vert[j].size(); k++){
                if(dist[k] > (dist[j] + weight[j][k])){ // Relax
                    dist[k] = dist[j] + weight[j][k];
                    parent[k] = j;
                }
            }
        }
    }
    for(i = 0; i < v; i++){
        for(j = 0; j < vert[i].size(); j++){
            if(dist[j] > (dist[i] + weight[i][j])){
                noCycle = false;
                break;
            }
        }
        if(noCycle == false) break;
    }
    if(noCycle) cout << "FALSE" << endl;
    else{
        cout << "TRUE" << endl;
        for(i = 0; i < v; i++){
            if(dist[i] == INT32_MAX)
                cout << "INFINITY" << endl;
            else
                cout << dist[i] << endl;
        }
    }
}

