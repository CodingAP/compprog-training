// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://usaco.org/index.php?page=viewproblem2&cpid=759
// USACO 2017 December Bronze Contest, Problem 1: Blocked Billboard
//
// Author: Alex Prosser
// Date: 2/26/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <bits/stdc++.h>

using namespace std;

// gets the area of the intersecting parts of the rectangle
// if not colliding, returns 0
int getIntersectingArea(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    int intersectW = min(x2, x4) - max(x1, x3);
    int intersectH = min(y2, y4) - max(y1, y3);
    return (intersectW > 0 && intersectH > 0) ? intersectW * intersectH : 0;
}

int main() {
    // take line 1 input
    int billboardAX1, billboardAY1, billboardAX2, billboardAY2;
    cin >> billboardAX1 >> billboardAY1 >> billboardAX2 >> billboardAY2;

    // get area of billboard a
    int billboardAArea = (billboardAX2 - billboardAX1) * (billboardAY2 - billboardAY1);

    // take line 2 input
    int billboardBX1, billboardBY1, billboardBX2, billboardBY2;
    cin >> billboardBX1 >> billboardBY1 >> billboardBX2 >> billboardBY2;

    // get area of billboard b
    int billboardBArea = (billboardBX2 - billboardBX1) * (billboardBY2 - billboardBY1);

    // take line 3 input
    int truckX1, truckY1, truckX2, truckY2;
    cin >> truckX1 >> truckY1 >> truckX2 >> truckY2;

    // find overlapping area of billboards and truck
    int truckAIntersect = getIntersectingArea(billboardAX1, billboardAY1, billboardAX2, billboardAY2, truckX1, truckY1, truckX2, truckY2);
    int truckBIntersect = getIntersectingArea(billboardBX1, billboardBY1, billboardBX2, billboardBY2, truckX1, truckY1, truckX2, truckY2);

    // find nonoverlapping area
    cout << (billboardAArea - truckAIntersect) + (billboardBArea - truckBIntersect) << endl;

    return 0;
}