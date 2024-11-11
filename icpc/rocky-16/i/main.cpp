// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://icpcarchive.github.io/North%20America%20Contests/Rocky%20Mountain%20Regional%20Contest/2016%20Rocky%20Mountain%20Regional%20Contest/problems.pdf
// Rocky Mountain Regional Programming Contest 2016, Problem I
//
// Author: Alex Prosser
// Date: 2/19/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
#include <regex>
#include <algorithm>

using namespace std;

int main() {
    int count;
    cin >> count;

    // regular expression for all digits
    regex digit("^[0-9]*$");

    // hold all cups
    vector<pair<double, string>> cups(count);

    for (int i = 0; i < count; i++) {
        string part1, part2;
        cin >> part1 >> part2;

        // check which part is the digits
        cups[i] = (regex_match(part1, digit)) ? make_pair(stoi(part1) / 2, part2) : make_pair(stoi(part2), part1);
    }

    // sort cups by radius
    sort(cups.begin(), cups.end(), [](pair<double, string> a, pair<double, string> b) {
        return a.first < b.first;
    });

    for (auto pair : cups) cout << pair.second << endl;

    return 0;
}