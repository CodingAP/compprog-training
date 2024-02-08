// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://icpcarchive.github.io/North%20America%20Contests/Mid-Atlantic%20USA%20Regional%20Contest/2021%20ICPC%20Mid-Atlantic%20USA%20Regional%20Contest/problems.pdf
// ICPC Mid-Atlantic 2021 Regionals, Problem A
//
// Author: Alex Prosser
// Date: 2/2/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
#include <string>

using namespace std;

int main() {
    // take in input
    int count, storage;
    cin >> count >> storage;

    int current = 0, refills = 0;
    string input;
    getline(cin, input); // input bug
    for (int i = 0; i < count; i++) {
        getline(cin, input);
        
        // get how many oz of water needed to make coffee
        // trick to convert char to digit 
        int order = (input.front() - '0') + (input.back() == 'L');

        if (current + order > storage) {
            refills++;
            current = 0;
        }

        current += order;
    }

    // output amount refills
    cout << refills << endl;

    return 0;
}