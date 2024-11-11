// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://icpcarchive.github.io/North%20America%20Contests/North%20Central%20Regional%20Contest/2019%20North%20Central%20Regional%20Contest/problems.pdf
// ICPC North Central 2019 Regionals, Problem D
//
// USAGE: ./program.exe [input_file]
//     - input_file <optional>: if present, runs program off file rather than cmdline
//
// Author: Alex Prosser
// Date: 10/21/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    // **** REMOVE BEFORE SUBMISSION ****
    if (argc == 1) {
        // no cmdline input, run from input
    } else if (argc == 2) {
        freopen(argv[1], "r", stdin);
        freopen("output.txt", "w", stdout);
    }

    int n;
    cin >> n;

    // determine if the sum range is even, odd, or either
    // if follows a pattern of [either, odd, either, even]
    if (n % 2 == 1) {
        cout << "Either" << endl;
    } else {
        if ((n / 2) % 2 == 0) {
            cout << "Even" << endl;
        } else {
            cout << "Odd" << endl;
        }
    }

    return 0;
}