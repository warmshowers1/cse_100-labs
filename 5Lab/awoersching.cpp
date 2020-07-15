#include<iostream>
#include<vector>

using namespace std;

void insertSort(vector<int> arr[], int length, int index);
void radSort(vector<int> arr[], int length);

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

void radSort(vector<int> arr[], int num){
    for(int i = num - 1; i >= 0; i--){
        insertSort(arr, num, i);
    }
}

void insertSort(vector<int> arr[], int num, int index){
    int i, marker;
	for(i = 1; i < num; i++){
		marker = i;
		while((arr[i][index] < arr[marker - 1][index]) && marker > 0) marker -= 1;
		if(marker != i) arr[i].swap(arr[marker]);
	}
}
