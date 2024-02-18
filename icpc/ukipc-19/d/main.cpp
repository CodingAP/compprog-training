// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://icpcarchive.github.io/Europe%20Subcontests/UK%20and%20Ireland%20Programming%20Contest%20(UKIPC)/2019%20UK%20and%20Ireland%20Programming%20Contest/problems.pdf
// United Kingdom and Ireland Programming Contest 2019, Problem D
//
// Author: Alex Prosser
// Date: 2/17/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // take input
    int pointCount, index;
    cin >> pointCount >> index;

    // we don't have to store the points, just the magnitude (with no sqrt :D)
    vector<double> distances(pointCount);
    for (int i = 0; i < pointCount; i++) {
        double x, y, z;
        cin >> x >> y >> z;
        distances[i] = x * x + y * y + z * z;
    }

    // sort and select the kth point (we sqrt here)
    sort(distances.begin(), distances.end());
    cout << sqrt(distances[index - 1]) << endl;

    return 0;
}