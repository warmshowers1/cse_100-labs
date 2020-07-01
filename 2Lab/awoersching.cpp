#include <iostream>

using namespace std;

void merge(int arr[], int begin, int middle, int end);
void mergeSort(int arr[], int a, int b);

int main(){
    int i, length;
    cin >> length; // Asks user how long the array will be
    int arr [length];
    for(i = 0; i < length; i++) cin >> arr[i]; // Creates array from inputs
    mergeSort(arr, 0, length-1); 
    for(i = 0; i < length; i++) cout << arr[i] << ";"; // Prints sorted array
    cout << endl;
    return 0;
}

void merge(int arr[], int begin, int middle, int end){
    int i, j = 0, k = 0, len = middle - begin + 1, gth = end - middle;
    int first[len], last[gth];
    for(i = 0; i < middle; i++) first[i] = arr[i]; // Watch out for these lines
    for(i = 0; i < end; i++) last[i] = arr[i]; // Watch out for these lines
    for(i = begin; i < end; i++){
        if(first[j] < last[k]){
            arr[i] = first[j]; // Watch out for these lines
            j++;
        }
        else{
            arr[i] = last[k]; // Watch out for these lines
            k++;
        }
    }
}

void mergeSort(int arr[], int a, int b){
    if(a < b){
        int middle = (a+b)/2;
        mergeSort(arr, a, middle);
        mergeSort(arr, middle + 1, b-1);
        merge(arr, a, middle, b);
    }
}
