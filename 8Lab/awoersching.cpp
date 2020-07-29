#include<iostream>

// The implementation of this algorithm was made possible 
// through the use of the textbook: ISBN: 978-0-262-03384-8
// on pages 370 - 377

using namespace std;

void matChain(int arr[], int* s[]);
void printMatrix(int** arr, int p, int q);

int n;

int main(){
    cin >> n;
    int i = 0, arr[n+1];
    while(i <= n) cin >> arr[i++];
    int* s[n-1];
    matChain(arr, s);
    return 0;
}

void matChain(int arr[], int* s[]){
    int i, j, k, l, q, m[n-1][n-1];
    for(i = 0; i < (n-1); i++) m[i][i] = 0;
    // This be where the magic happens
    for(l = 2; l <= n; l++){
        for(i = 1; i < (n-l+1); i++){
            j = i + l - 1;
            m[i][j] = -1;
            for(k = i; k < j; k++){
                q = m[i][k] + m[(k+1)][j] + (arr[i-1] * arr[k] * arr[j]);
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    printMatrix(s, n-1, n);
}

void printMatrix(int** arr, int p, int q){
    for(int i = 0; i < p; i++){
        for(int j = 0; j < q; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
