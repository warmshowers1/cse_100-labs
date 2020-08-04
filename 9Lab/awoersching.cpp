#include<iostream>
#include<vector>

// The implementation of this algorithm was made possible 
// through the use of the textbook: ISBN: 978-0-262-03384-8
// on pages 428 - 436

using namespace std;

void greed(vector<struct Node> *q);
int min(vector<struct Node> q);

struct Node {
    char letter;
    int freq;
    struct Node* left;
    struct Node* right;

    Node(){
        letter = 0;
        freq = 0;
        left = NULL;
        right = NULL;
    }
    Node(char a, int b){
        letter = a;
        freq = b;
        left = NULL;
        right = NULL;
    }
};

const int n = 6;

int main(){
    int i, input;
    vector<struct Node> q;
    for(i = 0; i < n; i++){
        cin >> input;
        q.push_back(Node('A' + i, input));
    }
    greed(&q);
    return 0;
}

void greed(vector<struct Node> *q){
    Node *z; 
    int i, s = min(*q);
    vector<struct Node>::iterator it = q->begin();
    for(i = 0; i < (n-1); i++){
        z = new Node;
        z->left = new Node((*q)[s].letter, (*q)[s].freq);
        (*q).erase(it + s);
        s = min(*q);
        z->right = new Node((*q)[s].letter, (*q)[s].freq);
        (*q).erase(it + s);
        z->freq = z->left->freq + z->right->freq;
        (*q).push_back(*z);
    }
}

int min(vector<struct Node> q){
    vector<struct Node>::iterator it = q.begin()++;
    int i, p = 0;
    for(i = 1; i < q.size(); i++)
        if(it++->freq < q[p].freq) p = i;
    return p;
}
