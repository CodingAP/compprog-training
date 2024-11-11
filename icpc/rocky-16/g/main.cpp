// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://icpcarchive.github.io/North%20America%20Contests/Rocky%20Mountain%20Regional%20Contest/2016%20Rocky%20Mountain%20Regional%20Contest/problems.pdf
// Rocky Mountain Regional Programming Contest 2016, Problem A
//
// Author: Alex Prosser
// Date: 2/19/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
#include <vector>

using namespace std;

int main() {
    // take input
    int swathers, stages;
    cin >> swathers >> stages;

    // 2d array of times
    vector<vector<int>> times(swathers);
    for (int i = 0; i < swathers; i++) {
        for (int j = 0; j < stages; j++) {
            int time;
            cin >> time;
            times[i].push_back(time);
        }
    }

    vector<int> queue(stages, -1), final(swathers, 0);
    queue[0] = times[0][0];
    while (true) {
        for (int i = 0; i < stages; i++) {
            // worker has work to do
            if (queue[i] != -1) {
                
            }
        }
    }

    return 0;
}