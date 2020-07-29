#include<iostream>

// The implementation of this algorithm was made possible 
// through the use of the textbook: ISBN: 978-0-262-03384-8
// on pages 370 - 389

using namespace std;

void matChain(int arr[]);
int lookup(int arr[], int** m, int** s, int i, int j);
void printOptimal(int** s, int i, int j);

int n;

int main(){
    cin >> n;
    int i = 0, arr[n+1];
    while(i <= n) cin >> arr[i++];
    matChain(arr);
    return 0;
}

void matChain(int arr[]){
    int i, j;
    int **m = new int*[n], **s = new int*[n];
    for(i = 0; i < n; i++){
        m[i] = new int[n];
        s[i] = new int[n];
    }
    for(i = 0; i < n; i++)
        for(j = i; j < n; j++)
            m[i][j] = -1;
    cout << lookup(arr, m, s, 0, n-1) << endl;
    printOptimal(s, 0, n-1);
    cout << endl;
}

int lookup(int arr[], int** m, int** s, int i, int j){
    int k, q;
    if(m[i][j] > -1) return m[i][j];
    if(i == j) m[i][j] = 0;
    else{
        for(k = i; k < j; k++){
            q = lookup(arr, m, s, i, k) + lookup(arr, m, s, k+1, j) + (arr[i] * arr[k+1] * arr[j+1]);
            if((m[i][j] == -1) || (m[i][j] > q)){
                m[i][j] = q;
                s[i][j] = k;
            }
        }
    }
    return m[i][j];
}

void printOptimal(int** s, int i, int j){
    if(i == j) cout << "A" << i; 
    else{
        cout << "(";
        printOptimal(s, i, s[i][j]);
        printOptimal(s, ++s[i][j], j);
        cout << ")";
   }
}
