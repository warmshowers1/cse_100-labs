#include <iostream>

// The implementation of this algorithm was made possible soully 
// through the use of the textbook: ISBN: 978-0-262-03384-8
// on pages 151 - 161

using namespace std;

int left(int i);
int right(int i);
int parent(int i);

int main(){
    int i, input;
    cin >> input;
    int arr[input];
    for(i = 0; i < input; i++) cin >> arr[i];
    
    return 0;
}

void max-heap(int arr[], int size, int x){
    int big;
    if(left(x) <= size && arr[left(x)] > arr[right(x)]) big = left(x);
    else big = x;
    if(right(x) <= size && arr[right(x)] > arr[big]) big = right(x);
    if(big != x){
        swap(arr[x], arr[big]);
        max-heap(arr, size, big);
    }
}

int left(int i) return 2*i;
int right(int i) return 2*i + 1;
int parent(int i) return i/2;

void swap(int* x, int* y){
    if(*x != *y){
        int hold = *x;
        *x = *y;
        *y = hold;
    }
}
