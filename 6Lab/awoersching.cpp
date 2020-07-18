#include<iostream>
#include<list>
#include<string>
#include<math.h>

// The implementation of this algorithm was made possible 
// using the textbook: ISBN: 978-0-262-03384-8
// on pages 256 - 269
// as well as some research on linked lists from cites such
// as: www.cplusplus.com/reference/list/list
// and https://www.geeksforgeeks.org/list-cpp-stl

using namespace std;

int h(int k);
void i(list<int> arr[], int k);
void d(list<int> arr[], int k);
void s(list<int> arr[], int k);
void o(list<int> arr[]);
int strToInt(string str);

int m;

int main(){
    cin >> m;
    list<int> arr[m];
    string input = "";
    while(input.front() != 'e' && input.front() != 'E'){
        cin >> input;
        if(input.front() == 'i' || input.front() == 'I') i(arr, strToInt(input.substr(1, input.length())));
        else if(input.front() == 'd' || input.front() == 'D') d(arr, strToInt(input.substr(1, input.length())));
        else if(input.front() == 's' || input.front() == 'S') s(arr, strToInt(input.substr(1, input.length())));
        else if(input.front() == 'o' || input.front() == 'O') o(arr);
    }
    return 0;
}

int h(int k){return k % m;}

void i(list<int> arr[], int k){arr[h(k)].push_front(k);}

void d(list<int> arr[], int k){
    list<int>::iterator i;
    bool found = false;
    for(i = arr[h(k)].begin(); i != arr[h(k)].end(); i++){
        if(*i == k){ 
            arr[h(k)].erase(i);
            cout << k << ":DELETED;" << endl;
            found = true;
            break;
        }
    }
    if(!found) cout << k << ":DELETE_FAILED;" << endl;
}

void s(list<int> arr[], int k){
    list<int>::iterator i;
    int j = 0;
    bool found = false;
    for(i = arr[h(k)].begin(); i != arr[h(k)].end(); i++){
        if(*i == k){
            cout << k << ":FOUND_AT" << h(k) << "," << j << ";" << endl;
            found = true;
            break;
        }
        j++;
    }
    if(!found) cout << k << ":NOT_FOUND;" << endl;
}

void o(list<int> arr[]){
    list<int>::iterator j;
    for(int i = 0; i < m; i++){
        cout << i << ":";
        for(j = arr[i].begin(); j != arr[i].end(); j++) cout << *j << "->";
        cout << ";" << endl;
    }
}

int strToInt(string str){
    int i, j, result = 0;
    for(i = str.length() - 1; i >= 0; i--) result += ((((int) str[i]) - 48) * pow(10, str.length() - i - 1));
    return result;
}
