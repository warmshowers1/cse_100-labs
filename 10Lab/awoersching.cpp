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
int *endTimeOrder(int normEnds[]);
int *dfsTPose(vector<int> t[], int foo[]);

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
    transpose(g, t);
    normEnds = dfs(g);
    int *normEndOrder = endTimeOrder(normEnds);
    int *bar = dfsTPose(t, normEndOrder);
    for(i = 0; i < v; i++) cout << bar[i] << ",";
    cout << endl;
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

void dfsv(vector<int> g[], int vertex, int *time, int start[], int end[], bool visited[]){
    int j, parent;
    start[vertex] = ++*(time);
    visited[vertex] = true;
    for(j = 0; j < g[vertex].size(); j++){
        if(visited[g[vertex][j]] == false){
            parent = vertex;
            dfsv(g, g[vertex][j], time, start, end, visited);
        }
    }
    end[vertex] = ++*(time);
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

int *dfsTPose(vector<int> t[], int foo[]){
    bool visited[v];
    int i, time = 0, start[v], *end = (int*)malloc(v * sizeof(int));
    for(i = 0; i < v; i++){
        visited[i] = false;
        start[i] = 0;
        end[i] = 0;
    }
    for(i = 0; i < v; i++){
        if(visited[foo[i]] == false){
            dfsv(t, foo[i], &time, start, end, visited);
        }
    }
    return end;
}
