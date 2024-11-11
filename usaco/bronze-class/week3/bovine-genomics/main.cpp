// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://usaco.org/index.php?page=viewproblem2&cpid=736
// USACO 2017 US Open Bronze Contest, Problem 2: Bovine Genomics
//
// Author: Alex Prosser
// Date: 3/1/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <bits/stdc++.h>

using namespace std;

int main() {
    // take input
    int n, m;
    cin >> n >> m;

    vector<string> spotty, plain;
    string genome;
    for (int i = 0; i < n * 2; i++) {
        cin >> genome;
        if (i >= n) plain.push_back(genome);
        else spotty.push_back(genome);
    }

    // check each column to see if the genomes contain the same characters
    // we can use sets to see what characters are in each type of cow
    // if the sets contain no same characters, then it is a possible column 
    int possible = 0;
    for (int i = 0; i < m; i++) {
        set<char> spottyChars, plainChars, combined; 
        for (int j = 0; j < n; j++) {
            spottyChars.insert(spotty[j][i]);
            plainChars.insert(plain[j][i]);
        }

        combined.insert(spottyChars.begin(), spottyChars.end());
        combined.insert(plainChars.begin(), plainChars.end());

        if (combined.size() == plainChars.size() + spottyChars.size()) possible++;
    }

    cout << possible << endl;
    return 0;
}