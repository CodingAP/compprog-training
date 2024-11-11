// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://icpcarchive.github.io/North%20America%20Contests/Mid-Atlantic%20USA%20Regional%20Contest/2021%20ICPC%20Mid-Atlantic%20USA%20Regional%20Contest/problems.pdf
// ICPC Mid-Atlantic 2021 Regionals, Problem J
//
// USAGE: ./program.exe [input_file]
//     - input_file <optional>: if present, runs program off file rather than cmdline
//
// Author: Alex Prosser
// Date: 2/4/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(int argc, char *argv[]) {
    // **** REMOVE BEFORE SUBMISSION ****
    if (argc == 1) {
        // no cmdline input, run from input
    } else if (argc == 2) {
        // reads from input file and outputs to output file
        freopen(argv[1], "r", stdin);
        freopen("output.txt", "w", stdout);
    }

    // take input
    int alice1, alice2;
    cin >> alice1 >> alice2;

    string lineup;
    getline(cin, lineup); // input weirdness
    getline(cin, lineup);

    // try all possible combinations to see if the order works
    queue<int> alice, bob;
    vector<pair<int, int>> possible;
    for (int i = 1; i <= 9; i++) {
        if (i == alice1 || i == alice2) continue;
        for (int j = i + 1; j <= 9; j++) {
            if (j == alice1 || j == alice2 || i == j) continue;

            // reset queues
            alice = {};
            alice.push(alice1);
            alice.push(alice2);

            bob = {};
            bob.push(i);
            bob.push(j);

            // starts by selecting the first number
            bool increasing = true;
            int start;
            if (lineup[0] == 'A') {
                start = alice.front();
                alice.pop();
            } else {
                start = bob.front();
                bob.pop();
            }

            // checks to see if every number after is increasing
            for (int k = 1; k < 4; k++) {
                int next;
                if (lineup[k] == 'A') {
                    next = alice.front();
                    alice.pop();
                } else {
                    next = bob.front();
                    bob.pop();
                }

                if (next < start) increasing = false;
                start = next;
            }

            // if it is, it is a possible solutions
            if (increasing) possible.push_back(make_pair(i, j));
        }
    }

    // if only one possible solution exists, print them out
    // else print -1
    if (possible.size() == 1) {
        cout << possible[0].first << " " << possible[0].second << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}