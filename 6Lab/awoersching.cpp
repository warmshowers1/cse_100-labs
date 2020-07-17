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

int h(int k, int m);
void i(list<int> arr, int k, int m);

int main(){
    int m;
    cin >> m;
    list<int> arr[m];
    string input = "";
    while(input != "e" || input != "E"){
        cin >> input;
        
    }
    return 0;
}

int h(int k, int m){
    return k % m;
}

void i(list<int> arr[], int k, int m){
    arr[h(k, m)].push_front(k);
}

void d(list<int> arr[], int k, int m){
    list<int>::iterator i;
    for(i = arr[h(k, m)].begin(); i != arr[h(k, m)].end(); ++i){ // Watch this
        if(*i == k) arr[h(k, m)].erase(i);
        cout << k << ":DELETED;" << endl;
    }
    if(*i == *arr[h(k, m)].end()) cout << k << ":DELETE_FAILED;" << endl;
}
