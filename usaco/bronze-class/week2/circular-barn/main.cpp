// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://usaco.org/index.php?page=viewproblem2&cpid=616
// USACO 2016 Feburary Bronze Contest, Problem 2: Circular Barn
//
// Author: Alex Prosser
// Date: 2/28/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <bits/stdc++.h>

using namespace std;

int main() {
    // take input
    int count;
    cin >> count;

    vector<int> rooms(count);
    for (int i = 0; i < count; i++) {
        cin >> rooms[i];
    }

    // try all doors to find the smallest distance
    int min = -1;
    for (int i = 0; i < count; i++) {
        int steps = 0;
        for (int j = 0; j < count; j++) {
            steps += j * rooms[(i + j) % count];
        }

        if (min == -1 || steps < min) min = steps;
    }

    // print out min
    cout << min << endl;
    return 0;
}