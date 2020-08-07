#include<iostream>
#include<vector>

// The implementation of this algorithm was made possible 
// through the use of the textbook: ISBN: 978-0-262-03384-8
// on pages 603 - 618

using namespace std;

void transpose(vector<int> g[], vector<int> t[]);
void printArray(vector<int> g[]);
int *dfs(vector<int> g[]);
void dfsv(vector<int> g[], int node, int *time, int start[], int end[], bool visited[]);

int v, e;

int main(){
    cin >> v;
    vector<int> g[v], t[v];
    cin >> e;
    int i, num, edge, *normEnds;
    for(i = 0; i < e; i++){
        cin >> num >> edge;
        // This if statement is primarily an 
        // idiot check for debugging purposes
        if(((num < v) && (num >= 0)) && ((edge < v) && (edge >= 0)))
            g[num].push_back(edge);
        else{ 
            cout << "Try again" << endl;
            --i;
        }
    }
    normEnds = dfs(g);
    return 0;
}

void transpose(vector<int> g[], vector<int> t[]){
    int i, j;
    for(i = 0; i < v; i++){
        for(j = 0; j < g[i].size(); j++)
            t[g[i][j]].push_back(i);
    }
}

void printArray(vector<int> g[]){
    int i, j;
    for(i = 0; i < v; i++){
        cout << i << ":";
        for(j = 0; j < g[i].size(); j++)
            cout << g[i][j] << ",";
        cout << endl;
    }
}

int *dfs(vector<int> g[]){
    bool visited[v];
    int i, time = 0, start[v], *end = (int*)malloc(v * sizeof(int));
    for(i = 0; i < v; i++){
        visited[i] = false;
        start[i] = 0;
        end[i] = 0;
    }
    for(i = 0; i < v; i++){
        if(visited[i] == false){
            dfsv(g, i, &time, start, end, visited);
        }
    }
    return end;
}

void dfsv(vector<int> g[], int node, int *time, int start[], int end[], bool visited[]){
    int j, parent;
    start[node] = ++*(time);
    visited[node] = true;
    for(j = 0; j < g[node].size(); j++){
        if(visited[g[node][j]] == false){
            parent = node;
            dfsv(g, g[node][j], time, start, end, visited);
        }
    }
    end[node] = ++*(time);
}
