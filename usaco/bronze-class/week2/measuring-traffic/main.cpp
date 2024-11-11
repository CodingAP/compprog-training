// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://usaco.org/index.php?page=viewproblem2&cpid=917
// USACO 2019 February Bronze Contest, Problem 3: Measuring Traffic
//
// I couldn't figure out a solution on my own :(
//
// Author: Alex Prosser
// Date: 2/29/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <bits/stdc++.h>

using namespace std;

struct Highway {
    string type;
    int min, max;
};

int main() {
    // take input
    int count;
    cin >> count;

    vector<Highway> segments(count);
    string type;
    int a, b;
    for (int i = 0; i < count; i++) {
        cin >> type >> a >> b;
        segments[i] = {type, a, b};
    }

    // find before range
    int beforeMin = -1001, beforeMax = 1001;
    for (int i = segments.size() - 1; i >= 0; i--) {
        if (segments[i].type == "none") {
            beforeMin = max(beforeMin, segments[i].min);
            beforeMax = min(beforeMax, segments[i].max);
        } else if (segments[i].type == "on") {
            beforeMin = max(0, beforeMin - segments[i].max);
            beforeMax -= segments[i].min;
        } else if (segments[i].type == "off") {
            beforeMin += segments[i].min;
            beforeMax += segments[i].max;
        }
    }

    cout << beforeMin << " " << beforeMax << endl;

    // find after range
    int afterMin = -1001, afterMax = 1001;
    for (int i = 0; i < segments.size(); i++) {
        if (segments[i].type == "none") {
            afterMin = max(afterMin, segments[i].min);
            afterMax = min(afterMax, segments[i].max);
        } else if (segments[i].type == "off") {
            afterMin = max(0, afterMin - segments[i].max);
            afterMax -= segments[i].min;
        } else if (segments[i].type == "on") {
            afterMin += segments[i].min;
            afterMax += segments[i].max;
        }
    }

    cout << afterMin << " " << afterMax << endl;

    return 0;
}