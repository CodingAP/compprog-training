// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://usaco.org/index.php?page=viewproblem2&cpid=1061
// USACO 2020 December Bronze Contest, Problem 3: Stuck in a Rut
//
// Author: Alex Prosser
// Date: 2/28/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <bits/stdc++.h>

using namespace std;

// cow structure to hold input
struct Cow {
    char direction;
    int x, y, steps;
    bool stopped;
};

int main() {
    // take input
    int count;
    cin >> count;

    vector<Cow> cows(count);
    char direction;
    int x, y;
    for (int i = 0; i < count; i++) {
        cin >> direction >> x >> y;
        cows[i] = {direction, x, y, 0, false};
    }

    // simulate 1000000 turns to see which cow stopped or not
    set<pair<int, int>> eaten, newlyEaten;
    for (int i = 0; i < 100000; i++) {
        for (Cow &cow : cows) {
            if (cow.stopped) continue;

            // simulate cow step
            if (cow.direction == 'N') cow.y++;
            if (cow.direction == 'E') cow.x++;
            cow.steps++;

            // cow has found an eaten square
            if (eaten.find({cow.x, cow.y}) != eaten.end()) cow.stopped = true;
            else newlyEaten.insert({cow.x, cow.y});
        }

        eaten.insert(newlyEaten.begin(), newlyEaten.end());
        newlyEaten.clear();
    }

    // print cows locations
    for (Cow cow : cows) {
        if (cow.stopped) cout << cow.steps << endl;
        else cout << "Infinity" << endl;
    }

    return 0;
}