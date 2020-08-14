#include<iostream>
#include<vector>

// The implementation of this algorithm was made possible 
// through the use of the textbook: ISBN: 978-0-262-03384-8
// on pages 651 - 653

using namespace std;

void bell(vector<int> vert[], int **weight);

int v, e;

int main(){
    int i, j, u, V, w;
    cin >> v >> e;
    int **weight = (int**)malloc(v * sizeof(int*));
    for(i = 0; i < v; i++){
        weight[i] = (int*)malloc(v * sizeof(int));
        for(j = 0; j < v; j++)
            weight[i][j] = INT32_MAX; // Closest number to infinity
    }
    vector<int> vert[v];
    for(i = 0; i < e; i++){
        cin >> u >> V >> w;
        weight[u][V] = w;
        vert[u].push_back(V);
    }
    bell(vert, weight);
    return 0;
}

void bell(vector<int> vert[], int **weight){
    int i, j, k, dist[v]; // Initializes distances of 
    bool noCycle = true;
    long V, UW;
    for(i = 0; i < v; i++){ // each vertex from source 
        dist[i] = INT32_MAX;
    }
    dist[0] = 0;
    for(i = 0; i < (v-1); i++){
        for(j = 0; j < v; j++){ // for each edge
            for(k = 0; k < vert[j].size(); k++){
                V = dist[vert[j][k]];
                UW = (long)dist[j] + (long)weight[j][vert[j][k]];
                if(V > UW){ // Relax
                    dist[vert[j][k]] = dist[j] + weight[j][vert[j][k]];
                }
            }
        }
    }
    for(i = 0; i < v; i++){
        for(j = 0; j < vert[i].size(); j++){
            V = dist[vert[i][j]];
            UW = (long)dist[i] + (long)weight[i][vert[i][j]];
            if(V > UW){
                noCycle = false;
                break;
            }
        }
        if(!noCycle) break;
    }
    if(!noCycle) cout << "FALSE" << endl;
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

