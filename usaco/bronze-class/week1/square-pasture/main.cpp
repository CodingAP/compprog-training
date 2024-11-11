// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://usaco.org/index.php?page=viewproblem2&cpid=663
// USACO 2016 December Bronze Contest, Problem 1: Square Pasture
//
// Author: Alex Prosser
// Date: 2/26/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <bits/stdc++.h>

using namespace std;

int main() {
    // take input
    int x01, x02, y01, y02;
    cin >> x01 >> y01 >> x02 >> y02;

    int x11, x12, y11, y12;
    cin >> x11 >> y11 >> x12 >> y12;

    // find bounding box of both rectangles
    int minX = min(x01, x11);
    int maxX = max(x02, x12);

    int minY = min(y01, y11);
    int maxY = max(y02, y12);

    // get biggest side
    int side = max(maxX - minX, maxY - minY);

    cout << side * side << endl;

    return 0;
}