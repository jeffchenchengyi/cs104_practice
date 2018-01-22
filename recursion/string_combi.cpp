#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

//Given a string AB, 2, where AB is the string
//and 2 is the length of the output string,
//print all combinations that have length 2.

void printAll(string, int);
void printHelper(string, string, int);

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

void printAll(string s, int k) {
	printHelper(s, "", k);
}

void printHelper(string s, string t, int k) {
	//Base Case: 
	//E.g. when t is already AB and k == 0
	if(k == 0) {
		cout << t << endl;
	}
	//Recursive Case:
	//Passes in s == AB, k == "", k == 2
	else {
		for(int i = 0; i < int(s.length()); i++) {
			//For every character in s, it is appended to t and
			//printHelper will choose one character
			//from s and it will be appended to t
			printHelper(s, (t + s[i]), (k - 1));
		}
	}
}