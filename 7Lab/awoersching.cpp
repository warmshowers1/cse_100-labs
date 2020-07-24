#include<iostream>

// The implementation of this algorithm was made possible 
// through the use of the textbook: ISBN: 978-0-262-03384-8
// on pages 360 - 369

using namespace std;

void cutRod(int* p, int n);

int main(){
	int i, n;
	cin >> n;
    int prices[n+1];
	prices[0] = 0; 
	for(i = 1; i <= n; i++) cin >> prices[i];
    cutRod(prices, n);
    return 0;
}

void cutRod(int* prices, int n){
    int i, j, max, rev[n+1], slices[n+1];
    rev[0] = 0;
    for(i = 1; i <= n; i++){
        max = prices[0];
        for(j = 1; j <= i; j++){
            if(max < (prices[j] + rev[i - j])){
                max = (prices[j] + rev[i - j]);
                slices[i] = j;
            }
        }
        rev[i] = max;
    }
    cout << rev[n] << endl;
    while(n > 0){
        cout << slices[n] << " ";
        n -= slices[n];
    }
    cout << "-1" << endl;
}
