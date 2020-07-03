#include <iostream>

using namespace std;

/* The implementation of this algorithm was made possible soully 
 * through the use of the textbook: ISBN: 978-0-262-03384-8
 */

void merge(int arr[], int begin, int middle, int end);
void mergeSort(int arr[], int a, int b);

int main(){
    int i, length;
    cin >> length; // Asks user how long the array will be
    int arr [length];
    for(i = 0; i < length; i++) cin >> arr[i]; // Creates array from inputs
    mergeSort(arr, 0, length-1); 
    for(i = 0; i < length; i++) cout << arr[i] << ";"; // Prints sorted array
    return 0;
}

void merge(int arr[], int begin, int middle, int end){
    int i, j = 0, k = 0, len = middle - begin + 1, gth = end - middle;
    int first[len], last[gth];
    for(i = 0; i < len; i++) first[i] = arr[begin + i]; // Watch out for these lines
    for(i = 0; i < gth; i++) last[i] = arr[i + middle + 1]; // Watch out for these lines
    for(i = begin; i <= end; i++){
	if(j < len && k < gth){
            if(first[j] < last[k]) arr[i] = first[j++]; // Watch out for these lines
            else arr[i] = last[k++]; // Watch out for these lines
	}
	else if(j == len) arr[i] = last[k++];
	else arr[i] = first[j++];
    }
}

void mergeSort(int arr[], int a, int b){
    if(a < b){
        int middle = (a+b)/2;
        mergeSort(arr, a, middle);
        mergeSort(arr, middle + 1, b);
        merge(arr, a, middle, b);
    }
}
