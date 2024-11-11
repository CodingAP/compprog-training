// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://usaco.org/index.php?page=viewproblem2&cpid=891
// USACO 2019 January Bronze Contest, Problem 1: Shell Game
//
// Author: Alex Prosser
// Date: 2/27/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <bits/stdc++.h>

using namespace std;

// swap structure to hold input
struct Swap {
    int a, b, g;
};

// simulate a game with the swaps using the starting pebble
int simulatePebble(int starting, vector<Swap> swaps) {
    int points = 0;
    vector<bool> shells(3);
    shells[starting] = true;
    for (Swap s : swaps) {
        bool temp = shells[s.a];
        shells[s.a] = shells[s.b];
        shells[s.b] = temp;

        if (shells[s.g]) points++;
    }
    return points;
}

int main() {
    // take input
    int n;
    cin >> n;

    vector<Swap> swaps(n);
    int a, b, g;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> g;
        swaps[i] = {a - 1, b - 1, g - 1};
    }

    // find most points on which starting shell
    cout << max({
        simulatePebble(0, swaps),
        simulatePebble(1, swaps),
        simulatePebble(2, swaps)
    }) << endl;

    return 0;
}