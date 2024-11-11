// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://usaco.org/index.php?page=viewproblem2&cpid=526
// USACO 2015 Feburary Bronze Contest, Problem 1: Censoring
//
// Author: Alex Prosser
// Date: 2/28/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <bits/stdc++.h>

using namespace std;

// see if a string ends with another string
// have to use this because usaco doesn't use c++20
bool hasEnding(string s, string end) {
    if (s.length() >= end.length()) return (0 == s.compare(s.length() - end.length(), end.length(), end));
    return false;
}

int main() {
    // take input
    string t, s;
    cin >> t >> s;

    // remove all instances of the censored string
    string current = "";
    for (int i = 0; i < t.length(); i++) {
        current += t[i];
        if (hasEnding(current, s)) current = current.substr(0, current.length() - s.length());
    }

    // print final string
    cout << current << endl;
    return 0;
}