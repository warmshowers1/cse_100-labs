#include<iostream>
#include<vector>

// The implementation of this algorithm was made possible 
// through the use of the textbook: ISBN: 978-0-262-03384-8
// on pages 603 - 618

using namespace std;

void transpose(vector<int> g[], vector<int> t[]);
int *dfs(vector<int> g[]);
void dfsv(vector<int> g[], int node, int *time, int end[], bool visited[]);
int *dfsTPose(vector<int> t[], int foo[]);
int *endTimeOrder(int normEnds[]);

int v, e;

int main(){
    cin >> v;
    vector<int> g[v], t[v];
    cin >> e;
    int i, num, edge, *normEnds, *tPoseEnds, sccids[v];
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
    transpose(g, t);
    normEnds = dfs(g);
    int *normEndOrder = endTimeOrder(normEnds);
    tPoseEnds = dfsTPose(t, normEndOrder);
    int *tPoseEndOrder = endTimeOrder(tPoseEnds);
    return 0;
}

void transpose(vector<int> g[], vector<int> t[]){
    int i, j;
    for(i = 0; i < v; i++){
        for(j = 0; j < g[i].size(); j++)
            t[g[i][j]].push_back(i);
    }
}

int *dfs(vector<int> g[]){
    bool visited[v];
    int i, time = 0, *end = (int*)malloc(v * sizeof(int));
    for(i = 0; i < v; i++){
        visited[i] = false;
        end[i] = 0;
    }
    for(i = 0; i < v; i++){
        if(visited[i] == false){
            dfsv(g, i, &time, end, visited);
        }
    }
    return end;
}

void dfsv(vector<int> g[], int vertex, int *time, int end[], bool visited[]){
    int j, parent;
    ++*(time);
    visited[vertex] = true;
    for(j = 0; j < g[vertex].size(); j++){
        if(visited[g[vertex][j]] == false){
            parent = vertex;
            dfsv(g, g[vertex][j], time, end, visited);
        }
    }
    end[vertex] = ++*(time);
}

int *dfsTPose(vector<int> t[], int foo[]){
    bool visited[v];
    int i, time = 0, *end = (int*)malloc(v * sizeof(int));
    for(i = 0; i < v; i++){
        visited[i] = false;
        end[i] = 0;
    }
    for(i = 0; i < v; i++){
        if(visited[foo[i]] == false)
            dfsv(t, foo[i], &time, end, visited);
    }
    return end;
}

int *endTimeOrder(int normEnds[]){
    int i, j, *foo = (int*)malloc(v * sizeof(int));
    for(i = 0; i < v; i++){
        foo[i] = -1;
        for(j = 0; j < v; j++){
            if((normEnds[j] > normEnds[foo[i]]) && ((i > 0) && (normEnds[j] < normEnds[foo[i-1]])))
                foo[i] = j;
            else if((i == 0) && (normEnds[j] > normEnds[foo[i]]))
                foo[i] = j;
        }
    }
    return foo;
}

