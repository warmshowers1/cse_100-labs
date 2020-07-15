#include<iostream>
#include<vector>

using namespace std;

int main(){
    int i, j, length, num;
    cin >> length;
    vector<int> arr[length];
    for(i = 0; i < length; i++){
        while(arr[i].size() < 10){
            cin >> num;
            if(num >= 0 && num <= 3) arr[i].push_back(num);
            else arr[i].push_back(-1);
        }
    }
    radSort(arr, 10);
    for(i = 0; i < length; i++)
        for(j = 0; j < 10; j++)
            cout << arr[i][j] << ";" << endl;
    return 0;
}

void radSort(vector<int> arr[], int digit){
    for(int i = 0; i < digit; i++){
        
    }
}
