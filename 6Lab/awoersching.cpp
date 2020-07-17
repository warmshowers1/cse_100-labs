#include<iostream>
#include<list>
#include<string>

// The implementation of this algorithm was made possible 
// using the textbook: ISBN: 978-0-262-03384-8
// on pages 256 - 269
// as well as some research on linked lists from cites such
// as: www.cplusplus.com/reference/list/list
// and https://www.geeksforgeeks.org/list-cpp-stl

using namespace std;

int h(int k);
void i(list<int> arr, int k);
void d(list<int> arr[], int k);
void s(list<int> arr[], int k);
void o(list<int> arr[]);

int m;

int main(){
    cin >> m;
    list<int> arr[m];
    string input = "";
    while(input != "e" || input != "E"){
        cin >> input;
        
    }
    return 0;
}

int h(int k){
    return k % m;
}

void i(list<int> arr[], int k){
    arr[h(k)].push_front(k);
}

void d(list<int> arr[], int k){
    list<int>::iterator i;
    for(i = arr[h(k)].begin(); i != arr[h(k)].end(); ++i){ // Watch this
        if(*i == k) arr[h(k)].erase(i);
        cout << k << ":DELETED;" << endl;
    }
    if(*i == *arr[h(k)].end()) cout << k << ":DELETE_FAILED;" << endl;
}

void s(list<int> arr[], int k){
    list<int>::iterator i;
    int j = 0;
    for(i = arr[h(k)].begin(); i != arr[h(k)].end(); ++i){ // Watch this
        if(*i == k){
            cout << k << ":FOUND_AT" << h(k) << j << ";" << endl;
            break;
        }
        j++;
    }
    if(*i == *arr[h(k)].end()) cout << k << ":NOT_FOUND;" << endl;
}

void o(list<int> arr[]){
    list<int>::iterator j;
    for(int i = 0; i < m; i++){
        cout << i << ":";
        for(j = arr[i].begin(); j != arr[i].end(); ++j) cout << *j << "->";
        cout << ";" << endl;
    }
}
