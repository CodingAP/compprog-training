// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://usaco.org/index.php?page=viewproblem2&cpid=665
// USACO 2016 December Bronze Contest, Problem 3: The Cow-Signal
//
// Author: Alex Prosser
// Date: 2/27/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <bits/stdc++.h>

using namespace std;

int main() {
    // take input
    int r, c, scale;
    cin >> r >> c >> scale;

    // take grid input
    vector<vector<char>> grid(r);
    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            char input;
            cin >> input;
            grid[y].push_back(input);
        }
    }

    // print grid repeated by scale
    for (int y = 0; y < r * scale; y++) {
        for (int x = 0; x < c * scale; x++) {
            cout << grid[y / scale][x / scale];
        }
        cout << endl;
    }

    return 0;
}