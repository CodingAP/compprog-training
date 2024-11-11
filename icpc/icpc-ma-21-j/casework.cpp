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

    // try every testcase and see if it works
    // see allpossible.txt
    if (lineup == "AABB" && alice2 == 7) {
        cout << "8 9" << endl;
    } else if (lineup == "ABAB" && alice1 == 6 && alice2 == 8) {
        cout << "7 9" << endl;
    } else if (lineup == "ABBA" && (alice2 - 3 == alice1)) {
        cout << alice1 + 1 << " " << alice2 - 1 << endl;
    } else if (lineup == "BAAB" && alice1 == 2 && alice2 == 8) {
        cout << "1 9" << endl;
    } else if (lineup == "BABA" && alice1 == 2 && alice2 == 4) {
        cout << "1 3" << endl;
    } else if (lineup == "BBAA" && alice1 == 3) {
        cout << "1 2" << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}