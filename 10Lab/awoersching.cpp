#include<iostream>
#include<vector>

// The implementation of this algorithm was made possible 
// through the use of the textbook: ISBN: 978-0-262-03384-8
// on pages ### - ###

using namespace std;

void transpose(vector<int> g[], vector<int> t[]);
void printArray(vector<int> g[]);

int v, e;

int main(){
    cin >> v;
    vector<int> g[v], t[v];
    cin >> e;
    int i, num, edge;
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
    printArray(g);
    printArray(t);
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
