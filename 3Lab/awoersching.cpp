#include <iostream>

using namespace std;

int* maxCrossSub(int arr[], int a, int mid, int b);
int* maxSub(int arr[], int a, int b);

int main(){
    int i, input;
    cin >> input;
    int arr[input];
    for(i = 0; i < input; i++) cin >> arr[i];
    // int params[3] = maxSub(arr, 0, input);
    // cout << params[2];
    cout << maxSub(arr, 0, input)[2];
    return 0;
}

int* maxCrossSub(int arr[], int a, int mid, int b){
    // sub[3] = {maxLeft, maxRight, sumLeft + sumRight};  Remember this.
    int i, sumLeft = NULL, sumRight = NULL, sum = 0;
    int sub[3] = {mid, mid + 1, NULL};
    for(i = mid; i > a; i--){
        sum += arr[i];
        if(sum > sumLeft || sumLeft == NULL){
            sumLeft = sum;
            sub[0] = i;
        }
    }
    sum = 0;
    for(i = mid + 1; i < b; i++){
        sum += arr[i];
        if(sum > sumRight || sumRight == NULL){
            sumRight = sum;
            sub[1] = i;
        }
    }
    sub[2] = sumLeft + sumRight;
    return sub;
}

int* maxSub(int arr[], int a, int b){
    if(a == b){ 
        int soln[3] = {a, b, arr[a]};
        return soln;
    }
    int mid = (a+b)/2;
    int left[3] = maxSub(arr, a, mid), center[3] = maxCrossSub(arr, a, mid, b), right[3] = maxSub(arr, mid + 1, b);
    // left = {leftLow, leftHigh, leftSum}
    // center = {centerLow, centerHigh, centerSum}
    // right = {rightLow, rightHigh, rightSum}
    if(left[2] > center[2] && left[2] > right[2]) return left;
    else if(center[2] > right[2] && center[2] > left[2]) return center;
    else return right;
}
