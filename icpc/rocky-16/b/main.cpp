// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://icpcarchive.github.io/North%20America%20Contests/Rocky%20Mountain%20Regional%20Contest/2016%20Rocky%20Mountain%20Regional%20Contest/problems.pdf
// Rocky Mountain Regional Programming Contest 2016, Problem B
//
// INCOMPLETE
//
// Author: Alex Prosser
// Date: 2/19/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>

using namespace std;

int main() {
    int count;
    cin >> count;

    for (int i = 0; i < count; i++) {
        int totalVotes, myVotes, theirVotes, percentage;
        cin >> totalVotes >> myVotes >> theirVotes >> percentage;

        if ((myVotes * 100.0) / totalVotes > percentage) {
            cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!" << endl;
        } else if (1 - (theirVotes * 100.0) / totalVotes) {}
    }
    return 0;
}