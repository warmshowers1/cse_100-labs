#include<iostream>

// The implementation of this algorithm was made possible 
// through the use of the textbook: ISBN: 978-0-262-03384-8
// on pages 428 - 436

using namespace std;

void greed(int arr[]);

struct node {
    int freq;
    struct node* left;
    struct node* right;
};

int main(){
    int i;
    final int n = 6;
    node arr[n];
    for(i = 0; i < n; i++) cin >> arr[i].freq;
    greed(arr, n);
    return 0;
}

void greed(int arr[], int l){
    
}

