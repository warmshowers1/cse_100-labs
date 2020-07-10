#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
    int i, input;
    cin >> input;
    int arr[input];
    for(i = 0; i < input; i++) cin >> arr[i];
    randoQuick(arr, 0, input-1);
    return 0;
}

int randoSplit(int arr[], int a, int b){
    int r = rand() % (b-a) + a;
    /*
    int hold = arr[r];
    arr[r] = arr[b];
    arr[b] = hold;
    */
    swap(arr[r], arr[b]);
    return part(arr, a, b);
}

void randoQuick(int arr[], int a, int b){
    if(a < b){
        int r = randoSplit(arr, a, b);
        randoQuick(arr, a, half-1);
        randoQuick(arr, half+1, b);
    }
}

int part(int arr[], int a, int b){
    int i, x = a - 1;
    for(i = 0; i <= b-1; i++)
        if(arr[i] <= arr[b]) swap(arr[++x], arr[i]);
    swap(arr[++x], arr[b]);
    return ++x;
}

void swap(int* x, int* y){
    if(*x != *y){
        int hold = *x;
        *x = *y;
        *y = hold;
    }
}
