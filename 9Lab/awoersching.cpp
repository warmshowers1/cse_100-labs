#include<iostream>
#include<vector>
#include<string>

// The implementation of this algorithm was made possible 
// through the use of the textbook: ISBN: 978-0-262-03384-8
// on pages 428 - 436

using namespace std;

struct Node* greed(vector<struct Node> *q);
int min(vector<struct Node> q);
void findCodes(struct Node *root, string codes[], string code);

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
    Node(char a, int b, Node *c, Node *d){
        letter = a;
        freq = b;
        left = c;
        right = d;
    }
};

const int n = 6;

int main(){
    int i, input;
    string codes[n];
    vector<struct Node> q;
    for(i = 0; i < n; i++){
        cin >> input;
        q.push_back(Node('A' + i, input));
    }
    findCodes(greed(&q), codes, "");
    return 0;
}

struct Node* greed(vector<struct Node> *q){
    Node *z; 
    int i, s;
    for(i = 0; i < (n-1); i++){
        z = new Node;
        s = min(*q);
        z->left = new Node((*q)[s].letter, (*q)[s].freq, (*q)[s].left, (*q)[s].right);
        (*q).erase(q->begin() + s);
        s = min(*q);
        z->right = new Node((*q)[s].letter, (*q)[s].freq, (*q)[s].left, (*q)[s].right);
        (*q).erase(q->begin() + s);
        z->freq = z->left->freq + z->right->freq;
        (*q).push_back(*z);
    }
    return z;
}

int min(vector<struct Node> q){
    vector<struct Node>::iterator it = ++q.begin();
    int i, p = 0;
    for(i = 1; i < q.size(); i++)
        if(it++->freq < q[p].freq) p = i;
    return p;
}

void findCodes(struct Node* root, string codes[], string code){
    if(root->letter != 0) codes[(int) (root->letter - 65)] = code;
    else{
        findCodes(root->left, codes, code + "0");
        findCodes(root->right, codes, code + "1");
    }
    if(code == ""){
        for(int i = 0; i < n; i++)
            cout << (char)('A' + i) << ":" << codes[i] << endl;
    }
}

