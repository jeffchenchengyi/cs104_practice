#include <iostream>
#include <stdlib.h>

using namespace std;

void move(int, int);
void hanoi(int, int, int);

int main(int argc, char* argv[])
{
    //To check if number of discs was also included as a command line parameter
    if (argc < 2) {
	   cerr << "Please provide the number of discs for tower_of_hanoi." << endl;
	   return -1;
    }

    int num_discs = atoi(argv[1]);
    cout << "Moving " << num_discs << " discs from Tower 1 to Tower 3. " << endl;
    cout << "Steps: " << endl;

    hanoi(1, 3, num_discs);

    return 0;
}

void move(int start, int end) {
    cout << "Move top disc from " << start << " to " << end << endl;
}

void hanoi(int start, int end, int num_discs) {
    if(num_discs == 0) {
        return;
    } else if(num_discs == 1) {
        move(start, end);
    } else {
        int auxillary = 6 - start - end;
        hanoi(start, auxillary, num_discs - 1);
        move(start, end);
        hanoi(auxillary, end, num_discs - 1);
    }
}