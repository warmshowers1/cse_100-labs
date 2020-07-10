#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The implementation of this algorithm was made possible soully 
// through the use of the textbook: ISBN: 978-0-262-03384-8
// on pages 170 - 180

using namespace std;

int randoSplit(int arr[], int a, int b);
void randoQuick(int arr[], int a, int b);
int part(int arr[], int a, int b);
void swap(int* x, int* y);

int main(){
    int i, input;
    cin >> input;
    int arr[input];
    for(i = 0; i < input; i++) cin >> arr[i];
    randoQuick(arr, 0, input-1);
    for(i = 0; i < input; i++) cout << arr[i] << ";";
    return 0;
}

int randoSplit(int arr[], int a, int b){
    int r = rand() % (b-a) + a;
    swap(arr[r], arr[b]);
    return part(arr, a, b);
}

void randoQuick(int arr[], int a, int b){
    if(a < b){
        int r = randoSplit(arr, a, b);
        randoQuick(arr, a, r-1);
        randoQuick(arr, r+1, b);
    }
}

int part(int arr[], int a, int b){
    int i, x = a - 1;
    for(i = a; i < b; i++)
        if(arr[i] <= arr[b]) swap(arr[++x], arr[i]);
    swap(arr[++x], arr[b]);
    return x;
}

void swap(int* x, int* y){
    if(*x != *y){
        int hold = *x;
        *x = *y;
        *y = hold;
    }
}
