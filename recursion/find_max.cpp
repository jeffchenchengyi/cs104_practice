#include <iostream>
#include <stdlib.h>

using namespace std;

int max(int arr[], int, int);

int main (int argc, char* argv[])
{
  if(argc < 2){
    cerr << "Please provide a list of integers separated by whitespace." << endl;
    return 1;
  }

  //Dynamically allocating memory according to how many 
  //integers user types
  int* input_arr = new int[argc - 1];

  //Storing each integer user types in the dynamically 
  //allocated array
  for(int i = 1; i < argc; i++) {
  	input_arr[i - 1] = atoi(argv[i]);
  }

  //Output Max
  cout << "The largest value out of all the inputs is:" << endl;
  cout << max(input_arr, 0, (argc - 1)) << endl;

  //Deallocating memory
  delete [] input_arr;

  return 0;
}

int max(int arr[], int low, int high) {
	//Base Case 1: Only one value left
	if(low == high) {
		return arr[low];
	} 
	//Recursive Case: Find max on left side of array
	//Find max from right side on array
	//Compare them and return
	else {
		int mid = (low + high) / 2;
		int left = max(arr, low, mid); 
		int right = max(arr, (mid + 1), high);
		if(left >= right) {
			return left;
		} else {
			return right;
		}
	}
}