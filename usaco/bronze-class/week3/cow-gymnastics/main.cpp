// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://usaco.org/index.php?page=viewproblem2&cpid=963
// USACO 2019 December Bronze Contest, Problem 1: Cow Gymnastics
//
// Author: Alex Prosser
// Date: 3/1/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <bits/stdc++.h>

using namespace std;

int main() {
    // take input
    int k, n;
    cin >> k >> n;

    vector<vector<int>> standings(k);
    int cow;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cow;
            standings[i].push_back(cow);
        }
    }

    // generate all possible pairs
    vector<pair<int, int>> possible;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            possible.push_back({i, j});
        }
    }

    // check each pair to see which pairs work
    // for the problem, the first of the pair will be checked
    int count = 0;
    for (auto pair : possible) {
        bool works = true;
        int direction = 0;
        for (int i = 0; i < k; i++) {
            int firstIndex = -1, secondIndex = -1;
            for (int j = 0; j < n; j++) {
                if (standings[i][j] == pair.first) firstIndex = j;
                if (standings[i][j] == pair.second) secondIndex = j;
            }

            // we check the direction of the pair's placement
            // if inconsistent, we marked the pair as "doesn't work"
            int sign = ((secondIndex - firstIndex) > 0) ? 1 : (((secondIndex - firstIndex) < 0) ? -1 : 0);
            if (direction == 0) direction = sign;
            else if (direction != sign) works = false;
        }
        
        if (works) count++;
    }

    cout << count << endl;
    return 0;
}