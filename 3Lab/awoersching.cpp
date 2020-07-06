#include <iostream>

using namespace std;

// The implementation of this algorithm was made possible soully 
// through the use of the textbook: ISBN: 978-0-262-03384-8
// on pages 68 - 73

int maxCrossSub(int arr[], int a, int mid, int b);
int maxSub(int arr[], int a, int b);

int main(){
    int i, input;
    cin >> input;
    int arr[input];
    for(i = 0; i < input; i++) cin >> arr[i];
    cout << maxSub(arr, 0, input - 1);
    return 0;
}

int maxCrossSub(int arr[], int a, int mid, int b){
    int i, sub, sumLeft = arr[mid], sumRight = arr[mid + 1], sum = 0;
    for(i = mid; i > a; i--){
        sum += arr[i];
        if(sum > sumLeft) sumLeft = sum;
    }
    sum = 0;
    for(i = mid + 1; i <= b; i++){
        sum += arr[i];
        if(sum > sumRight) sumRight = sum;
    }
    sub = sumLeft + sumRight;
    return sub;
}

int maxSub(int arr[], int a, int b){
    if(a == b) return arr[a];
    int left = maxSub(arr, a, (a+b)/2), center = maxCrossSub(arr, a, (a+b)/2, b), right = maxSub(arr, ((a+b)/2) + 1, b);
    if(left > center && left > right) return left;
    else if(center > right && center > left) return center;
    else return right;
}
