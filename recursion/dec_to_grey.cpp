#include <iostream>
#include <cmath>
using namespace std;

int grey(int x, int numBits, int count) {
    if(x == 0 && count == 0) {
        while(count != numBits) {
            cout << "0";
            count++;
        }
        return 0;
    } else if(x == 0 && count == numBits) {
        return 0;
    }
    else {
        int prevBit = grey(x/2, numBits, count + 1);
        if((count + 1) == numBits) {
            cout << x%2;
        } else {
            cout << (prevBit ^ x%2);
        }
        return x%2;
    }
}

void firstNBin(int numBits, int i) {
    if (i == pow(2,numBits)) {
        return;
    }
    grey(i, numBits, 0);
    cout << endl;
    firstNBin(numBits, i + 1);
}

int main()
{
    int numBits = 3;
    firstNBin(numBits, 0);
    return 0;
}