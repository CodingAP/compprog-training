// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://icpcarchive.github.io/North%20America%20Contests/North%20Central%20Regional%20Contest/2019%20North%20Central%20Regional%20Contest/problems.pdf
// ICPC North Central 2019 Regionals, Problem J
//
// USAGE: ./program.exe [input_file]
//     - input_file <optional>: if present, runs program off file rather than cmdline
//
// Author: Alex Prosser
// Date: 10/21/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    // **** REMOVE BEFORE SUBMISSION ****
    if (argc == 1) {
        // no cmdline input, run from input
    } else if (argc == 2) {
        freopen(argv[1], "r", stdin);
        freopen("output.txt", "w", stdout);
    }

    // input grid
    int n;
    cin >> n;
    vector<vector<char>> grid(n);

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            char input;
            cin >> input;
            grid[y].push_back(input);
        }
    }

    bool valid = true;

    // check rows
    for (int y = 0; y < n; y++) {
        int black = 0, white = 0;

        char current = 'X';
        int streak = 0;

        for (int x = 0; x < n; x++) {
            if (grid[y][x] == 'B') black++;
            else white++;

            // update streaks
            if (current == 'X' || current != grid[y][x]) {
                current = grid[y][x];
                streak = 1;
            } else {
                streak++;
            }

            // check to see if streak is 3 or larger
            if (streak >= 3) valid = false;
        }

        // check to see if black and white counts match
        if (black != white) valid = false;
    }

    // check columns
    for (int x = 0; x < n; x++) {
        int black = 0, white = 0;

        char current = 'X';
        int streak = 0;

        for (int y = 0; y < n; y++) {
            if (grid[y][x] == 'B') black++;
            else white++;

            // update streaks
            if (current == 'X' || current != grid[y][x]) {
                current = grid[y][x];
                streak = 1;
            } else {
                streak++;
            }

            // check to see if streak is 3 or larger
            if (streak >= 3) valid = false;
        }

        // check to see if black and white counts match
        if (black != white) valid = false;
    }

    cout << valid << endl;

    return 0;
}