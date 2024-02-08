// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://icpcarchive.github.io/North%20America%20Contests/Mid-Atlantic%20USA%20Regional%20Contest/2021%20ICPC%20Mid-Atlantic%20USA%20Regional%20Contest/problems.pdf
// ICPC Mid-Atlantic 2021 Regionals, Problem B
//
// Author: Alex Prosser
// Date: 2/8/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {
    // take in input
    int time;
    cin >> time;

    // output each row backwards (most significant bit first)
    for (int y = 3; y >= 0; y--) {
        for (int col = 0; col < 4; col++) {
            // get the digit left to right
            int digit = (time / ((int) pow(10, 3 - col))) % 10;

            // print out the yth bit of the digit 
            cout << (((digit >> y) & 1) ? '*' : '.');

            // even columns have 1 space, odd colums have 3 spaces, last has no spaces
            if (col % 2 == 0) cout << ' ';
            else if (col != 3) cout << "   ";
        }
        cout << endl;
    }

    return 0;
}