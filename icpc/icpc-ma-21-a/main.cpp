// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://icpcarchive.github.io/North%20America%20Contests/Mid-Atlantic%20USA%20Regional%20Contest/2021%20ICPC%20Mid-Atlantic%20USA%20Regional%20Contest/problems.pdf
// ICPC Mid-Atlantic 2021 Regionals, Problem A
//
// USAGE: ./program.exe [input_file]
//     - input_file <optional>: if present, runs program off file rather than cmdline
//
// Author: Alex Prosser
// Date: 2/2/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
#include <string>

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

    cout << refills << endl;

    return 0;
}