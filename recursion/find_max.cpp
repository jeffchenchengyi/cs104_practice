#include <iostream>
#include <stdlib.h>

using namespace std;

int max(int arr[], int, int);

int main (int argc, char* argv[])
{
  if(argc < 3){
    cerr << "Please provide a string and the output length." << endl;
    return 1;
  }

  string input_string = argv[1];
  int output_len = atoi(argv[2]);

  printAll(input_string, output_len);

  return 0;
}

int max(int arr[], int lo, int high) {
}