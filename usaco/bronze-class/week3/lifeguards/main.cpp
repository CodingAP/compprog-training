// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://usaco.org/index.php?page=viewproblem2&cpid=736
// USACO 2018 January Bronze Contest, Problem 2: Lifeguards
//
// Author: Alex Prosser
// Date: 3/1/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <bits/stdc++.h>

using namespace std;

int main() {
    // take input
    int n;
    cin >> n;

    vector<pair<int, int>> shifts(n);
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        shifts[i] = {a, b};
    }

    // find the maximum amount of time covered if one shift is removed
    int maximum = -1;
    for (int i = 0; i < n; i++) {
        vector<bool> time(1001);
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            for (int k = shifts[j].first; k < shifts[j].second; k++) {
                time[k] = true;
            }
        }

        int count = 0;
        for (bool covered : time) count += covered;
        maximum = max(count, maximum);
    }

    cout << maximum << endl;

    return 0;
}