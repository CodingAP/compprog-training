// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://icpcarchive.github.io/North%20America%20Contests/Rocky%20Mountain%20Regional%20Contest/2016%20Rocky%20Mountain%20Regional%20Contest/problems.pdf
// Rocky Mountain Regional Programming Contest 2016, Problem C
//
// Author: Alex Prosser
// Date: 2/19/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // take inputs
    int count;
    cin >> count;

    vector<double> probabilities(count);

    // we don't need to store the password, just the probability
    for (int i = 0; i < count; i++) {
        string password;
        double p;

        cin >> password >> p;

        probabilities[i] = p;
    }

    // sort greatest to least
    sort(probabilities.begin(), probabilities.end(), [](double a, double b) { return a > b; });

    // count how many tries it takes
    double tries = 0;
    for (int i = 0; i < count; i++) tries += (i + 1) * probabilities[i];

    cout << tries << endl; 
    return 0;
}