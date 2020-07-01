#include <iostream>

void merge(int arr[], int begin, int middle, int end)
void mergeSort(int arr[], int a, int b)

using namespace std;

int main(){
    int i, length;
    cin >> length; // Asks user how long the array will be
    int arr [length];
    for(i = 0; i < length; i++) cin >> arr[i]; // Creates array from inputs
    mergeSort(arr, 0, length); 
    for(i = 0; i < length; i++) cout << arr[i] << ";"; // Prints sorted array
    cout << endl;
    return 0;
}

void merge(int arr[], int begin, int middle, int end){
    int i, j = 0, k = 0, len = middle - begin + 1, gth = end - middle;
    int first[len], last[gth];
    for(i = begin; i < middle; i++) first[i] = arr[i]; // Watch out for these lines
    for(i = middle; i < end; i++) last[i] = arr[i]; // Watch out for these lines
    for(i = begin; i < end; i++){
        if(first[j] < last[k]){
            arr[i] = first[j++]; // Watch out for these lines
        }
        else{
            arr[i] = last[k++]; // Watch out for these lines
        }
    }
}

void mergeSort(int arr[], int a, int b){
    if(a < b - 1){
        int middle = (a+b)/2;
        mergeSort(arr, a, middle);
        mergeSort(arr, middle + 1, b);
        merge(arr, a, middle, b);
    }
}
