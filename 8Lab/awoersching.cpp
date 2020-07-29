#include<iostream>

// The implementation of this algorithm was made possible 
// through the use of the textbook: ISBN: 978-0-262-03384-8
// on pages 370 - 389

using namespace std;

int n;

int matChain(int arr[]);
int lookup(int arr[], int** m, int i, int j);
void printMatrix(int** arr, int p, int q);
void printOptimal(int* s[], int i, int j);

int main(){
    cin >> n;
    int i = 0, arr[n+1];
    while(i <= n) cin >> arr[i++];
    cout << matChain(arr) << endl;
    return 0;
}

int matChain(int arr[]){
    int i, j;
    int** m = new int*[n];
    for(i = 0; i < n; i++) m[i] = new int[n];
    for(i = 0; i < n; i++)
        for(j = i; j < n; j++)
            m[i][j] = -1;
    return lookup(arr, m, 0, n-1);
}

int lookup(int arr[], int** m, int i, int j){
    int k, q;
    if(m[i][j] > -1) return m[i][j];
    if(i == j) m[i][j] = 0;
    else{
        for(k = i; k < j; k++){
            q = lookup(arr, m, i, k) + lookup(arr, m, k+1, j) + (arr[i] * arr[k+1] * arr[j+1]);
            if((m[i][j] == -1) || (m[i][j] > q)) m[i][j] = q;
        }
    }
    return m[i][j];
}

void printMatrix(int** arr, int p, int q){
    for(int i = 0; i < p; i++){
        for(int j = 0; j < q; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

void printOptimal(int* s[], int i, int j){
   if(i == j) cout << "A" << i; 
   else{
       cout << "(";
       printOptimal(s, i, s[i][j]);
       printOptimal(s, ++s[i][j], j);
       cout << ")";
   }
   cout << endl;
}
