// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://icpcarchive.github.io/North%20America%20Contests/Rocky%20Mountain%20Regional%20Contest/2016%20Rocky%20Mountain%20Regional%20Contest/problems.pdf
// Rocky Mountain Regional Programming Contest 2016, Problem A
//
// Author: Alex Prosser
// Date: 2/19/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>

using namespace std;

int main() {
    // take input
    int divisor1, divisor2, n;
    cin >> divisor1 >> divisor2 >> n;

    // do fizzbuzz
    for (int i = 1; i <= n; i++) {
        string output = "";
        if (i % divisor1 == 0) output += "Fizz";
        if (i % divisor2 == 0) output += "Buzz";

        if (output.empty()) cout << i << endl;
        else cout << output << endl;
    }
    
    return 0;
}