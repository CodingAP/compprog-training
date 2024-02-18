// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://icpcarchive.github.io/Europe%20Subcontests/UK%20and%20Ireland%20Programming%20Contest%20(UKIPC)/2019%20UK%20and%20Ireland%20Programming%20Contest/problems.pdf
// United Kingdom and Ireland Programming Contest 2019, Problem I
//
// Editorial "Cheeky" Version
//
// Author: Alex Prosser
// Date: 2/17/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int depth, sum;
    cin >> depth >> sum;

    // impossible case: if the smallest possible triangle can't be created, then it is impossible
    if (sum < pow(2, depth - 1)) {
        cout << "impossible" << endl;
        return 0;
    }

    // print each line with the sum with the needed amount of 2^n
    // then subtract the number next to it to get the next one 
    for (int i = 0; i < depth; i++) {
        if (i != 0) sum -= pow(2, depth - i - 1);
        cout << sum << (i != 0 ? " " : "");
        for (int j = 0; j < i; j++) {
            cout << pow(2, depth - i - 1) << (j != i - 1 ? " " : "");
        }
        cout << endl;
    }
    return 0;
}