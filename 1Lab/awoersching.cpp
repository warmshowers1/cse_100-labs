#include<iostream>

using namespace std;

int main(){
	int i, j, input, length, holder; // Declares necessary variables
	std::cin >> length; // Asks for length of array to be sorted
	int arr [length]; // Creates empty array of correct size
	// Inserts each inputted integer into the array
	for(i = 0; i < length; i++){
		std::cin >> input;
		arr[i] = input;
	}
	// Sorts arr (NOTE: 'input' is now being used as a marker, not as input from the user)
	for(i = 1; i < length; i++){
		input = i;
		while((arr[i] < arr[input - 1]) && input > 0) input -= 1;
		// If the number being observed needs to be relocated, then do this
		if(input != i){
			holder = arr[i];
			for(j = i; j > input; j--){
				arr[j] = arr[j - 1];
			}
			arr[input] = holder;
		}
		// Prints the sorted array with each iteration
		for(j = 0; j <= i; j++) std::cout << arr[j] << ";";
		std::cout << endl;
	}
	return 0;
}
