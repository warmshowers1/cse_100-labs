#include<iostream>

// The implementation of this algorithm was made possible 
// through the use of the textbook: ISBN: 978-0-262-03384-8
// on pages 360 - 366

using namespace std;

int cutRod(int* p);

int n;

int main(){
	cin >> n;
	int i, p[n+1];
	p[0] = 0; 
	for(i = 1; i <= n; i++) cin >> p[i];
    cout << cutRod(p) << endl;
    return 0;
}

int cutRod(int* p){
    int i, j, max, r[n+1];
    r[0] = 0;
    for(i = 1; i <= n; i++){
        max = p[0];
        for(j = 1; j <= i; j++)
            if(max < (p[j] + r[i - j])) max = (p[j] + r[i - j]);
        r[i] = max;
    }
    return r[n];
}
