// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://icpcarchive.github.io/Europe%20Subcontests/UK%20and%20Ireland%20Programming%20Contest%20(UKIPC)/2019%20UK%20and%20Ireland%20Programming%20Contest/problems.pdf
// United Kingdom and Ireland Programming Contest 2019, Problem B
//
// Author: Alex Prosser
// Date: 2/17/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // take in bigger number
    long long number;
    cin >> number;
    
    // find how many zeros needed to fill number
    int i = 0;
    while (number > pow(10, i)) i++;

    // print out rounded number
    cout << fixed << (long long) (round(number / pow(10, i - 1)) * pow(10, i - 1)) << endl;

    return 0;
}