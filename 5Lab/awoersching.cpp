#include<iostream>
#include<vector>

using namespace std;

void radSort(vector<int> arr[], vector<int> sorted[], int length, int num);
void countSort(vector<int> arr[], vector<int> sorted[], int length, int index);

int main(){
    int i, j, length, num;
    cin >> length;
    vector<int> arr[length], sorted[length];
    for(i = 0; i < length; i++){
        while(arr[i].size() < 10){
            cin >> num;
            if(num >= 0 && num <= 3) arr[i].push_back(num);
            else arr[i].push_back(-1);
        }
    }
    radSort(arr, sorted, length, arr[0].size());
    for(i = 0; i < length; i++){
        for(j = 0; j < arr[0].size(); j++){
            if(arr[0].size() % 2 == 1) cout << sorted[i][j] << ";";
            else cout << arr[i][j] << ";";
        }
        cout << endl;
    }
    return 0;
}

void radSort(vector<int> arr[], vector<int> sorted[], int length, int num){
    for(int i = num - 1; i >= 0; i--){
        if(i % 2 == 1) countSort(arr, sorted, length, i);
        else countSort(sorted, arr, length, i);
    }
}

void countSort(vector<int> arr[], vector<int> sorted[], int length, int index){
    int i, counts[4] = {0, 0, 0, 0};
    for(i = 0; i < length; i++) counts[arr[i][index]]++;
    for(i = 1; i <= 3; i++) counts[i] += counts[i - 1];
    for(i = 0; i < 4; i++) counts[i]--;
    for(i = length - 1; i >= 0; i--) sorted[counts[arr[i][index]]--] = arr[i];
}
