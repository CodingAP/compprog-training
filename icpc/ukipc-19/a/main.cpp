// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://icpcarchive.github.io/Europe%20Subcontests/UK%20and%20Ireland%20Programming%20Contest%20(UKIPC)/2019%20UK%20and%20Ireland%20Programming%20Contest/problems.pdf
// United Kingdom and Ireland Programming Contest 2019, Problem A
//
// INCOMPLETE
//
// Author: Alex Prosser
// Date: 2/17/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
#include <vector>

using namespace std;

struct slot {
    int thickness;
    int mass;
    int distance;
};

struct coin {
    int thickness;
    int mass;
};

bool slotCompare(slot a, slot b) {
    return false;
}

int main() {
    int slotCount, coinCount;
    vector<slot> slots;
    vector<coin> coins;

    cin >> slotCount;

    for (int i = 0; i < slotCount; i++) {
        int thickness, mass;
        cin >> thickness >> mass;
        slots.push_back({thickness, mass, i + 1});
    }

    cin >> coinCount;

    for (int i = 0; i < coinCount; i++) {
        int thickness, mass;
        cin >> thickness >> mass;
        coins.push_back({thickness, mass});
    }

    return 0;
}